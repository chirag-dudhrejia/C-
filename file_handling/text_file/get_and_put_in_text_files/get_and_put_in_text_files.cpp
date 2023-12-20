#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char output, input;
    ofstream outfile;
    outfile.open("file.txt");

    while (true)
    {
        cin.get(output);
        if (output == '$') {break;}
        outfile<<output;
    }
    outfile.close();

    ifstream inputfile;
    inputfile.open("file.txt");

    cout<<"\n\n";
    while (!inputfile.eof())
    {
        inputfile.unsetf(ios::skipws);
        inputfile>>input;
        cout<<input;
    }
    inputfile.close();
    return 0;
}