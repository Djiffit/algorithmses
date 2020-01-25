#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

long x, n, p;
long total = 0;
vector<long> sums;
deque<long> planks;

pair<pair<deque<long>, deque<long>>, pair<long, long>> split_vec(deque<long> nums, long total)
{
    long rightsum = 0;
    deque<long> right;
    while (rightsum <= total / 2)
    {
        long num = nums.back();
        right.push_front(num);
        nums.pop_back();
        rightsum += num;
    }
    sort(right.begin(), right.end());
    return {{nums, right}, {total - rightsum, rightsum}};
}

void calculate_plank(long remaining, deque<long> nums)
{
    cout << remaining << '\n';
    if (nums.size() > 1)
    {
        total += remaining;
    }
    if (nums.size() <= 2)
        return;

    auto split = split_vec(nums, remaining);

    calculate_plank(split.second.first, split.first.first);
    calculate_plank(split.second.second, split.first.second);
}

int main()
{
    cin >> x >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> p;
        planks.push_back(p);
    }
    sort(planks.begin(), planks.end());
    for (auto i = 0; i < n; i++)
    {
        if (i == 0)
            sums.push_back(0);
        else
            sums.push_back(sums[i - 1] + planks[i - 1]);
    }

    // for (auto i : sums)
    // {
    //     cout << i << '\n';
    // }
    calculate_plank(x, planks);

    cout << total;
}
