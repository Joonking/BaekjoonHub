
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Account
{
	int ID;
	int Age;
	string Name;
};

bool operator<(Account const& left, Account const& right)
{
	if (left.Age == right.Age)
	{
		return left.ID < right.ID;
	}
	return left.Age < right.Age;
}

bool operator>(Account const& left, Account const& right)
{
	if (left.Age == right.Age)
	{
		return left.ID > right.ID;
	}
	return left.Age > right.Age;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Account> v;

	for (int i = 0; i < N; i++)
	{
		Account tempAccount;
		tempAccount.ID = i;
		cin >> tempAccount.Age >> tempAccount.Name;
		v.push_back(tempAccount);
	}

	sort(v.begin(), v.end());

	for (Account i : v)
	{
		cout << i.Age << ' ' << i.Name << "\n";
	}
}