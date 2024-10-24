#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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

vector<string> Board;

int WBCount(int y, int x)
{
	int Count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			int TempY = y + i;
			int TempX = x + k;

			if (Board[TempY][TempX] == WB[i][k])
				Count++;

		}
	}
	return Count;
}

int BWCount(int y, int x)
{
	int Count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			int TempY = y + i;
			int TempX = x + k;

			if (Board[TempY][TempX] == BW[i][k])
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

	Board.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> Board[i];
	}
	int MinCount = INT_MAX;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int k = 0; k <= M - 8; k++)
		{
			MinCount = min(MinCount, WBCount(i, k));
			MinCount = min(MinCount, BWCount(i, k));
		}
	}

	cout << MinCount; 

	return 0;
}