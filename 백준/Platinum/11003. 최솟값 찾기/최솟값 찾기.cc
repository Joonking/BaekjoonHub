#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    deque<pair<int, int>> dq; // pair<인덱스, 값>
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        // 현재 수보다 작은 수는 더 이상 최소값이 될 수 없음
        while (!dq.empty() && dq.back().second > num) {
            dq.pop_back();
        }
        dq.push_back({ i, num }); // 인덱스와 함께 deque에 저장
        // L개 이상의 수가 들어있는 경우, 최소값 출력 후 deque에서 제거
        if (dq.front().first <= i - l) {
            dq.pop_front();
        }
        cout << dq.front().second << ' ';
    }
    cout << '\n';
    return 0;
}