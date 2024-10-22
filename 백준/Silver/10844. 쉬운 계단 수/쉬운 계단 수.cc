#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    //D[N][H] : 길이가 N인 계단에서 H 높이로 종료되는 계단수를 만들 수 있는 경우의 수
    //D[1][1] : 길이가 1인 계단에서 1높이로, D[1][2] : 1인 계단에서 2높이로
    //D[2][0] : 길이가 2인 계단에서 0높이로 종료되는 계단 - 10 한개
    //D[2][1] : 길이가 2인 계단에서 1높이로 종료되는 계단 - 21 한개 
    //D[2][1] = D[1][0] + D[1][1] = 0 + 1


    long D[101][11] = { 0 };  // 배열 전체를 0으로 초기화
    long mod = 1000000000;

    // 1자리 숫자의 계단 수 초기화
    for (int i = 1; i <= 9; i++)
    {
        D[1][i] = 1;  // 1자리 수는 1부터 9까지
    }

    // 2자리 이상 숫자의 계단 수 계산
    for (int i = 2; i <= N; i++)
    {
        D[i][0] = D[i - 1][1];  // 끝자리가 0일 때는 그 이전 자리에서 1로 끝나는 경우만 가능
        D[i][9] = D[i - 1][8];  // 끝자리가 9일 때는 그 이전 자리에서 8로 끝나는 경우만 가능

        for (int j = 1; j <= 8; j++)
        {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
        }
    }

    // N자리 숫자의 계단 수 합계 계산
    long Sum = 0;

    for (int i = 0; i <= 9; i++)
        Sum = (Sum + D[N][i]) % mod;

    cout << Sum;

    return 0;
}
