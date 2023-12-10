#include <iostream>
using namespace std;

int maximum(int arr[], int size, int max, int index = 0)
{
    if (index >= size)
    {
        return max;
    }

    if (arr[index] > max)
    {
        max = arr[index];
    }
    
    return maximum(arr, size, max, index+1);
}

int main()
{
    int match_score[] = {180, 174, 214, 192, 203};

    int size = *(&match_score + 1) - match_score;
    int max = match_score[0];

    max = maximum(match_score, size, max);

    cout<<"Max is : "<<max;

    return 0;
}