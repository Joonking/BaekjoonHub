#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int Start;
    int End;
    int Weight;

    bool operator> (const Edge& Other) const
    {
        return Weight > Other.Weight;
    }
};

vector<int> Parent;

int Find(int num)
{
    if (Parent[num] == num)
        return num;
    return Parent[num] = Find(Parent[num]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        Parent[b] = a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E;
    cin >> V >> E;
    int A, B, C;

    priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

    // 대표 노드 초기화
    Parent.resize(V + 1);
    for (int i = 1; i <= V; i++) {
        Parent[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        cin >> A >> B >> C;
        Edge TempEdge;
        TempEdge.Start = A;
        TempEdge.End = B;
        TempEdge.Weight = C;
        PQ.push(TempEdge);
    }

    int EdgeCount = 0;
    int Answer = 0;

    while (PQ.empty() == false)
    {
        Edge TEdge = PQ.top();
        PQ.pop();

        if (Find(TEdge.Start) != Find(TEdge.End))
        {
            Union(TEdge.Start, TEdge.End);
            EdgeCount++;
            Answer += TEdge.Weight;
        }

        if (EdgeCount == E - 1)
            break;
    }

    cout << Answer;

    return 0;
}