#include <string>
#include <vector>

using namespace std;

vector<bool> Visited;

void DFS(const vector<vector<int>>& computers, int num)
{
    if(Visited[num])
        return;
    Visited[num] = true;
    
    for(int i= 0; i<computers[num].size();i ++)
    {
        if(computers[num][i] == 1 && i != num)
            DFS(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    Visited = vector<bool>(n, false);
    
    for(int i=0;i<computers.size();i++)
    {
        if(Visited[i] == false)
        {
            answer++;
            DFS(computers, i);
        }
    }
    
    
    return answer;
}