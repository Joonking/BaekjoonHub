#include <iostream>
#include <cmath>
using namespace std;

int Count = 0;
bool Find = false;
int N, r, c;

void Z(int y, int x, int size)
{
    if (Find) return;

    if (y == r && x == c)
    {
        Find = true;
        return;
    }

    if (y <= r && r < y + size && x <= c && c < x + size)
    {
        Z(y, x, size / 2);
        Z(y, x + size/2, size / 2);
        Z(y + size/2, x, size / 2);
        Z(y + size/2, x +size/2, size / 2);
    }
    else
    {
        Count += size * size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> r >> c;

    Z(0, 0, pow(2,N));

    cout << Count;

    return 0;
}
