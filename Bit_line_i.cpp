#include <iostream>
#include <vector>
using namespace std;
long n, k;
long mod = 1000000007;
int main()
{
    cin >> n >> k;
    long res[1000001] = {0};
    res[0] = 2;

    for (long i = 1; i <= n; i++)
    {
        long long total = 0;
        for (int j = 1; j <= k && i - j >= 0; j++)
            total = (total + res[i - j]) % mod;
        res[i] = total % mod;
    }

    cout << res[n] % mod;
}
