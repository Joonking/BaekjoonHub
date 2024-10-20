//068_1068 리프 노드의 개수 구하기

#include <iostream>
#include <vector>
using namespace std;

static int N;
static vector<vector<int>> tree;
static vector<bool> visited;
static int deleteNode = 0;
static int answer = 0;

void DFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N);
	visited.resize(N);

	int root = 0;

	for(int i=0;i< N;i++)
	{
		int p;
		cin >> p;

		if(p==-1)
		{
			root = i;
		}
		else
		{
			tree[p].push_back(i);
			tree[i].push_back(p);
		}
	}

	cin >> deleteNode;
	if (deleteNode == root)
		cout << 0;
	else
	{
		DFS(root);
		cout << answer<<"\n";
	}
}

void DFS(int num)
{
	visited[num] = true;
	int cNode = 0;

	for(int i : tree[num])
	{
		if(!visited[i] && i!=deleteNode)
		{
			cNode++;
			DFS(i);
		}
	}
	if (cNode == 0)
		answer++;

}








