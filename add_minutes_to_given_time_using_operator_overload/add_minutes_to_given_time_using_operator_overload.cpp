#include <iostream>
using namespace std;

class Time
{
    int minute;
    int hour;

    public:
    Time(){}
    Time(int m, int h);
    Time operator + (int minutes);
    void show();
};

Time::Time(int m, int h)
{
    minute = m;
    hour = h;
}

Time Time::operator + (int minutes)
{
    Time new_time;

    new_time.minute = this->minute + minutes;
    new_time.hour = hour;

    if (new_time.minute>60)
    {
        new_time.hour = new_time.hour + (new_time.minute/60);
        new_time.minute = new_time.minute%60;
    }
    
    return new_time;
}

void Time::show()
{
    cout<<hour<<":"<<minute<<endl;
}

int main()
{
    int minute;
    int hour;

    cout<<"Enter Hours and Minutes Respectively : ";
    cin>>hour>>minute;

    int minutes;
    cout<<"Enter number of minutes to be added : ";
    cin>>minutes;

    Time t1, updated_time;
    t1 = Time(minute, hour);

    updated_time = t1 + minutes;

    cout<<"Old Time : ";
    t1.show();

    cout<<"Updated Time : ";
    updated_time.show();

    return 0;
}