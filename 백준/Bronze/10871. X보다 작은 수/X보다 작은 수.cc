#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, X;
	cin >> N >> X;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if(t<X)
			v.push_back(t);
	}

	for (int i : v)
		cout << i << " ";
}