
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

long n, x;
long long sum;
long mod = 1000000007;

int main()
{
    cin >> n;
    vector<long> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    if (sum % 2 == 1)
    {
        cout << 0;
        return 0;
    }

    vector<long> num_sums(sum / 2 + 1, 0);
    num_sums[0] = 1;

    for (int num = 1; num <= n; num++)
    {
        for (int tot = sum / 2; tot >= 1; tot -= 1)
        {
            if (tot - nums[num] >= 0)
                num_sums[tot] = (num_sums[tot] + num_sums[tot - nums[num]]) % mod;
        }
    }

    cout << num_sums[sum / 2] % mod;
}