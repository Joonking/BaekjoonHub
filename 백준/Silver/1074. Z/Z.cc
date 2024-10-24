#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, r, c;

int Count = 0;
bool Find = false;

void Z(int y, int x, int Size)
{
	if (Find) return;

	if (y == r && x == c)
	{
		Find = true;
		return;
	}

	if (y <= r && r < y + Size && x <= c && c < x + Size)
	{
		int Half = Size / 2;

		Z(y, x, Half);
		Z(y, x + Half, Half);
		Z(y + Half, x, Half);
		Z(y + Half, x + Half, Half);
	}
	else
	{
		Count += Size * Size;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> r >> c;

	Z(0, 0, pow(2,N));

	cout << Count;
	
	return 0;
}