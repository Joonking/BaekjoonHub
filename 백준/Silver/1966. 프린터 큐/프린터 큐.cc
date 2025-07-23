#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> PrintQueue;
        priority_queue<int> PQ;

        for (int i = 0; i < N; i++)
        {
            pair<int, int> Node;
            cin >> Node.first;
            Node.second = i;

            PrintQueue.push(Node);
            PQ.push(Node.first);
        }
        int Order = 0;
        while (PrintQueue.empty() == false)
        {
            pair<int, int> FrontNode = PrintQueue.front();
            PrintQueue.pop();
            if (FrontNode.first < PQ.top())
            {
                PrintQueue.push(FrontNode);
            }
            else if(FrontNode.first == PQ.top())
            {
                if (FrontNode.second == M)
                {
                    cout << ++Order << "\n";
                    break;
                }
                else
                {
                    PQ.pop();
                    Order++;
                }
            }
        }

    }

    return 0;
}