#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &list, vector<bool> &visited, int v)
{
    if (visited[v])
        return;

    visited[v] = true;

    for (int i : list[v])
    {
        if (!visited[i])
            DFS(list, visited, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> List(N+1);
    vector<bool> Visited(N+1,false);

    for (int i = 0; i < M; i++)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;

        List[tempA].push_back(tempB);
        List[tempB].push_back(tempA);
    }

    int count = 0;
    for (int i = 1; i < N+1; i++)
    {
        if (!Visited[i])
        {
            count++;
            DFS(List, Visited, i);
        }
    }

    cout << count;
}