#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string name;
    int grade;
    
};

// Function prototypes
void addStudent (vector<Student> &students); 
void displayStudents(const vector<Student>&students);
int calculateAverage(const vector<Student> &students);
int findHighestGrade(const vector<Student> &students);
int findLowestGrade(const vector<Student> &students);
void deleteStudent (vector<Student> &students, const string &name);
//void updateStudent (vector<Student> &students);
//void searchStudents (const vector<Student> &students);


int main (){
    vector<Student> students;
    int choice;
    
    do {
        cout << "STUDENT checking lab \n";
        cout << "1. ADD student: \n";
        cout << "2. Display students:\n";
        cout << "3. CAlculate average grade:\n";
        cout << "4. Display Highest grade \n";
        cout << "5. Display Lowest grade \n";
        cout << "6. Delete student\n";
        cout << "7. Update student \n";
        cout << "8. Search student \n";
        cout << "9. EXit: \n";
        cout << "enter your choice:";
        cin >> choice;

        string nameToDelete;
        Student newStudent;
        int total = 0;

        switch (choice){
            case 1:{
                Student newStudent;
                cout << "enter name:";
                cin >> newStudent.name;
                cout << "enter grade:";
                cin >> newStudent.grade;
               

                students.push_back(newStudent);
                break;
            }
case 2:
for ( const Student &s : students)
{
    cout << s.name << ":" << s.grade <<endl;

}
            
            break;


case 3:


for (const Student &s : students)
{
    total += s.grade;
}
cout << "Average Grade:" << total / students.size()<<endl;
break;

case 4:
cout << "Highest grade  " <<findHighestGrade(students)<<endl;
break;

case 5:
cout << "Lowest grade " <<findLowestGrade(students)<<endl;
break;

case 6:
cout << " Delete student by name :" ;
cin >> nameToDelete;
deleteStudent(students, nameToDelete);
break;

case 7:
//updateStudent(students);
break;

case 8:
//searchStudents(students);
break;


case 9:
cout << "goodbye!"<< endl;
break;
default:
cout << "invalid choice."<< endl;
break;
        }

    }
    while (choice !=9);



    return 0;

}

void addStudent (vector<Student> &students){
     Student newStudent;
                cout << "enter name:";
                cin >> newStudent.name;
                cout << "enter grade:";
                cin >> newStudent.grade;
               

                students.push_back(newStudent);
}
void displayStudents (const vector<Student> &students){
    for (const Student &s : students){
        cout << s.name << ":" <<s.grade << endl;
    }
}

int calculateAverage (const vector<Student> &students){
    int total = 0;
    for (const Student &s : students)
    {
        total += s.grade;
    }
    return students.empty() ? 0 : total / students.size();
}
int findHighestGrade (const vector<Student> &students){
    int highest = INT_MIN;
    for ( const Student &s : students){
        if (s.grade > highest){
            highest=s.grade;
        }
    }
    return highest;
}
int findLowestGrade(const vector<Student>&students)
{
    int lowest =INT_MAX;
    for(const Student &s :students){
        if(s.grade< lowest){
            lowest =s.grade;
        }
    }
    return lowest;
}

void deleteStudent(vector<Student> &students, const string &name)
{
    for(auto it = students.begin();it !=students.end();++it){
        if (it-> name ==name){
            students.erase(it);
            cout << "Student"<< name <<"' has been deleted"<< endl;
            return;
        }
    }
    cout << "Student"<< name << "' not found."<< endl;
}