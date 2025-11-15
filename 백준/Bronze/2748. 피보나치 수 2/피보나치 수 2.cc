#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    long long Fibo[100]={0};

    Fibo[0]=0;
    Fibo[1]=1;

    for (int i=2;i<=n;i++)
    {
        Fibo[i] = Fibo[i-1] + Fibo[i-2];
    }
    cout << Fibo[n];
    
    return 0;
}