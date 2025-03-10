#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int transform_count = 0; // 변환 횟수
    int removed_zeros = 0;   // 제거한 0의 개수

    while (s != "1") {
        transform_count++;

        // 0 제거 및 남은 길이 카운트
        int ones_count = 0;
        for (char c : s) {
            if (c == '1') ones_count++;
            else removed_zeros++;
        }

        // 남은 길이를 이진수로 변환
        s = "";
        while (ones_count > 0) {
            s = to_string(ones_count % 2) + s;
            ones_count /= 2;
        }
    }

    return {transform_count, removed_zeros};
}