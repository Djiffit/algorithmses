#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int grid[1000][1000] = {0};
int n = 5;

void validate_result()
{
    cout << "Unique sums:" << '\n';

    vector<int> sums;
    unordered_set<int> uniq_sums;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += grid[i][j];
        }
        sums.push_back(sum);
        uniq_sums.insert(sum);
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += grid[j][i];
        }
        sums.push_back(sum);
        uniq_sums.insert(sum);
    }

    sort(sums.begin(), sums.end());

    assert(sums.size() == uniq_sums.size());
    for (auto sum : sums)
    {
        cout << sum << " ";
    }
}

int main()
{
    std::cin >> n;

    if (n < 4)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if (n == 4)
    {
        cout << "3 4 3 4 3 1 1 2 4 4 3 2 2 2 1 1";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        grid[i][0] = 1;
        grid[i][1] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        grid[n - 1][i] = n;
    }
    int curr = 2;

    for (int i = 0; i < n - 1; i++)
    {
        curr = (i % (n - 2)) + 2;
        for (int j = 2; j < n; j++)
        {
            grid[i][j] = curr;
            curr = max((curr + 1) % (n), 2);
        }
    }

    for (int i = 2; i < n; i++)
    {
        grid[n - 2][i] = n - i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    validate_result();
}
