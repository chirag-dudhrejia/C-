#include <iostream>
using namespace std;

// Normal method
void reverse_print(int arr[], int index)
{
    if (index < 0)
    {
        return;
    }
    cout<<arr[index]<<" ";
    return reverse_print(arr, index-1);
}

// Method using stack behaviour of recursion
void stck_reverse_print(int arr[], int size, int index = 0)
{
    if (index >= size)
    {
        return;
    }
    stck_reverse_print(arr, size, index+1);
    cout<<arr[index]<<" ";
}

int main()
{
    int screen_time[] = {7, 9, 6, 9 ,8, 7, 10};

    int size = *(&screen_time + 1) - screen_time;

    cout<<"\nUsing normal method.\n";
    reverse_print(screen_time, size-1);

    cout<<"\n\nUsing stack method.\n";
    stck_reverse_print(screen_time, size);
    cout<<"\n\n";
    return 0;
}