#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int Alpabet[26] = { 0 };

	for (char c : s)
	{
		int index = c - 65; //A가 아스키코드 65
		if (c >= 97)  //97이 a임
		{
			index = index - 32;
		}

		Alpabet[index]++;
	}

	int MaxCount = 0;
	int MaxIndex = -1;
	int Overlap = 0;

	for (int i = 0; i < 26; i++)
	{
		if (Alpabet[i] > MaxCount)
		{
			MaxCount = Alpabet[i];
			MaxIndex = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (Alpabet[i] == MaxCount)
		{
			Overlap++;
		}
	}

	if (Overlap >= 2)
	{
		cout << "?";
	}
	else
	{
		char tempC = 65 + MaxIndex;
		cout << tempC;
	}
}