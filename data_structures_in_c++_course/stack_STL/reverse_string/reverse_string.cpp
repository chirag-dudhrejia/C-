#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> str;
    string text;

    cout<<"Enter String to reverse.\n";
    getline(cin>>ws, text);

    for (char c: text)
    {
        str.push(c);
    }

    int size = text.length();

    for (int i = 0; i < size; i++)
    {
        text[i] = str.top();
        str.pop();
    }
    
    cout<<"\nReversed string.\n";
    cout<<text<<"\n\n";
    
    return 0;
}