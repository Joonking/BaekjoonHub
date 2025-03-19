#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int One[] = {1,2,3,4,5};
    int Two[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int Three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int OneGood = 0, TwoGood = 0, ThreeGood = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == One[i % 5]) OneGood++;
        if (answers[i] == Two[i % 8]) TwoGood++;
        if (answers[i] == Three[i % 10]) ThreeGood++;
    }
    
    int maxScore = max(OneGood, max(TwoGood, ThreeGood));
    if (OneGood == maxScore) answer.push_back(1);
    if (TwoGood == maxScore) answer.push_back(2);
    if (ThreeGood == maxScore) answer.push_back(3);
    
    return answer;
}