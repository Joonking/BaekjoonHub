#include <iostream>
#include <string>
#include <climits>

using namespace std;

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string Board[50];

int BWCount(int a, int b)
{
	int Count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (BW[i][j] != Board[a + i][b + j])
				Count++;
		}
	}
	return Count;
}

int WBCount(int a, int b)
{
	int Count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (WB[i][j] != Board[a + i][b + j])
				Count++;
		}
	}
	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M; 
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> Board[i];
	}

	int MinValue = INT_MAX;
	for (int i = 0; i + 7 < N; i++)
	{
		for (int j = 0; j + 7 < M; j++)
		{
			int temp = min(BWCount(i, j), WBCount(i, j));
			if (temp < MinValue)
			{
				MinValue = temp;
			}
		}
	}

	cout << MinValue;

	return 0;
}