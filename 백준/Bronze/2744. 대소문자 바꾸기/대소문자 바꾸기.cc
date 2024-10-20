#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	for (int i=0;i<str.size();i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	}

	cout << str;
}
