#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
void insert_data(T &arr, int size)
{
    arr = (T)malloc(sizeof(T) * size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

template <class T>
void print_data(T &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

template <class T>
T swapp(T &a, T &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

template <class T>
void Sortt(T &arr, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapp(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int size;
    char option = '9';

    int *int_arr;
    float *float_arr;
    string char_str;

    while (option != '0')
    {
        cout << "Choose Data type to input data.\n"
             << "1. Integer.\n"
             << "2. Float.\n"
             << "3. Character String.\n"
             << "0. Exit program\n";
        cin >> option;

        if (option == '1')
        {
            cout << "Enter size of array you want : ";
            cin >> size;
            cout << "Enter " << size << " Integers for array.\n";
            insert_data<int*>(int_arr, size);

            cout<<"\nBefore Sorting.\n";
            print_data<int*>(int_arr, size);

            Sortt<int*>(int_arr, size);

            cout<<"\nAfter Sorting.\n";
            print_data<int*>(int_arr, size);
        }
        else if (option == '2')
        {
            cout << "Enter size of array you want : ";
            cin >> size;
            cout << "Enter " << size << " floating numbers for array.\n";
            insert_data<float*>(float_arr, size);

            cout<<"\nBefore Sorting.\n";
            print_data<float*>(float_arr, size);

            Sortt<float*>(float_arr, size);

            cout<<"\nAfter Sorting.\n";
            print_data<float*>(float_arr, size);
        }
        // else if (option == '3')
        // {
        //     cout << "Enter string.\n";
        //     cin.ignore();
        //     getline(cin, char_str);
        //     size = char_str.length();
        //     Sortt<string>(char_str, size);
        //     print_data<char>(char_str[0], size);
        // }
    }

    return 0;
}