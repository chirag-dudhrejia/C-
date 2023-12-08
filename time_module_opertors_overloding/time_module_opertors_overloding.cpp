#include <iostream>
#include <cmath>
using namespace std;

class Time
{
	int hours;
	int minutes;
	int seconds;
	
public:
	Time(): hours(10), minutes(10), seconds(10) {}
	Time(int h, int m, int s);
	Time(const Time& obj);
	Time operator + (int secs);
	Time operator - (int secs);
	void operator = (const Time& obj);
	void display();
};

Time::Time(int h, int m, int s): hours(h), minutes(m), seconds(s) {}

Time::Time(const Time& obj): hours(obj.hours), minutes(obj.minutes), seconds(obj.seconds){}

Time Time::operator +(int secs)
{
	Time new_time = *this;
	
	new_time.seconds = (new_time.seconds + secs)%60;
	new_time.minutes = new_time.minutes + ((new_time.seconds + secs)/60);
	
	if (new_time.minutes >= 60)
	{
		new_time.hours += (new_time.minutes/60);
		new_time.minutes %= 60;
	}
	
	if (new_time.hours >= 24)
	{
		new_time.hours %= 24;
	}

	return new_time;
}

Time Time::operator -(int secs)
{
	Time new_time = *this;
	int hour, minute, second;
	
    second = secs % 60;
    minute = secs / 60;
    hour = minute / 60;

    new_time.seconds = this->seconds - second;
    new_time.minutes = this->minutes - minute;
    new_time.hours = this->hours - hour;

    if (second<0)
    {
        new_time.seconds = 60 + new_time.seconds;
        new_time.minutes--;
    }
    if (new_time.minutes<0)
    {
        new_time.minutes = 60 + new_time.minutes;
        new_time.hours--;
    }
    if (new_time.hours<0)
    {
        new_time.hours = 24 + new_time.hours;
    }
    

	return new_time;
}

void Time::operator = (const Time& obj)
{
	this->hours = obj.hours;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
}

void Time::display()
{
	cout<<hours<<":"<<minutes<<":"<<seconds<<"\n";
}

int main()
{	int  seconds, minutes, hours, varsecs;
	Time t1, t2, t3;
	
	cout<<"Enter Hours, Minutes, Seconds respectively to initialize.\n";
	cin>>hours>>minutes>>seconds;
	
	t1 = Time(hours, minutes, seconds);
	t1.display();
	
	cout<<"Enter number of seconds to add and substrct from existing date : ";
	cin>>varsecs;
	
    cout<<"Using + opertor overloding.\n\n";
	t2 = t1 + varsecs;
	t2.display();
	
    cout<<"Using - opertor overloding.\n\n";
	t3 = t1 - varsecs;
	t3.display();
	
    return 0;
}