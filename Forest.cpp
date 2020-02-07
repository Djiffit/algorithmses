// Given an n x n grid of empty spots . and trees * how many different spots
// there are for 1x1, 2x2 ... nxn buildings on the map? n <= 2500

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long n;

int main()
{
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<vector<long>> verticals(n, vector<long>(n, 10e9));
    vector<vector<long>> horizontals(n, vector<long>(n, 10e9));
    vector<vector<long>> visited(n, vector<long>(n, 0));
    vector<long> skips(n + 1, 0);
    vector<long> squares(n + 1, 0);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cin >> grid[y][x];
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (grid[y][x] == '*')
            {
                verticals[y][x] = 0;
                horizontals[y][x] = 0;
            }
            else
            {
                if (y > 0)
                    verticals[y][x] = verticals[y - 1][x] + 1;
                else
                    verticals[y][x] = 1;
                if (x > 0)
                    horizontals[y][x] = horizontals[y][x - 1] + 1;
                else
                    horizontals[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (grid[y][x] != '*' && visited[y][x] != -1)
            {
                long inc_y = y;
                long inc_x = x;
                long diag = 1;
                if (y > 0 && x > 0 && visited[y - 1][x - 1] > 1)
                {
                    inc_y = y + visited[y - 1][x - 1] - 2;
                    inc_x = x + visited[y - 1][x - 1] - 2;
                    diag = inc_y - y + 1;
                    skips[diag - 1] += 1;
                }
                squares[diag] += 1;

                while (inc_y < n - 1 && inc_x < n - 1 && verticals[inc_y + 1][inc_x + 1] > diag && horizontals[inc_y + 1][inc_x + 1] > diag)
                {
                    inc_y += 1;
                    inc_x += 1;
                    diag += 1;
                    squares[diag] += 1;
                }

                visited[y][x] = diag;
            }
        }
    }

    for (int i = skips.size() - 2; i > 0; i--)
        skips[i - 1] += skips[i];

    for (int i = 1; i <= n; i++)
        cout << squares[i] + skips[i] << '\n';
}