#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  //N : 건물의 종류
    cin >> N;

    vector<vector<int>> A( N+1);      //인접리스트
    vector<int> indegree(N + 1);       //진입 차수 배열
    vector<int> selfBuild(N + 1);       //자신의 시간

    for(int i=1;i<=N;i++)
    {
        cin >> selfBuild[i];    //해당 건물을 짓기 위한 시간
        while(true)
        {
            int preTemp;
            cin >> preTemp;
            if (preTemp == -1)
                break;
            A[preTemp].push_back(i);
            indegree[i]++;      //진입 차수 데이터 저장
        }
    }

    queue<int> queue;
    for(int i=1; i<=N;i++)
    {
        if (indegree[i] == 0)
            queue.push(i);
    }

    vector<int> result(N+1);

    while(!queue.empty())
    {
        int now = queue.front();
        queue.pop();
        for(int next : A[now])
        {
            indegree[next]--;
            result[next] = max(result[next], result[now] + selfBuild[now]);
            if (indegree[next] == 0) {
                queue.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] + selfBuild[i] << "\n";
    }

}
