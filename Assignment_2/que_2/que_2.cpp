#include <iostream>
using namespace std;

class arrayContainer
{
    int size;
    int* arr;
    
public:
    arrayContainer(){}
    arrayContainer(int len);
    void set_data();
    arrayContainer operator * (int num);
    void display();
};

arrayContainer::arrayContainer(int len): size(len)
{
    arr = (int*)malloc(sizeof(int)*size);
}

void arrayContainer::set_data()
{
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    
}

arrayContainer arrayContainer::operator * (int num)
{
    arrayContainer result(size);
    for (int i = 0; i < size; i++)
    {
        result.arr[i] = this->arr[i] * num;
    }
    return result;
}

void arrayContainer::display()
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    
}

int main()
{
    int size;
    cout<<"Enter Size Of Array : ";
    cin>>size;

    arrayContainer arr1;
    arr1 = arrayContainer(size);
    arr1.set_data();
    cout<<endl<<"Before."<<endl;
    arr1.display();

    arrayContainer multiplied;
    multiplied = arr1 * 5;
    cout<<endl<<"After."<<endl;
    multiplied.display();

    return 0;
}