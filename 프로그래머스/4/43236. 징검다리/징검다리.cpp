#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    long long left = 1;
    long long right = distance;

    // 꼭 넣어야 함!
    rocks.push_back(distance); 
    sort(rocks.begin(), rocks.end());

    long long Standard = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        Standard = 0;
        int RemoveCount = 0;

        for (int rock : rocks) {
            int RocksDistance = rock - Standard;
            if (RocksDistance < mid) {
                RemoveCount++;  // 바위 제거
            } else {
                Standard = rock; // 바위 유지
            }
        }

        if (RemoveCount > n) {
            right = mid - 1;
        } else {
            answer = mid;      // 가능한 거리니까 저장
            left = mid + 1;    // 더 넓은 거리 도전
        }
    }

    return answer;
}
