#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

set<pair<long, long>> starts;
long n, start, stop;

bool check(set<std::pair<long, long>>::iterator iter)
{
    return ((iter->first >= start && iter->first <= stop) ||
            (iter->second >= start && iter->second <= stop) ||
            (iter->first < start && iter->second > stop));
}

bool check_prev(set<std::pair<long, long>>::iterator bound, int i)
{
    bound = prev(bound);
    if (check(bound))
    {
        cout << i + 1;
        return true;
    }
    return false;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> start >> stop;

        auto bound = starts.upper_bound({start, 0});

        if (bound != starts.end())
        {
            if (check(bound))
            {
                cout << i + 1;
                return 0;
            }

            if (bound != starts.begin() && check_prev(bound, i))
                return 0;
        }
        else if (starts.size() > 0 && check_prev(bound, i))
            return 0;
        starts.insert({start, stop});
    }

    cout << -1;
}
