#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000;

int n, m;
vector<int> adj[MAX];

bool visited[MAX];

bool dfs(int node, int depth) {
    if (depth == 4) {
        return true;
    }

    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i];
        if (!visited[nextNode] && dfs(nextNode, depth + 1)) {
            return true;
        }
    }
    visited[node] = false;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (dfs(i, 0)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}