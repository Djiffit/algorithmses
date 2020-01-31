#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, p;
vector<long long> changes;

bool can_win(long long capacity)
{
    long long curr = 0;
    for (auto change : changes)
    {
        curr += change;
        curr = min(curr, capacity);
        if (curr < 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        changes.push_back(p);
    }

    long long left = 0;
    long long right = 10e16;
    if (!can_win(right))
    {
        cout << -1;
        return 0;
    }

    while (left < right)
    {
        auto mid = (left + right) / 2;

        bool can_succeed = can_win(mid);
        if (can_succeed && !can_win(mid - 1))
        {
            cout << mid;
            return 0;
        }
        if (can_succeed)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left;
}