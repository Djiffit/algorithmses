#include <iostream>
#include <vector>
using namespace std;
long n, k;
long mod = 1000000007;

long long power(long long x, long long y, long p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    k = k - 1;
    long res[1000001] = {0};
    res[0] = 2;

    for (long i = 1; i <= n; i++)
    {
        long long total = 0;
        for (int j = 1; j <= k && i - j >= 0; j++)
            total = (total + res[i - j]) % mod;
        res[i] = total % mod;
    }
    long long result = (power(2, n, mod) - res[n]) % mod;
    if (result >= 0)
        cout << result;
    else
        cout << result + mod;
}