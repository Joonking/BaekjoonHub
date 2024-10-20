#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	unordered_map<int, int> Umap;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Umap[temp]++;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		if (Umap.find(temp) == Umap.end())
			cout << 0 << " ";
		else
			cout << Umap[temp] << " ";
	}

	return 0;
}