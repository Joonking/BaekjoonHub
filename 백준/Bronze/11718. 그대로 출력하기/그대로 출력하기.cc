#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string str;
		getline(cin, str);
		if (str.size() == 0)break;
		cout << str << "\n";
	}

}