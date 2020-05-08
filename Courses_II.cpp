#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
long n, m, a, b;

int main()
{
    cin >> n >> m;
    vector<set<long>> requirements(n + 1);
    priority_queue<long> possible;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        requirements[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
        if (requirements[i].size() == 0)
            possible.push(-i);

    while (possible.size() > 0)
    {
        auto curr = possible.top();
        possible.pop();
    }
}