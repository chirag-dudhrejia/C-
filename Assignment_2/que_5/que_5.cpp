#include <iostream>
using namespace std;


class Matrix
{
    int matrix[10][10];
    int rows, cols;

public:
    Matrix(){}
    Matrix(int row, int col);
    Matrix operator * (int num);
    // friend istream& operator >> (istream& input, Matrix& mat);
    friend ostream& operator << (ostream& output, Matrix& mat);
};

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
    
}

Matrix Matrix::operator * (int num)
{
    Matrix result;
    result.rows = this->rows;
    result.cols = this->cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.matrix[i][j] = this->matrix[i][j] * num;
        }
        
    }
    return result;
}

int main()
{
    int row, col;
    Matrix m1, result;

    cout<<"Enter number Rows and Columns.";
    cin>>row>>col;

    cout<<"Enter elements here.";
    m1 = Matrix(row, col);

    result = m1 * 5;

    cout<<endl<<"Output :"<<endl<<result;

    return 0;
}

// istream& operator >> (istream& input, Matrix& mat)
// {
//     input>>mat.rows>>mat.cols;
//     return input;
// }

ostream& operator << (ostream& output, Matrix& mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            output<<mat.matrix[i][j]<<"  ";
        }
        output<<endl;
    }
    
}