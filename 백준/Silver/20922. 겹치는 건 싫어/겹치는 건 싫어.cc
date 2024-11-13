#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N : 수열 길이, K : 같은 정수를 K개 이하로 포함
int N, K;
vector<int> Nums;
int CheckList[100001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    Nums.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Nums[i];
    }

    int StartIndex = 0, EndIndex = 0;
    int MaxLength = 0;
    int ExceedCount = 0; // K를 초과한 값의 개수 체크

    while (EndIndex < N)
    {
        // 새로운 값을 추가
        int CurrentNum = Nums[EndIndex++];
        CheckList[CurrentNum]++;

        // K를 초과하는 값이 생기면 ExceedCount 증가
        if (CheckList[CurrentNum] > K)
        {
            ExceedCount++;
        }

        // ExceedCount가 0이 될 때까지 StartIndex를 이동
        while (ExceedCount > 0)
        {
            int RemoveNum = Nums[StartIndex++];
            CheckList[RemoveNum]--;

            // StartIndex가 하나 이동해서 K 이하가 되면 ExceedCount 감소
            if (CheckList[RemoveNum] == K)
            {
                ExceedCount--;
            }
        }

        // 현재 윈도우 크기 계산
        MaxLength = max(MaxLength, EndIndex - StartIndex);
    }

    cout << MaxLength;

    return 0;
}
