#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

long x, n, p;
long total = 0;
priority_queue<long> planks;

int main()
{
    cin >> x >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> p;
        planks.push(-p);
    }

    while (planks.size() > 1)
    {
        auto first = -planks.top();
        planks.pop();
        auto second = -planks.top();
        planks.pop();
        total += first + second;
        planks.push(-(first + second));
    }

    cout << total;
}
