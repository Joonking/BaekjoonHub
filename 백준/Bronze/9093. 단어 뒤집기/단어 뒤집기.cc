#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string line;
        getline(cin, line);

        stack<char> stk;
        
        for (char ch : line)
        {
            if (ch == ' ')
            {
                while (stk.empty() == false)
                {
                    cout << stk.top();
                    stk.pop();
                }
                cout << ' ';
            }
            else
            {
                stk.push(ch);
            }
        }

        while (stk.empty() == false)
        {
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }

    return 0;
}