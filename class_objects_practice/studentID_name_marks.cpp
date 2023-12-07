#include <iostream>

using namespace std;

class student
{
    int stu_id[10], marks[10];
    static int counter;
    string name[10];
    
    public:
    void set_student();
    void display_student();

};

int student:: counter;

void student::set_student()
{
    cout<<endl<< "Enter ID, Name and Marks for student "<<counter+1<<endl;
    cout<< "ID : ";
    cin>>stu_id[counter];
    cout<< "Name : ";
    cin>>name[counter];
    cout<< "Marks : ";
    cin>>marks[counter];
    counter++;
}
void student::display_student()
{
    for (int i = 0; i < counter; i++)
    {
        cout<<endl<<"Details for student "<<i+1<<" are"<<endl; 
        cout<<stu_id[i]<<" "<<name[i]<<" "<<marks[i];
    }
    

}

int main()
{
    student stud;
    int n;
    printf("Enter Number Of Students : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        stud.set_student();
    }

    stud.display_student();
    

}