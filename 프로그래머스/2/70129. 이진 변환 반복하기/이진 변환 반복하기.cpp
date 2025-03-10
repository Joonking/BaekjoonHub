#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    
    //이진 변환 횟수
    int CaseCount = 0;
    //제거된 모든 0의 개수
    int ZeroCount = 0;
    
    while(s != "1")
    {
        CaseCount++;
        int OneCount = 0;
        for(char c : s)
        {
            if(c == '0')
            {
                ZeroCount++;
            }
            else if(c == '1')
            {
                OneCount++;
            }
        }
        s = "";
        while(OneCount > 0)
        {
            s = to_string(OneCount%2) + s;
            OneCount /= 2;
        }
        
    }
    
    return {CaseCount,ZeroCount};
}