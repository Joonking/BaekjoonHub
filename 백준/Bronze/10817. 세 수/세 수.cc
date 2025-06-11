#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	sort(a, a + 3);
	cout << a[1];
}