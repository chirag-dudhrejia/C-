#include <iostream>
#include <typeinfo>
using namespace std;


int main()
{
    float int_arr[] = {2.3, 4.5, 6.7, 8.75};

    const int size = *(&int_arr + 1) - int_arr;

    cout<<size<<"\n";

    return 0;
}