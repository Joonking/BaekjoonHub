#include <iostream>
#include <queue>

using namespace std;

struct Compare
{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, Compare> PQ;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (PQ.empty())
				cout << 0 << "\n";
			else
			{
				cout << PQ.top() << "\n";
				PQ.pop();
			}
		}
		else
			PQ.push(temp);
	}

	return 0;
}