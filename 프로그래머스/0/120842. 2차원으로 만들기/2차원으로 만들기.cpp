#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    
    int Size = num_list.size()/n;
    vector<vector<int>> answer(Size);
    
    for(int i=0;i<num_list.size(); i++)
    {
        answer[i/n].push_back(num_list[i]);
    }
    
    return answer;
}