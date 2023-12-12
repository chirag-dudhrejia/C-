#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> stck;
    string str;

    getline(cin>>ws, str);

    int size = str.length();

    for (int i = 0; i < size; i++)
    {
        if (!stck.empty() && stck.top() == '(' && str[i] == ')')
        {
            stck.pop();
        }
        else if (str[i] == '(' || str[i] == ')')
        {
            stck.push(str[i]);
        }            
    }

    if (stck.empty())
    {
        cout<<"Balanced\n";
    }
    else
    {
        cout<<"Not Balanced\n";
    }
     
    return 0;
}