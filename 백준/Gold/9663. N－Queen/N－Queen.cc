#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
int sum = 0;
int map[15];

// 유망한지 판단하는 함수
int promising(int cdx) {

	// 같은 열이면 안되고, 대각선상에 있어서도 안 된다.
	for (int i = 0; i < cdx; i++) {
		if (map[cdx] == map[i] || cdx - i == abs(map[cdx] - map[i])) {
			return 0;
		}
	}
	return 1;
}

// nqueen 알고리즘 수행
void nqueen(int cdx) {

	// cdx가 마지막 행까지 수행하고 여기까지 오면, 찾기 완료
	if (cdx == n) {
		sum++;
		return;
	}

	for (int i = 0; i < n; i++) {
		map[cdx] = i; // cdx번째 행, i번째 열에 queen을 놓아본다.	
		// 이후 그 행에 둔 것에 대한 유망성을 판단한다.
		if (promising(cdx)) { // 그 자리에 두어도 괜찮았다면,
			nqueen(cdx + 1); // 그 다음 행에 대해 퀸을 놓는 것을 해 본다.
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	nqueen(0);
	cout << sum << endl;

}