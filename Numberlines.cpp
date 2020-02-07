#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long n, x;
unordered_map<long, long> last_occ;
long long mod = 1000000007;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    last_occ.reserve(n);

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        nums[i] = x;
    }

    vector<long long> memo(n + 1, 0);

    memo[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        memo[i] = memo[i - 1] * 2 % mod;

        if (last_occ.find(nums[i]) != last_occ.end())
            memo[i] = memo[i] - memo[last_occ[nums[i]]] % mod;

        last_occ[nums[i]] = (i - 1);
    }

    if (memo[n] - 1 < 0)
        cout << memo[n] - 1 + mod;
    else
        cout << memo[n] - 1;
}