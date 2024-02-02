#include <iostream>
#include <stack>
using namespace std;

class Disk
{
public:
    string data;
    int pos;
    Disk(string data, int pos) : data(data), pos(pos) {}
};

int main()
{
    int n;

    cout << "Enter Number of disks you want in hanoi tower? : ";
    cin >> n;

    stack<Disk> stk1;
    stack<Disk> stk2;
    stack<Disk> stk3;

    for (int i = 0; i < n; i++)
    {
        string da;
        int p;
        cout << "Enter Data " << i + 1 << " : ";
        cin >> da;
        Disk d(da, n - i);

        stk1.push(d);
    }

    while (!stk1.empty())
    {
        if (stk2.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();

            if (!stk3.empty())
            {

                while (!stk3.empty())
                {
                    // cout<<"\nempting s3\n";
                    stk1.push(stk3.top());
                    stk3.pop();
                }

                while (stk1.top().pos != 1)
                {
                    stk2.push(stk1.top());
                    stk1.pop();
                }
                // cout << "\nHey\n";
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        else if (stk3.empty())
        {
            stk3.push(stk1.top());
            stk1.pop();

            while (!stk2.empty())
            {
                stk1.push(stk2.top());
                stk2.pop();
            }

            while (stk1.top().pos != 1)
            {
                stk3.push(stk1.top());
                stk1.pop();
            }
            stk3.push(stk1.top());
            stk1.pop();
        }
        // cout << "\nHey\n";
    }

    cout<<"\n";

    while (!stk2.empty())
    {
        cout << stk2.top().data;
        stk2.pop();
        cout<<"\n";
    }

    return 0;
}