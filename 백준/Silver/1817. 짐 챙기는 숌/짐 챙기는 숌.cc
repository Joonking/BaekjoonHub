#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, W, Count = 0;
    vector<string> v;

    cin >> N >> W;
    int tmp = W;

    while (N--)
    {
        int book;
        cin >> book;

        if (tmp - book < 0)
        {
            Count++;
            tmp = W;
        }

        tmp -= book;
    }
    if (tmp == W)
        cout << Count;
    else
        cout << Count + 1;
}