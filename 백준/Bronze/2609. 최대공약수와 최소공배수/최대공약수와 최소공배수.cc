#include<iostream>
using namespace std;

int main()
{
	int a, b, ab, r, GCD, LCM;

	cin >> a >> b;
	ab = a * b;
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	while (true)
	{
		r = a % b;
		if (r == 0)break;
		a = b;
		b = r;
	}
	
	GCD = b;
	LCM = ab / b;

	cout << GCD << endl;
	cout << LCM << endl;
}

