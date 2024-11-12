#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    int x = 0, y=0;
    for(string Key : keyinput)
    {
        if(Key == "left")
            x--;
        else if(Key == "right")
            x++;
        else if(Key == "up")
            y++;
        else if(Key == "down")
            y--;
        
        if(x>board[0]/2) x = board[0]/2;
        if(x< -board[0]/2) x = -1 *board[0]/2;
        if(y>board[1]/2) y = board[1]/2;
        if(y< -board[1]/2) y = -board[1]/2;
    }
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}