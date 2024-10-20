#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &tree, vector<bool> &visited, vector<int> &answer, int number)
{
    visited[number] = true;
	for(int i : tree[number])
	{
		if(!visited[i])
		{
            answer[i] = number;
            DFS(tree, visited, answer, i);
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;      //노드의 개수
    cin >> N;

    vector<vector<int>> Tree(N+1);
    vector<bool> Visited(N + 1, false);
    vector<int> Answer(N + 1,0);

    for(int i=0;i<N-1;i++)
    {
        int a, b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    DFS(Tree, Visited, Answer, 1);

    for(int i=2;i<N+1;i++)
    {
        cout << Answer[i] << "\n";
    }
   
}