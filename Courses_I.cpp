#include <iostream>
#include <vector>
#include <deque>

using namespace std;
long n, m, a, b;

int main()
{
    cin >> n >> m;
    vector<long> prereqs(n + 1);
    vector<vector<long>> edges(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        prereqs[b] += 1;
        edges[a].push_back(b);
    }

    deque<long> queue;
    for (int i = 1; i <= n; i++)
        if (prereqs[i] == 0)
            queue.push_back(i);

    while (queue.size() > 0)
    {
        auto curr = queue.front();
        cout << curr << '\n';
        queue.pop_front();
        for (auto neig : edges[curr])
        {
            prereqs[neig] -= 1;
            if (prereqs[neig] == 0)
                queue.push_back(neig);
        }
    }
}