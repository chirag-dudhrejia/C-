#include <iostream>
using namespace std;

class Empinfo
{
protected:
	int empid;
	string name;
	string gender;
public:
	void set_empinfo()
	{
		cout<<"Employee Id : ";
		cin>>empid;
		cout<<"Enter name of employee : ";
		getline(cin>>ws, name);
		cout<<"Gender type 'male' or 'female'. : ";
		getline(cin>>ws, gender);
	}
};

class Deptinfo
{
protected:
	int manager_id;
	string dept_name;
	string project_name;
public:
	void set_deptinfo()
	{
		cout<<"Department name? : ";
		getline(cin>>ws, dept_name);
		cout<<"Id of manager : ";
		cin>>manager_id;
		cout<<"Current Project : ";
		getline(cin>>ws, project_name);
	}
};

class Employee: public Empinfo, public Deptinfo
{
public:
	void set_employee()
	{
		cout<<"Enter employes basic information.\n";
		set_empinfo();
		cout<<"Enter Department infrmation of employee.\n";
		set_deptinfo();	
	}
	void get_employee()
	{
		cout<<"Employee ID     : "<<empid<<"\n";
		cout<<"Name            : "<<name<<"\n";
		cout<<"Gender          : "<<gender<<"\n";
		
		cout<<"Manager's ID    : "<<manager_id<<"\n";
		cout<<"Department name : "<<dept_name<<"\n";
		cout<<"Project name    : "<<project_name<<"\n";
	}
};

int main()
{
	Employee emp;
	
	emp.set_employee();
	cout<<"\n";
	emp.get_employee();
	
	
	return 0;
}
