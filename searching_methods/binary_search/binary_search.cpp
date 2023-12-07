#include <iostream>
using namespace std;

template <class T>
class Array
{
    const int size;
    T* arr;
public:
    Array(){}
    Array(int s): size(s), arr(new T[size]) {}
    void input();
    void sorting();
    int binary_search(const T& key);
    int first_occurence_bs(const T& key);
    void display();
    template <class U>
    friend void swap(const U& a, const U& b);
};

template <class T>
void Array<T>::input()
{
    cout<<"Enter "<<size<<" elements in array.\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
}

template <class T>
void Array<T>::sorting()
{
    bool sorted = true;
    for (int i = 0; i < size-1; i++)
    {
        sorted = true;
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap<T>(arr[j], arr[j+1]);
                sorted = false;
            }
            
        }
        
        if (sorted == true)
        {
            return;
        }
        
    }
    
}

template <class T>
int Array<T>::binary_search(const T& key)
{
    this->sorting();
    int l = 0;
    int r = size-1;

    cout<<"Sorted array ";
    this->display();

    while (r>=l)
    {
        unsigned int mid = l + (r-l)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            r = mid -1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
    }
    return -1;
}

template <class T>
int Array<T>::first_occurence_bs(const T& key)
{
    this->sorting();
    int l = 0;
    int r = size-1;
    int res = -1;

    while (r >= l)
    {
        int mid = l + (r-l)/2;

        if (arr[mid] == key)
        {
            res = mid;
            r = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }

    }
    return res;
}

template <class U>
void swap(const U& a, const U& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

template <class T>
void Array<T>::display()
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int size;
    cout<<"Enter size of array : ";
    cin>>size;

    char option = '9';

    while (option != '0')
    {
        cout<<"Choose Datatype to perform task.\n"
            <<"1. Integer.\n"
            <<"2. Float.\n"
            <<"3. Character.\n"
            <<"0. Exit.\n";
        cin>>option;

        if (option == '1')
        {
            Array<int> int_arr(size);
            int_arr.input();
            int int_key;
            cout<<"Enter what you want to search : ";
            cin>>int_key;
            int pos = int_arr.binary_search(int_key);
            cout<<"\nThe element "<<int_key<<" is present at "<<pos<<" position.\n\n";
            pos = int_arr.first_occurence_bs(int_key);
            cout<<"\nThe first occurence of element "<<int_key<<" is present at "<<pos<<" position.\n\n";
            pos = int_arr.first_occurence_bs(int_key);
            cout<<"\nThe first occurence of element "<<int_key<<" is present at "<<pos<<" position.\n\n";

        }
        else if (option == '2')
        {
            Array<float> float_arr(size);
            float_arr.input();
            float float_key;
            cout<<"Enter what you want to search : ";
            cin>>float_key;
            int pos = float_arr.binary_search(float_key);
            cout<<"\nThe element "<<float_key<<" is present at "<<pos<<" position.\n\n";
            pos = float_arr.first_occurence_bs(float_key);
            cout<<"The first occurence of element "<<float_key<<" is present at "<<pos<<" position.\n\n";

        }
        else if (option == '3')
        {
            Array<char> char_arr(size);
            char_arr.input();
            char char_key;
            cout<<"Enter what you want to search : ";
            cin>>char_key;
            int pos = char_arr.binary_search(char_key);
            cout<<"\nThe element "<<char_key<<" is present at "<<pos<<" position.\n\n";
            pos = char_arr.first_occurence_bs(char_key);
            cout<<"The first occurence of element "<<char_key<<" is present at "<<pos<<" position.\n\n";

        }
    }
    return 0;
}