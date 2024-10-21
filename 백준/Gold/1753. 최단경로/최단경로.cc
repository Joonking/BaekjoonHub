#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //V : 정점의 개수, E : 간선의 개수, K : 시작 지점
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> DijkstraList(V + 1);
    
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        DijkstraList[u].push_back({ v,w });
    }

    vector<int> Ans(V + 1, INT_MAX);
    Ans[K] = 0;

    //pair - 거리, 노드
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({ 0, K });

    while (PQ.empty() == false)
    {
        int NowDistance = PQ.top().first;
        int NowNode = PQ.top().second;
        PQ.pop();

        if (NowDistance > Ans[NowNode])
            continue;

        for (const auto& a : DijkstraList[NowNode])
        {
            int NextNode = a.first;
            int NextDistance = a.second;

            if (Ans[NextNode] > Ans[NowNode] + NextDistance)
            {
                Ans[NextNode] = Ans[NowNode] + NextDistance;
                PQ.push({ Ans[NextNode], NextNode });
            }
            
        }
    }

    // 결과 출력
    for (int i = 1; i <= V; i++) {
        if (Ans[i] == INT_MAX) {
            cout << "INF\n";
        }
        else {
            cout << Ans[i] << "\n";
        }
    }

    
    return 0;
}
