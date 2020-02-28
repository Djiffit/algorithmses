#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

priority_queue<tuple<int, int, int>> candidates;

int main()
{
    int n, x, y;
    long total = 0;
    cin >> n;
    vector<int> visited(n + 1, 0);
    vector<vector<int>> nodes(n + 1, vector<int>());
    deque<pair<int, int>> que = {{1, 0}};

    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }

    while (que.size() > 0)
    {
        auto [node, depth] = que.front();
        que.pop_front();
        visited[node] = 1;
        for (auto neig : nodes[node])
        {
            if (visited[neig] == 0)
            {
                candidates.push({(depth + 1), neig, node});
                que.push_back({neig, depth + 1});
            }
        }
    }

    visited = vector<int>(n + 1, 0);
    while (candidates.size() > 0)
    {
        auto [_, start, end] = candidates.top();
        candidates.pop();

        if (visited[start] == 0 && visited[end] == 0)
        {
            visited[start] = 1;
            visited[end] = 1;
            total += 1;
        }
    }

    cout << total;
}