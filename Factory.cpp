#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
unsigned long long n, t, x;
vector<unsigned long long> machines;

bool can_produce(unsigned long long minutes)
{
    unsigned long long total = 0;
    for (auto mach : machines)
    {
        total += floor(minutes / mach);
    }
    return total >= t;
}

int main()
{
    cin >> n >> t;

    for (long i = 0; i < n; i++)
    {
        cin >> x;
        machines.push_back(x);
    }

    unsigned long long left = 0;
    unsigned long long right = 1000000000000000000;

    while (left < right)
    {
        auto mid = (left + right) / 2;
        auto mid_works = can_produce(mid);
        if (mid_works && !can_produce(mid - 1))
        {
            cout << mid;
            return 0;
        }
        if (mid_works)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left;
}
