#include <iostream>
#include <climits>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int Num[4] = { x, y, w - x, h - y };
	int MinValue = INT_MAX;
	for (int i : Num)
	{
		if (i < MinValue)
			MinValue = i;
	}
	cout << MinValue;
	
	return 0;
}