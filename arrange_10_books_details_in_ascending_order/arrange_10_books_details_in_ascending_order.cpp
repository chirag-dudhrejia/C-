#include <iostream>
using namespace std;

class Book
{
    string title;
    string author;
    int year;
    float price;

    public:
    Book(){}
    Book(string, string, int, float);
    void display();
    friend void sort_by_price(Book books[]);
};

Book::Book(string book_title, string book_author, int Publish_year, float book_price)
{
    title = book_title;
    author = book_author;
    year = Publish_year;
    price = book_price;
}

void sort_by_price(Book books[])
{
    int flag = 0;
    Book temp;
    for (int i = 0; i < 10-1; i++)
    {
        flag = 0;
        for (int j = 0; j < (10-i)-1; j++)
        {
            if (books[j].price > books[j+1].price)
            {
                flag = 1;
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
            
        }

        if (flag == 0)
        {
            break;
        }
        
        
    }
    
}

void Book::display()
{
        cout <<title<<"   ";
        cout <<author<<"   ";
        cout <<year<<"   ";
        cout <<price<<"   "<<endl;   
}

int main()
{
    Book books[10];

    books[0] = Book("Harry Potter", "J.K. Rowlins", 2001, 103);
    books[1] = Book("Harry Potter 2", "J.K. Rowlins", 2002, 204);
    books[2] = Book("Harry Potter 3", "J.K. Rowlins", 2003, 306);
    books[3] = Book("Harry Potter 4", "J.K. Rowlins", 2004, 109);
    books[4] = Book("Harry Potter 5", "J.K. Rowlins", 2005, 175);
    books[5] = Book("Harry Potter 6", "J.K. Rowlins", 2006, 165);
    books[6] = Book("Harry Potter 7", "J.K. Rowlins", 2007, 142);
    books[7] = Book("Harry Potter 8", "J.K. Rowlins", 2008, 1002);
    books[8] = Book("Harry Potter 9", "J.K. Rowlins", 2009, 189);
    books[9] = Book("Harry Potter 10", "J.K. Rowlins", 2010, 195);

    for (int i = 0; i < 10; i++)
    {
        books[i].display();
    }
    
    sort_by_price(books);

        cout<<endl<<endl;
    for (int i = 0; i < 10; i++)
    {
        books[i].display();
    }

}