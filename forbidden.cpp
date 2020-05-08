#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
long mod = 1000000007;
long n;
string word;
unordered_map<long, long long> cache;

long long power(long long x, long long y)
{
    int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;

        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

long long count_forbidden(long length)
{
    cout << length << '\n';
    if (length < 0)
        return 0;
    if (length == 0)
        return 1;
    if (cache.find(length) != cache.end())
        return cache[length];
    long long res = (length == 1 ? 26 : (26 * count_forbidden(length - 1) % mod) + (count_forbidden(length - word.size()))) % mod;
    cache[length] = res;
    return res;
}

int main()
{
    cin >> n >> word;
    cout << power(26, n) - count_forbidden(n) << '\n';

    long long result = power(26, n) + power(26, n) - count_forbidden(n) % mod;
    result = (result >= 0) ? result : result + mod;
    cout << result;
}