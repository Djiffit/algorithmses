#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

long x, n;
unordered_set<long> sums;

int main()
{
    cin >> n;

    vector<long> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    for (auto coin : coins)
    {
        unordered_set<long> new_sums;
        for (auto sum : sums)
            new_sums.insert(sum + coin);
        new_sums.insert(coin);
        sums.merge(new_sums);
    }
    vector<long> result(sums.begin(), sums.end());
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto res : result)
        cout << res << " ";
}