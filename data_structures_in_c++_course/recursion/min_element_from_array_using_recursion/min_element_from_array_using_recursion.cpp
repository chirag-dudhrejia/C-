#include <iostream>
using namespace std;

int minimum(int arr[], int size, int min, int i = 0)
{

    if (i>=size)
    {
        return min;
    }
    
    if (arr[i]<min)
    {
        min = arr[i];
    }
    

    return minimum(arr, size, min, i+1);
}

int main()
{
    int revenue[] = {35, 67, 23, 78, 54, 93};

    int size = *(&revenue + 1) - revenue;

    int min = revenue[0];
    
    min = minimum(revenue, size, min);

    cout<<"Min is : "<<min;

    return 0;
}