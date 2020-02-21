#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

long x, m, n;
long start_el = -1;
long start_i = -1;
long long result = 1;
long mod = 1000000007;
map<tuple<long, long, long>, long long> cache;

long long solve(long start, long end, long distance, long long sofar)
{
    if (distance == 0 && (abs(start - end) <= 1 || end == -1))
        return 1;
    if (distance == 0)
        return 0;

    auto cache_val = cache.find({start, end, distance});
    if (cache_val != cache.end())
        return cache_val->second;
    long long increase = 0;
    if (start != -1)
    {
        increase += solve(start, end, distance - 1, sofar) % mod;
        if (start > 1)
            increase += solve(start - 1, end, distance - 1, sofar + 1) % mod;
        if (start < m)
            increase += solve(start + 1, end, distance - 1, sofar + 1) % mod;
    }
    else
        for (int i = 1; i <= m; i++)
            increase += solve(i, end, distance - 1, sofar) % mod;

    cache.insert({{start, end, distance}, increase});
    sofar = (sofar + increase) % mod;
    return increase % mod;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0)
        {
            if (i - start_i - 1 >= 1)
            {
                long long poss = solve(start_el, x, i - start_i - 1, 0) % mod;
                result = result * poss % mod;
            }
            start_el = x;
            start_i = i;
        }
    }

    if (start_i != n - 1)
    {
        long long poss = solve(start_el, -1, start_i == -1 ? n : (n - 1) - start_i, 0) % mod;
        result = result * poss % mod;
    }

    cout << result;
}