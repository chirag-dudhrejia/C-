#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> stck;
    string str;

    cout<<"Enter string to remove all adjacent duplicates.\n";
    getline(cin>>ws, str);

    for (char c: str)
    {
        if (!stck.empty() && stck.top() == c)
        {
            stck.pop();
        }
        else
        {
            stck.push(c);
        } 
    }

    stack<char> stck2;
    char element;
    while (!stck.empty())
    {
        element = stck.top();
        stck.pop();
        stck2.push(element); 
    }

    str.clear();
    while (!stck2.empty())
    {
        str += stck2.top();
        stck2.pop();
    }

    cout<<"Output.\n";
    cout<<str;
}