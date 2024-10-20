#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(auto i : queries)
    {
        int startIndex = i[0];
        int endIndex = i[1];
        int K = i[2];
        int MIN = 1000001;
        for(int j=startIndex; j<=endIndex;j++)
        {
            if(arr[j]>K)
            {
                MIN = min(MIN, arr[j]);
            }
        }
        if(MIN == 1000001)
                MIN = -1;
            answer.push_back(MIN);
    }

    return answer;
}