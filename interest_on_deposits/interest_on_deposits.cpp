#include <iostream>
using namespace std;

class Student
{
    int rollno;
    string name;
    int age;
    float maths, science, english;

    public:
    Student(){}
    Student(int stu_rollno, string stu_name, int stu_age);
    void modify_data(int, Student students[]);
    void display_data();
};

Student::Student(int stu_rollno, string stu_name, int stu_age)
{
    rollno = stu_rollno;
    name = stu_name;
    age = stu_age;
    maths = 40;
    science = 40;
    english = 40;
}
    
void Student::modify_data(int modify_rollno, Student students[])
{
    int i, flag = 0;
    int math, sci, eng;

    cout<<"New Marks Of Maths\n";
    cin>>math;
    cout<<"New Marks Of Science\n";
    cin>>sci;
    cout<<"New Marks Of English\n";
    cin>>eng;

    for ( i = 0; i < 5; i++)
    {
        if (students[i].rollno == modify_rollno)
        {
            students[i].maths = math;
            students[i].science = sci;
            students[i].english = eng;
            flag = 1;
        }

        if (flag == 1)
        {
            break;
        }
    }  
}

void Student::display_data()
{
    cout<<"Details Of Roll No. "<<rollno<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Age : "<<age<<endl;
    cout<<"Maths : "<<maths<<endl;
    cout<<"Science : "<<science<<endl;
    cout<<"English : "<<english<<endl;
}

int main()
{
    int modify_rollno, i;
    Student students[5];
   
    students[0] = Student(101, "Chirag", 21);
    students[1] = Student(102, "Momo", 21);
    students[2] = Student(103, "Jigar", 15);
    students[3] = Student(104, "Mom", 44);
    students[4] = Student(105, "Dad", 51);

    for ( i = 0; i < 5; i++)
    {
        students[i].display_data();
    }
    

    cout<<"Enter the Roll Number Of student you want to modify marks: ";
    cin>>modify_rollno;

    students[0].modify_data(modify_rollno, students);
    
    for ( i = 0; i < 5; i++)
    {
        students[i].display_data();
    }
    

}