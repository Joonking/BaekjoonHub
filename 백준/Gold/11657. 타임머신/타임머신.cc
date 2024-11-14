#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;


int N, M;

//1 : 출발, 2 : 도착, 3: 가중치
typedef tuple<int, int, int> Edge;

//엣지 리스트
vector<Edge> EdgeList;
//시간 리스트
vector<long> MDistance;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	EdgeList.resize(M);
	MDistance.resize(N + 1, LONG_MAX);

	for (int i = 0; i < M; i++)
	{
		int Start, End, Time;
		cin >> Start >> End >> Time;
		EdgeList[i] = { Start, End, Time };
	}

	MDistance[1] = 0;

	//N-1번 동안 체크
	for (int i = 0; i < N-1; i++)
	{
		for (int k = 0; k < M; k++)
		{
			Edge TempEdge = EdgeList[k];
			int StartNode = get<0>(TempEdge);
			int EndNode = get<1>(TempEdge);
			int Time = get<2>(TempEdge);

			if (MDistance[StartNode] != LONG_MAX && MDistance[StartNode] + Time < MDistance[EndNode])
			{
				MDistance[EndNode] = MDistance[StartNode] + Time;
			}
		}
	}

	bool IsMinusCycle = false;

	for (int k = 0; k < M; k++)
	{
		Edge TempEdge = EdgeList[k];
		int StartNode = get<0>(TempEdge);
		int EndNode = get<1>(TempEdge);
		int Time = get<2>(TempEdge);

		if (MDistance[StartNode] != LONG_MAX && MDistance[StartNode] + Time < MDistance[EndNode])
		{
			IsMinusCycle = true;
		}
	}

	if (IsMinusCycle)
	{
		cout << -1 << "\n";
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (MDistance[i] == LONG_MAX)
				cout << -1 << "\n";
			else
				cout << MDistance[i] << "\n";
		}
	}

	return 0;
}


