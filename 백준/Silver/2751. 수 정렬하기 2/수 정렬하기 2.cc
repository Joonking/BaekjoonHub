#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, t;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
}