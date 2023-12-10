#include <iostream>
using namespace std;

void print(int arr[], int size, int index = 0)
{
    if (index >= size)
    {
        return;
    }
    cout<<arr[index]<<" ";
    return print(arr, size, index+1);
}

int main()
{
    int marks[] = {89, 95, 92, 87, 90, 96};

    int size = *(&marks + 1) - marks;

    cout<<"\nArray.\n";
    print(marks, size);
    cout<<"\n\n";
    return 0;
}