#include <iostream>
using namespace std;
template <class T>
void swap(T a[], T b[], int size)
{
    // int size = *(&a + 1) - a;
    for (int i = 0; i < size; i++)
    {
        a[i] = a[i] + b[i];
        b[i] = a[i] - b[i];
        a[i] = a[i] - b[i];
    }
}

template <class T>
void setdata(T a[], T b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> b[i];
    }
}

template <class T>
void getdata(T a[], T b[], int size)
{
    // int size = *(&a + 1) - a;

    for (int i = 0; i < size; i++)
    {
        cout << a[i]<<" ";
    }
    cout<<"\n";
    for (int i = 0; i < size; i++)
    {
        cout << b[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int size;
    cout << "Enter Size of arrays : ";
    cin >> size;
    int int_arr1[size], int_arr2[size];
    float float_arr1[size], float_arr2[size];
    char char_arr1[size], char_arr2[size];

    char option = '1';
    while (option != '0')
    {

        cout << "Enter task to perform : "
             << "1. int."
             << "2. float."
             << "3. char."
             << "0. Exit."
             << "\n";
        cin >> option;
        
        if (option == '1')
        {
            cout << "Enter " << size << " integers in both array.\n";
            setdata(int_arr1, int_arr2, size);
            cout << "Before Swap.\n";
            getdata(int_arr1, int_arr2, size);
            swap <int>(int_arr1, int_arr2, size);
            cout << "After Swap.\n";
            getdata(int_arr1, int_arr2, size);
        }
        else if (option == '2')
        {
            cout << "Enter " << size << " floating numbers in both array.\n";
            setdata(float_arr1, float_arr2, size);
            cout << "Before Swap.\n";
            getdata(float_arr1, float_arr2, size);
            swap <float>(float_arr1, float_arr2, size);
            cout << "After Swap.\n";
            getdata(float_arr1, float_arr2, size);
        }
        else if (option == '3')
        {
            cout << "Enter " << size << " characters in both array.\n";
            setdata(char_arr1, char_arr2, size);
            cout << "Before Swap.\n";
            getdata(char_arr1, char_arr2, size);
            swap <char>(char_arr1, char_arr2, size);
            cout << "After Swap.\n";
            getdata(char_arr1, char_arr2, size);
        }
    }
}