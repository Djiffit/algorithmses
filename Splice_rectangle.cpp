#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long w, h;
vector<vector<long>> cache;

long get_cuts(int a, int b)
{
    int min = cache[a][b];
    if (min > 0)
    {
        return min;
    }

    if (a % b == 0)
    {
        min = a / b - 1;
    }
    else if (b % a == 0)
    {
        min = b / a - 1;
    }
    else
    {
        for (int i = 1; i < a / 2 + 1; i++)
        {
            long n = get_cuts(a - i, b);
            long m = get_cuts(i, b);

            if (min == -1 || m + n + 1 < min)
            {
                min = m + n + 1;
            }
        }
        for (int j = 1; j < b / 2 + 1; j++)
        {
            long n = get_cuts(a, b - j);
            long m = get_cuts(a, j);

            if (min == -1 || m + n + 1 < min)
            {
                min = m + n + 1;
            }
        }
    }

    // cout << min << '\n';

    cache[a][b] = min;
    return min;
}

int main()
{
    cin >> w >> h;
    cache = vector<vector<long>>(w + 1, vector<long>(h + 1, -1));
    int res = get_cuts(w, h);
    cout << res;
}