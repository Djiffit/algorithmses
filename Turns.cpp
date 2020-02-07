#include <iostream>
#include <vector>
using namespace std;

long n;

int main()
{
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<long>> righters(n, vector<long>(n, 10e9));
    vector<vector<long>> downers(n, vector<long>(n, 10e9));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cin >> grid[y][x];
    }

    if (grid[0][0] == '*')
    {
        cout << -1;
        return 0;
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (grid[y][x] != '*')
            {
                if (y == 0 && x == 0)
                {
                    downers[y][x] = 0;
                    righters[y][x] = 0;
                }
                if (y > 0)
                {
                    downers[y][x] = min(righters[y - 1][x] + 1, min(downers[y][x], downers[y - 1][x]));
                    righters[y][x] = min(righters[y][x], min(downers[y - 1][x] + 1, righters[y - 1][x] + 2));
                }
                if (x > 0)
                {
                    downers[y][x] = min(downers[y][x], min(downers[y][x - 1] + 2, righters[y][x - 1] + 1));
                    righters[y][x] = min(righters[y][x], min(downers[y][x - 1] + 2, righters[y][x - 1]));
                }
            }
            else
            {
                downers[y][x] = 10e10;
                righters[y][x] = 10e10;
            }
        }
    }

    if (min(downers[n - 1][n - 1], righters[n - 1][n - 1]) > n * n)
        cout << -1;
    else
        cout << min(downers[n - 1][n - 1], righters[n - 1][n - 1]);
}