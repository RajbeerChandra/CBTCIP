#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct scholar {
    string first_name;
    string last_name;
    int roll_number;
    double cgpa;
    int course_ids[10];
} scholars[110];

int total_scholars = 0;

void addScholarDetails()
{
    cout<<"Enter the new scholar details\n";
    
    cout<<"Enter the Roll Number of the scholar\n";
    int roll_no;
    cin>>roll_no;
    
    for(int i = 0; i < total_scholars; i++)
    {
       if(scholars[i].roll_number == roll_no)
       {
          cout << " Scholar with the given roll number already exists in the database\n";
          return;
       }
    }
    
    cout<<"Enter the first name of the scholar\n";
    cin>>scholars[total_scholars].first_name;
    
    cout<<"Enter the last name of the scholar\n";
    cin>>scholars[total_scholars].last_name;
    
    scholars[total_scholars].roll_number = roll_no;
    
    cout<<"Enter the CGPA of the scholar\n";
    cin>>scholars[total_scholars].cgpa;
    
    cout<<"Enter the course ID of each course in which the scholar is enrolled in\n";
    for (int i = 0; i < 5; i++) {
        cin>>scholars[total_scholars].course_ids[i];
    }
    
    total_scholars++;
}

void findScholarByRollNumber()
{
    int roll_no;
    cout<<"Enter the Roll Number of the scholar\n";
    cin>>roll_no;
    
    bool found = false;
    
    for (int i = 0; i < total_scholars; i++) {
        if (roll_no == scholars[i].roll_number) {
            found = true;
            
            cout<<"The Scholar's Details are:\n";
            
            cout<<"The First name is " << scholars[i].first_name << "\n";
            cout<<"The Last name is " << scholars[i].last_name << "\n";
            cout<<"The CGPA is " << scholars[i].cgpa << "\n";
            cout<<"The course ID of each course\n";
        
            for (int j = 0; j < 5; j++) {
                cout << scholars[i].course_ids[j] << " ";
            }
            
            break;
      }
    }
    
    if(!found)
       cout<<"No such scholar with the given roll number\n";
}

void findScholarByFirstName()
{
    string firstName;
    cout<<"Enter the first name of the scholar\n";
    cin>>firstName;
    
    bool found = false;
    
    for (int i = 0; i < total_scholars; i++) {
        if (firstName == scholars[i].first_name) {
            found = true;
            
            cout<<"The Scholar's Details are\n";
            
            cout<<"The First name is " << scholars[i].first_name << "\n";
            cout<<"The Last name is " << scholars[i].last_name << "\n";
            cout<<"The CGPA is " << scholars[i].cgpa << "\n";
            cout<<"The course ID of each course\n";
        
            for (int j = 0; j < 5; j++) {
                cout << scholars[i].course_ids[j] << " ";
            }
            
            cout<<"\n";
      }
    }
    
    if(!found)
       cout<<"No such scholar with the given first name\n";
}

void findScholarByCourseId()
{
    int id;
    cout<<"Enter the course id\n";
    cin>>id;
    
    bool found = false;
    
    for (int i = 0; i < total_scholars; i++) {
      
      for(int j = 0; j < 5; j++){
      
         if(id == scholars[i].course_ids[j]){
            
            found=true;
            cout<<"The Scholar's Details are\n";
            
            cout<<"The First name is " << scholars[i].first_name << "\n";
            cout<<"The Last name is " << scholars[i].last_name << "\n";
            cout<<"The CGPA is " << scholars[i].cgpa << "\n";
            cout<<"\n";
         }
      }      
        
    }
    
    if(!found)
       cout<<"No such scholars with the given course id\n";  
}
    
void findTotalScholars()
{
    cout<<"The total number of Scholars are "<< total_scholars <<"\n";
    cout<<"You can have maximum of 110 scholars in the database\n";
}

void deleteScholarByRollNumber()
{
    int roll_no;
    cout<<"Enter the Roll Number that you want to delete\n";
    cin>>roll_no;
    
    bool found=false;
    for (int i = 0; i < total_scholars; i++) {
        if (roll_no == scholars[i].roll_number) {
            found = true;
            for (int j = i; j < 109; j++)
                scholars[j] = scholars[j + 1];
            total_scholars--;
        }
    }
    
    if(found){
       cout<<"The Roll Number is removed Successfully\n";
    }
    else{
       cout<<"Roll number not found in the database\n";
    }
    
}

void updateScholarDetails()
{
 
    cout<<"Enter the roll number whose details you want to update\n";
    int roll_no;
    cin>>roll_no;
    
    bool found=false;
    for (int i = 0; i < total_scholars; i++) {
        if (scholars[i].roll_number == roll_no) {
        
            found=true;
            cout<< "1. Update first name\n"
                   "2. Update last name\n"
                   "3. Update roll number.\n"
                   "4. Update CGPA\n"
                   "5. Update courses\n";
                   
            int choice;
            cin>>choice;
            
            switch(choice) {
            case 1:
                cout<<"Enter the new first name\n";
                cin>>scholars[i].first_name;
                break;
                
            case 2:
                cout<<"Enter the new last name\n";
                cin>>scholars[i].last_name;
                break;
                
            case 3:
                cout<<"Enter the new roll number\n";
                cin>>scholars[i].roll_number;
                break;
                
            case 4:
                cout<<"Enter the new CGPA\n";
                cin>>scholars[i].cgpa;
                break;
                
            case 5:
                cout<<"Enter the new courses \n";
                cin>>scholars[i].course_ids[0]>>
                    scholars[i].course_ids[1]>> scholars[i].course_ids[2]>>
                    scholars[i].course_ids[3]>>scholars[i].course_ids[4];
                break;

        }
     }
   }  
   
   if(found){
     cout<<"Details updated successfully.\n";
   }
   else{
     cout<<"Scholar not found in the database.\n";
   }
}

int main()
{
    int choice;
    while (true) {
        cout<<"Choices of the tasks that you want to perform\n";
        
        cout<<"1. Add new Scholar to the database\n";
        
        cout<<"2. Search Scholar by Roll Number\n";
               
        cout<<"3. Search Scholar by First Name\n";
               
        cout<<"4. Search Scholar by Course Id\n";
               
        cout<<"5. Count Total number of Scholars\n";
               
        cout<<"6. Delete the Scholar by Roll Number\n";
               
        cout<<"7. Update Scholar Details by Roll Number\n";
               
        cout<<"8. Exit the program\n";
        
        cout<<"Enter your choice\n";
        cin>>choice;
        
        switch (choice) {
        case 1:
            addScholarDetails();
            break;
            
        case 2:
            findScholarByRollNumber();
            break;
            
        case 3:
            findScholarByFirstName();
            break;
            
        case 4:
            findScholarByCourseId();
            break;
            
        case 5:
            findTotalScholars();
            break;
            
        case 6:
            deleteScholarByRollNumber();
            break;
            
        case 7:
            updateScholarDetails();
            break;
            
        case 8:
            exit(0);
            break;
        }
    }
    
    return 0;
}
