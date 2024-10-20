#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string StrTemp;
	getline(cin, StrTemp);
	int Count = 1;
	for (char c : StrTemp)
	{
		if (c == ' ')
			Count++;
	}
	if (StrTemp[0] == ' ')
		Count--;
	if (StrTemp[StrTemp.size() - 1] == ' ')
		Count--;
	cout << Count;
	return 0;
}