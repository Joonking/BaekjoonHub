#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    
    int n = sequence.size();
    int left = 0, right =0;
    int sum = sequence[0];
    int minLen = n + 1;
    vector<int> answer = {0, n-1};
    
    while(right < n)
    {
        if(sum <k)
        {
            right++;
            if(right<n)sum +=sequence[right];
        }else if(sum > k)
        {
            sum -= sequence[left];
            left++;
        }
        else{
            if((right - left)<minLen)
            {
                minLen = right - left;
                answer = {left, right};
            }
            right++;
            if(right < n) 
                sum+=sequence[right];
        }
    }
    
    
    
    
    return answer;
}