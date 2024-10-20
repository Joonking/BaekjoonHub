//007_1940 주몽의 명령

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	//크기 N짜리 int 형 벡터 생성 및 모두 0으로 초기화
	vector<int> v(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	//정렬 sort 시간복잡도 : nlogn
	sort(v.begin(), v.end());

	int count = 0;
	int start = 0;
	int end = N - 1;

	while (start < end) // start와 end가 교차되는 순간 종료
	{
		if (v[start] + v[end] < M)
		{
			start++;
		}
		else if (v[start] + v[end] > M)
		{
			end--;
		}
		else
		{
			count++;
			start++;
			end--;
		}
	}
	cout << count << "\n";

}