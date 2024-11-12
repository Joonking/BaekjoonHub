#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(string s : quiz)
    {
        vector<string> StrVector;
        stringstream SS(s);
        string Temp;
        while(SS >> Temp)
        {
            StrVector.push_back(Temp);
        }
        int LeftResult = stoi(StrVector[0]);
        if(StrVector[1] == "+")
            LeftResult += stoi(StrVector[2]);
        else
            LeftResult -= stoi(StrVector[2]);
        
        if(LeftResult == stoi(StrVector[4]))
            answer.push_back("O");
        else
            answer.push_back("X");
    }
    
    return answer;
}