#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int N;
static vector<int> D, Ti, Pi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	D.resize(N + 2);
	Ti.resize(N + 1);
	Pi.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> Ti[i] >> Pi[i];
	}

	for (int i = N; i > 0; i--)
	{
		if (i + Ti[i] > N + 1)    //i번째 상담을 퇴사일까지 끝낼 수 없는 경우
		{
			// i : 현재날짜 + Ti[i] : 상담이 걸리는 기간 > N+1 : 퇴사날
			D[i] = D[i + 1];  
		}
		else						//i 번째 상담을 퇴사일까지 끝낼 수 있는 경우
		{
			D[i] = max(D[i + 1], D[i + Ti[i]] + Pi[i]);
		}
	}
	cout << D[1];

}