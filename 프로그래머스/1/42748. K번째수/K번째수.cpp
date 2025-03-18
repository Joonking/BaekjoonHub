#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int c = 0; c < commands.size(); c++)
    {
        int i = commands[c][0] - 1; // 시작 인덱스
        int j = commands[c][1];     // 끝 인덱스 (자른 후 sort에 쓰기 위함)
        int k = commands[c][2] - 1; // k번째 인덱스 (0-based)

        vector<int> NewVector;

        // 새로운 변수 x 사용!
        for (int x = i; x < j; x++)
        {
            NewVector.push_back(array[x]);
        }
        sort(NewVector.begin(), NewVector.end());
        answer.push_back(NewVector[k]);
    }
    
    return answer;
}
