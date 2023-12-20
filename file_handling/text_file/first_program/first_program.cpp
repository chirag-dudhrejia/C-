#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string output, input;;
    ofstream outfile;
    outfile.open("first.txt");

    while (true)
    {
        getline(cin>>ws, output);
        if (output == "end") {break;}
        outfile<<output<<endl;
    }

    outfile.close();

    ifstream inputfile;
    inputfile.open("first.txt");

    while (!inputfile.eof())
    {
        getline(inputfile, input);
        cout<<input<<"\n";
    }
    inputfile.close();
    return 0;
}