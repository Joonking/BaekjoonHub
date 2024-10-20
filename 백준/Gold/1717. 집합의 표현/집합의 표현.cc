#include <iostream>
#include <vector>

using namespace std;

vector<int> Node;

int FindFunction(int a)
{
	if (Node[a] == a)
		return a;
	return Node[a] = FindFunction(Node[a]);
}

void UnionFunction(int a, int b)
{
	int CandidateA = FindFunction(a);
	int CandidateB = FindFunction(b);

	if (CandidateA != CandidateB)
		Node[CandidateB] = CandidateA;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	Node.resize(n + 1);

	for (int i = 0; i <= n; i++)
	{
		Node[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int Type, A, B;
		cin >> Type >> A >> B;

		if (Type == 0)
		{
			UnionFunction(A, B);
		}
		else if (Type == 1)
		{
			if (FindFunction(A) == FindFunction(B))
				cout << "YES" << "\n";
			else
			{
				cout << "NO" << "\n";
			}
		}

	}



	return 0;
}