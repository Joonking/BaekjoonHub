#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> Targets(n);
	stack<int> Stack;
	for (int i = 0; i < n; i++)
	{
		cin >> Targets[i];
	}
	vector<char> Ans;
	int Current = 1;
	for (int Target : Targets)
	{
		while (Current <= Target)
		{
			Stack.push(Current++);
			Ans.push_back('+');
		}
		if (Target == Stack.top())
		{
			Stack.pop();
			Ans.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (char c : Ans)
		cout << c << "\n";

	return 0;
}