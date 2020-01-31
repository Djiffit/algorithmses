#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
long n;

long nums_smaller(long guess)
{
    long total = 0;
    for (long i = 1; i <= n; i++)
    {
        if (i > guess)
            return total;
        total += min(n, (long)floor(guess / i));
    }
    return total;
}

int main()
{
    cin >> n;
    long left = 1;
    long right = n * n;
    long target = right / 2;

    while (left < right)
    {
        auto mid = (left + right) / 2;
        long smallers = nums_smaller(mid);

        if (smallers <= target)
            left = mid + 1;
        else
            right = mid;
    }

    cout << left;
}
