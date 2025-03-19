#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> Days;
    
    for(int i=0;i<progresses.size(); i++)
    {
        int d = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) d++;
        Days.push_back(d);
    }
    
    queue<int> MyQueue;
    MyQueue.push(Days[0]);
    for(int i=1;i<Days.size();i++)
    {
        if(MyQueue.front() >= Days[i])
        {
            MyQueue.push(Days[i]);
        }
        else
        {
            answer.push_back(MyQueue.size());
            while(MyQueue.empty() == false)
            {
                MyQueue.pop();
            }
            MyQueue.push(Days[i]);
        }
    }
    
    if (!MyQueue.empty()) {
        answer.push_back(MyQueue.size());
    }
    
    return answer;
}