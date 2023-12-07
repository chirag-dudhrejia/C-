#include <iostream>
using namespace std;

template <class T>
class Vector
{
    int size;
    T *arr;

public:
    Vector() {}
    Vector(int s) : size(s), arr(new T[size]) { cout << "hey\n"; }
    T dotproduct(Vector &v2);
    void setdata();
    void getdata();
};

template <class T>
T Vector<T>::dotproduct(Vector &v2)
{
    T result = 0;

    for (int i = 0; i < this->size; i++)
    {
        result += (this->arr[i] * v2.arr[i]);
    }
    return result;
}

template <class T>
void Vector<T>::setdata()
{
    for (int i = 0; i < size; i++)
    {
        cin >> this->arr[i];
    }
}

template <class T>
void Vector<T>::getdata()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << this->arr[i];
    }
    cout << "\n";
}

int main()
{
    int size, int_result;
    float float_result;
    char option = '9';

    cout << "Enter size of vector : ";
    cin >> size;

    while (option != '0')
    {

        cout << "Choose Data Type to perform action.\n"
             << "1. Integer.\n"
             << "2. Float.\n"
             << "0. Exit.\n";
        cin >> option;

        if (option == '1')
        {
            cout << "Enter Data into integer vector 1\n";
            Vector<int> int_v1(size);
            int_v1.setdata();
            cout << "Enter Data into integer vector 2\n";
            Vector<int> int_v2(size);
            int_v2.setdata();
            cout << "Dot Product is : " << int_v1.dotproduct(int_v2);
        }
        else if (option == '2')
        {
            cout << "Enter Data into integer vector 1\n";
            Vector<float> float_v1(size);
            float_v1.setdata();
            cout << "Enter Data into integer vector 2\n";
            Vector<float> float_v2(size);
            float_v2.setdata();
            cout << "Dot Product is : " << float_v1.dotproduct(float_v2) << "\n";
        }
    }
}