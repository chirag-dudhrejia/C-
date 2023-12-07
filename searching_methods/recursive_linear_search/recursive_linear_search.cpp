#include <iostream>
using namespace std;

template <class T>
class Array
{
    int size;
    T *arr;

public:
    Array() {}
    Array(int s) : size(s), arr(new T[size]) {}
    void input();
    int recursive_linear_search(const T &key, int pos = 0);
};

template <class T>
void Array<T>::input()
{
    cout << "Enter " << size << " elements.\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

template <class T>
int Array<T>::recursive_linear_search(const T &key, int pos)
{
    if (arr[pos] == key)
    {
        return pos;
    }
    else if (size > pos)
    {
        return recursive_linear_search(key, pos + 1);
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter Size of array : ";
    cin >> size;

    char option = '9';

    while (option != '0')
    {
        cout << "Choose Datatype to perform task.\n"
             << "1. Integer.\n"
             << "2. Float.\n"
             << "3. Character.\n"
             << "0. Exit.\n";
        cin >> option;

        if (option == '1')
        {
            Array<int> int_arr(size);
            int_arr.input();
            int int_key;
            cout << "Enter what you want to search : ";
            cin >> int_key;
            int pos = int_arr.recursive_linear_search(int_key);
            cout << "\nThe element " << int_key << " is present at " << pos << " position.\n\n";
        }
        else if (option == '2')
        {
            Array<float> float_arr(size);
            float_arr.input();
            float float_key;
            cout << "Enter what you want to search : ";
            cin >> float_key;
            int pos = float_arr.recursive_linear_search(float_key);
            cout << "\nThe element " << float_key << " is present at " << pos << " position.\n\n";
        }
        else if (option == '3')
        {
            Array<char> char_arr(size);
            char_arr.input();
            char char_key;
            cout << "Enter what you want to search : ";
            cin >> char_key;
            int pos = char_arr.recursive_linear_search(char_key);
            cout << "\nThe element " << char_key << " is present at " << pos << " position.\n\n";
        }
    }

    return 0;
}