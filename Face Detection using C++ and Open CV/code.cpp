#include "/usr/local/include/opencv2/objdetect.hpp"
#include "/usr/local/include/opencv2/highgui.hpp"
#include "/usr/local/include/opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void detectAndMark(Mat& frame, CascadeClassifier& faceDetector, CascadeClassifier& eyeDetector, double scalingFactor);
string faceCascadeFilePath, eyeCascadeFilePath;

int main(int argc, const char** argv) {
    VideoCapture videoCaptureDevice; 
    Mat currentFrame, processedFrame;

    CascadeClassifier faceCascade, eyeCascade; 
    double scale = 1.0;

    eyeCascade.load("../../haarcascade_eye_tree_eyeglasses.xml");
    faceCascade.load("../../haarcascade_frontalcatface.xml");

    videoCaptureDevice.open(0); 
    if(videoCaptureDevice.isOpened()) {
        cout << "Face Detection Started...." << endl;
        while(true) {
            videoCaptureDevice >> currentFrame;
            if(currentFrame.empty())
                break;
            Mat frameClone = currentFrame.clone();
            detectAndMark(frameClone, faceCascade, eyeCascade, scale); 
            char keyPress = (char)waitKey(10);
            if(keyPress == 27 || keyPress == 'q' || keyPress == 'Q') 
                break;
        }
    } else {
        cout << "Could not Open Camera";
    }
    return 0;
}

void detectAndMark(Mat& img, CascadeClassifier& faceDetector, CascadeClassifier& eyeDetector, double scalingFactor) {
    vector<Rect> faces, eyes;
    Mat grayImage, smallImg;

    cvtColor(img, grayImage, COLOR_BGR2GRAY);
    double fx = 1 / scalingFactor;

    resize(grayImage, smallImg, Size(), fx, fx, INTER_LINEAR); 
    equalizeHist(smallImg, smallImg);

    faceDetector.detectMultiScale(smallImg, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30));

    for(size_t i = 0; i < faces.size(); i++) {
        Rect face = faces[i];
        Mat faceRegion;
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = Scalar(255, 0, 0);
        int radius;

        double aspectRatio = (double)face.width / face.height;
        if(0.75 < aspectRatio && aspectRatio < 1.3) {
            center.x = cvRound((face.x + face.width * 0.5) * scalingFactor);
            center.y = cvRound((face.y + face.height * 0.5) * scalingFactor);
            radius = cvRound((face.width + face.height) * 0.25 * scalingFactor);
            circle(img, center, radius, color, 3, 8, 0);
        } else {
            rectangle(img, cvPoint(cvRound(face.x * scalingFactor), cvRound(face.y * scalingFactor)),
                cvPoint(cvRound((face.x + face.width - 1) * scalingFactor), cvRound((face.y + face.height - 1) * scalingFactor)), color, 3, 8, 0);
        }
        if(eyeDetector.empty())
            continue;
        faceRegion = smallImg(face);
        eyeDetector.detectMultiScale(faceRegion, nestedObjects, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30));
        
        for(size_t j = 0; j < nestedObjects.size(); j++) {
            Rect eye = nestedObjects[j];
            center.x = cvRound((face.x + eye.x + eye.width * 0.5) * scalingFactor);
            center.y = cvRound((face.y + eye.y + eye.height * 0.5) * scalingFactor);
            radius = cvRound((eye.width + eye.height) * 0.25 * scalingFactor);
            circle(img, center, radius, color, 3, 8, 0);
        }
    }

    imshow("Face Detection", img);
}
