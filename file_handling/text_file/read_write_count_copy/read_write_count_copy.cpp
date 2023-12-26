#include <iostream>
#include <fstream>
using namespace std;

class File_operations
{
public:
    void write(const string &filename);
    void read(const string &filename);
    void count_words_lines(const string &filename);
    void copy(const string &source_file, const string &destination_file);
};
void File_operations::write(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout<<"Failed to open file!\n";
        return;
    }
    
    string line;
    cout<<"Enter text into file, type ($$) to finish.\n";
    while (getline(cin>>ws, line) && line != "$$")
    {
        file<<line<<"\n";
    }
    file.close();
}
void File_operations::read(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout<<"Failed to open file!\n";
        return;
    }
    
    string line;
    while (getline(file, line))
    {
        cout<<line<<"\n";
    }
    file.close();
}
void File_operations::count_words_lines(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout<<"Failed to open file!\n";
        return;
    }
    
    int words = 0;
    int lines = 0;
    string word;
    while (file>>word)
    {
        words++;
    }
    
    file.clear();
    file.seekg(0, ios::beg);

    string line;
    while (getline(file, line))
    {
        lines++;
    }
    
    cout<<"Word count : "<<words<<"\n";
    cout<<"Line count : "<<lines<<"\n";
}
void File_operations::copy(const string &source, const string &destination)
{
    ifstream source_file(source);
    ofstream destination_file(destination);
    if (!source_file.is_open())
    {
        cout<<"Unable to open source file!\n";
        return;
    }
    if (!destination_file.is_open())
    {
        cout<<"Unable to open destination file!\n";
        return;
    }
    
    destination_file<<source_file.rdbuf();

    source_file.close();
    destination_file.close();
}

int main()
{
    string file1 = "f1.txt";
    string file2 = "f2.txt";

    File_operations o;

    o.write(file1);
    o.read(file1);
    cout<<"\n\n";
    o.count_words_lines(file1);
    o.copy(file1, file2);

    cout<<"\n\n";
    o.read(file2);
    return 0;
}