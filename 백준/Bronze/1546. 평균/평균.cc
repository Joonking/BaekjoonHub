#include <iostream>
using namespace std;
int main()
{
	int N, t, M=0, arr[1000];
	float sum = 0.0f;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		arr[i] = t;
		if (t > M)
			M = t;
	}

	for (int i = 0; i < N; i++)
	{
		sum+= (float)arr[i]/M * 100;
	}
	cout << sum / N;
}