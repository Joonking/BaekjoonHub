#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	a > b ? cout << ">" : a < b ? cout << "<" : cout << "==";
}