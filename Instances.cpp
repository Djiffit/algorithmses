#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

priority_queue<pair<long long, long long>> counts;
unordered_map<long long, long long> count_by_num;
deque<long long> nums;
long long n, k, x;

void change_val(long long key, long long change)
{
    long long existing = count_by_num[key];
    if (existing == 0)
    {
        count_by_num[key] = 1;
        counts.push({1, key});
    }
    else
    {
        count_by_num[key] = count_by_num[key] + change;
        if (existing + change > 0)
        {
            counts.push({count_by_num[key], key});
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    count_by_num.reserve(n);
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        x = -x;
        nums.push_back(x);
        change_val(x, 1);
    }

    for (auto right = k - 1; right < n; right++)
    {
        while (counts.size() > 0 && counts.top().first != count_by_num[counts.top().second])
        {
            counts.pop();
        }
        cout << -(counts.top()).second << '\n';

        cin >> x;
        x = -x;
        if (right < (n - 1))
        {
            if (nums.front() != x)
            {
                change_val(nums.front(), -1);
                change_val(x, 1);
            }
            nums.pop_front();
            nums.push_back(x);
        }
    }
}