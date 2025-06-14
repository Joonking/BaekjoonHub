#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;

    for (int x : scoville)
        PQ.push(x);

    while (PQ.top() < K) {
        // 더 섞을 수 있는 재료가 부족하면 실패
        if (PQ.size() < 2)
            return -1;

        int a = PQ.top(); PQ.pop();
        int b = PQ.top(); PQ.pop();
        PQ.push(a + b * 2);
        answer++;
    }

    return answer;
}