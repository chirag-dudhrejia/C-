#include <iostream>
using namespace std;

template <class T, int size>
class Matrix
{
    T matrix[size][size];

    public:
    Matrix();

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
        
    }
};

template <class T, int size>
Matrix<T, size>::Matrix()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<"Enter Value for "<<i<<" "<<j<<endl;
            cin>>matrix[i][j];
        }
        
    }
    
}

int main()
{
    int arr[] = {1,2,3,4,5}, size = 5;
    cout<<"Enter Size of Matrix : ";
    cin>>size;

    Matrix <int, 50> m1(arr, size);

}