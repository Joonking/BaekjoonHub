#include<vector>
#include <queue>
using namespace std;


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    int m = maps.size(); //y크기
    int n = maps[0].size(); //x크기
    
    queue<pair<int, int>> Queue;
    Queue.push({0,0});
    
    while(Queue.empty() == false)
    {
        auto [cy,cx] = Queue.front();
        Queue.pop();
        
        for(int dir=0;dir<4;dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            
            if(ny<0 || ny>=m || nx<0 || nx>=n)
                continue;
            
            if(maps[ny][nx] != 1)
                continue;
            
            Queue.push({ny,nx});
            maps[ny][nx] += maps[cy][cx];
        } 
    }
    
    return maps[m-1][n-1]==1?-1:maps[m-1][n-1];
}




