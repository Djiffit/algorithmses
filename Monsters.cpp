#include <iostream>
#include <vector>
using namespace std;

long n;
char el;

int main()
{
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<long>> total(n, vector<long>(n, 999999));
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> el;
            grid[y][x] = el;
            total[y][x] = 0;
        }
    }
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            long fights = 1000000;
            long addition = grid[y][x] == '*';
            if (y > 0)
                fights = min(fights, total[y - 1][x]);
            if (x > 0)
                fights = min(fights, total[y][x - 1]);
            if (y == 0 && x == 0)
                total[y][x] = addition;
            else
                total[y][x] = addition + fights;
        }
    }

    cout << total[n - 1][n - 1];
    return 0;
}
