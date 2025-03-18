#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    for(int i=1;i<triangle.size();i++)
    {
        for(int k=0;k<triangle[i].size();k++)
        {
            if(k == 0)
                triangle[i][k] += triangle[i-1][0];
            else if(k==triangle[i].size() -1)
                triangle[i][k] += triangle[i-1][k-1];
            else
            {
                triangle[i][k] += max(triangle[i-1][k-1], triangle[i-1][k]);
            }
        }
    }
    
    return *max_element(triangle.back().begin(), triangle.back().end());
}
