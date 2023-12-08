#include <iostream>
//#include <stdlib>
using namespace std;
template <class T>
class Array
{
	int size;
	T* arr;
public:
	Array(){}
	Array(int s): size(s), arr(new T[size]) {}
	Array(const Array& obj);
	void input();
	void output();
	Array operator * (const Array& obj);
};

template <class T>
Array<T>::Array(const Array& obj)
{
	*this = Array(obj.size);
	for (int i = 0; i<size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}

template <class T>
void Array<T>::input()
{
	cout<<"Enter "<<size<<" elements in array.\n";
	for(int i = 0; i<size; i++)
	{
		cin>>arr[i];
	}
}

template <class T>
void Array<T>::output()
{
	cout<<"Output.\n";
	for(int i = 0; i<size; i++)
	{
		cout<<this->arr[i]<<" ";
	}
    cout<<"\n\n";
}

template <class T>
Array<T> Array<T>::operator *(const Array& obj)
{
	Array square(size);
	
	for(int i = 0; i<size; i++)
	{
		square.arr[i] = this->arr[i] * obj.arr[i];
	}
	return square;
}

int main()
{
	int size;
	char option = '9';
	cout<<"Enter The size of array : ";
	cin>>size;
	

	
	while(option != '0')
	{
	cout<<"\nChoose datatype to perform task:\n"
		<<"1. Integer.\n"
		<<"2. Float.\n"
		<<"0. Exit\n";
	cin>>option;
	
	if(option == '1')
	{
	cout<<"Integer.\n";
	Array<int> int_arr1(size);
	int_arr1.input();
	cout<<"Int Array 1 ";
	int_arr1.output();
	
	Array<int> int_arr2 = int_arr1;
	cout<<"Int Array 2 ";
	int_arr2.output();
	
	Array<int> result;
	result = int_arr1 * int_arr2;
	cout<<"Int Array result ";
	result.output();
}
	
	else if(option == '2')
	{
	cout<<"Float.\n";
	Array<float> float_arr1(size);
	float_arr1.input();
	cout<<"\nfloat Array 1 ";
	float_arr1.output();
	
	Array<float> float_arr2(float_arr1);
	cout<<"\nfloat Array 2 ";
	float_arr2.output();
	
	Array<float> result;
	result = float_arr1 * float_arr2;
	cout<<"\float Array result ";
	result.output();
}
//	system("cls");
}
	
	return 0;
}