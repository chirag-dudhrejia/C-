#include <iostream>
using namespace std;

template <class T>
class Stack
{
    T stack[5];
    int top;

public:
    Stack() { top = -1; }
    bool isempty();
    bool isfull();
    void push(T value);
    T pop();
};

template <class T>
bool Stack<T>::isempty()
{
    return top == -1 ? 1 : 0;
}

template <class T>
bool Stack<T>::isfull()
{
    return top == 4 ? 1 : 0;
}

template <class T>
void Stack<T>::push(T value)
{
    if (isfull())
    {
        cout << "Stack is full."
             << "\n";
        return;
    }

    top++;
    stack[top] = value;
}

template <class T>
T Stack<T>::pop()
{
    if (isempty())
    {
        cout << "\nStack is empty.\n"
             << "\n";
        exit(0);
    }
    T poped_value = stack[top];
    top--;
    return poped_value;
}

int main()
{
    Stack<int> int_stack;
    Stack<double> double_stack;
    Stack<string> str_stack;
    char option = '9';
    while (option != '0')
    {
        cout << "\nChoose Data type to perform stack operations.\n"
             << "1. Integer.\n"
             << "2. Double or float.\n"
             << "3. String.\n"
             << "0. Exit.\n";
        cin >> option;

        if (option == '1')
        {

            while (option != '9')
            {
                cout << "\nChoose operation to perform on Integer stack.\n"
                     << "1. Push.\n"
                     << "2. Pop.\n"
                     << "3. Peek.\n"
                     << "9. Return back.\n"
                     << "0. Exit\n";
                cin >> option;

                if (option == '1')
                {
                    int int_val;
                    cout<<"Enter Value.\n";
                    cin >> int_val;
                    int_stack.push(int_val);
                }
                else if (option == '2')
                {
                    cout <<"\n\nPoped : "<< int_stack.pop() << "\n\n";
                }
                else if (option == '3')
                {
                    // cout<<int_stack.peek()<<"\n";
                }
                else if (option == '0')
                {
                    break;
                }
                else
                {
                    cout << "Invalid Input.\n";
                }
            }
        }
        else if (option == '2')
        {

            while (option != '9')
            {
                cout << "\nChoose operation to perform on Double/float stack.\n"
                     << "1. Push.\n"
                     << "2. Pop.\n"
                     << "3. Peek.\n"
                     << "9. Return to main menu.\n"
                     << "0. Exit\n";
                cin >> option;

                if (option == '1')
                {
                    double double_val;
                    cout<<"Enter Value.\n";
                    cin >> double_val;
                    double_stack.push(double_val);
                }
                else if (option == '2')
                {
                    cout <<"\n\nPoped : "<< double_stack.pop() << "\n\n";
                }
                else if (option == '3')
                {
                    // cout<<int_stack.peek()<<"\n";
                }
                else if (option == '0')
                {
                    break;
                }
                else
                {
                    cout << "Invalid Input.\n";
                }
            }
        }
        else if (option == '3')
        {

            while (option != '9')
            {
                cout << "\nChoose operation to perform on Double/float stack.\n"
                     << "1. Push.\n"
                     << "2. Pop.\n"
                     << "3. Peek.\n"
                     << "9. Return Back.\n"
                     << "0. Exit\n";
                cin >> option;

                if (option == '1')
                {
                    string str_val;
                    cout<<"Enter string.\n";
                    cin.ignore();
                    getline(cin, str_val);
                    str_stack.push(str_val);
                }
                else if (option == '2')
                {
                    cout <<"\n\nPoped : "<< str_stack.pop() << "\n\n";
                }
                else if (option == '3')
                {
                    // cout<<int_stack.peek()<<"\n";
                }
                else if (option == '0')
                {
                    break;
                }
                else
                {
                    cout << "Invalid Input.\n";
                }
            }
        }
        else
        {
            cout << "Invalid Output."
                 << "\n";
        }
    }

    cout<<"Exited Program succesfully.\n";
    return 0;
}