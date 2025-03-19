#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(int a, int b)
{
    string A = to_string(a);
    string B = to_string(b);
    return (A+B) > (B+A);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), Compare);
    
    for(int num : numbers)
    {
        answer += to_string(num);
    }
    
    if(answer[0] == '0') return "0";
    
    return answer;
}