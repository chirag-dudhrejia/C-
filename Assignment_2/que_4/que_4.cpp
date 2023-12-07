#include <iostream>
using namespace std;

class Matrix
{
    int** matrix;
    int rows, cols;

public:
    Matrix(){}
    Matrix(int row, int col);
    void setdata();
    friend ostream& operator << (ostream& output, Matrix& mat);
};

void Matrix::setdata()
{
    for (int i = 0; i < rows; i++)
    {
        cout<<"Enter "<<cols<<" elements for row "<<i<<"\n";
        for (int j = 0; j < cols; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
}

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
    matrix = (int**)malloc(sizeof(int*)*rows);

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*cols);
    }
        
}

ostream& operator << (ostream& output, Matrix& mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            output<<mat.matrix[i][j]<<" ";
        }
        output<<endl;
    }
    
}


int main()
{
    int row, col;
    cout<<"Enter Number Of Rows and Columns : ";
    cin>>row>>col;
    Matrix m1(row, col);
    m1.setdata();

    cout<<"\nMatrix.\n"<<m1;

    return 0;
}