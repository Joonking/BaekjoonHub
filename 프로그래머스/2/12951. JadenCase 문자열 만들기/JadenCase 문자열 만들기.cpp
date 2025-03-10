#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool IsFirst = true;
    for(char c : s)
    {
        if(c == ' ')
        {
            IsFirst = true;
            answer += ' ';
            continue;
        }
        
        if(IsFirst)
        {
            
            answer += toupper(c);
        }
        else
        {
            answer += tolower(c);
        }
        IsFirst = false;
    }
    
    return answer;
}