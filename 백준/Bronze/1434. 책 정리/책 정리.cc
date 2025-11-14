#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<pair<int,bool>> A(N); //박스{남은용량, 패킹여부)
    vector<int> B(M); //책

    for (int i=0;i<N;i++)
    {
        cin >> A[i].first;
    }
    for (int i=0;i<M;i++)
    {
        cin >> B[i];
    }

    int sum = 0;
    for (int i=0;i<M;i++)
    {
        bool bIsFindBox = false;
        for (auto& a : A)
        {
            //박스 패킹 전이면
            if (a.second == false)
            {
                //넣을 곳 찾았다
                if (B[i]<=a.first)
                {
                    bIsFindBox = true;
                    a.first -= B[i];
                    if (a.first == 0)
                        a.second = true;
                    break;
                }
                else // 이 박스 아니다 패킹하고 넘기자
                {
                    //패킹
                    a.second = true;
                    //남은 용량 더하기
                    sum += a.first;
                }
            }
        }
        
        //박스 모두 닫혔다 책 들어갈 곳 없다 시마이
        if (bIsFindBox == false)
            break;
    }
    
    for (auto a : A)
    {
        //패킹이 안된 박스가 있다면
        if (a.second == false)
        {
            //남은 용량 추가로 더해주기
            sum += a.first;
        }
    }
    cout << sum << endl;
    
    return 0;
}