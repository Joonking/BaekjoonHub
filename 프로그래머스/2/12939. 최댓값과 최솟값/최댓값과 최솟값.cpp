#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    string temp;
    vector<int> numbers;
    
    // 공백을 기준으로 숫자를 분리해서 벡터에 추가
    while (ss >> temp) {
        numbers.push_back(stoi(temp));
    }
    
    // 최솟값과 최댓값을 벡터에서 찾기
    int minVal = *min_element(numbers.begin(), numbers.end());
    int maxVal = *max_element(numbers.begin(), numbers.end());
    
    // 형식에 맞춰 결과 문자열 생성
    return to_string(minVal) + " " + to_string(maxVal);
}