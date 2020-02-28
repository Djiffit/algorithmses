#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> bfs(const vector<vector<int>> &nodes, int start = 1)
{
    vector<int> visited(nodes.size(), 0);
    deque<pair<int, int>> que = {{start, 0}};
    auto last = start;
    auto length = 0;

    while (que.size() > 0)
    {
        auto [node, depth] = que.front();
        que.pop_front();
        if (visited[node] == 0)
        {
            last = node;
            length = depth;
            visited[node] = 1;
            for (auto neig : nodes[node])
                que.push_back({neig, depth + 1});
        }
    }
    return {last, length};
}

int main()
{
    long n, x, y;
    cin >> n;
    vector<vector<int>> nodes(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }

    auto [node, depth] = bfs(nodes);
    auto [_, res] = bfs(nodes, node);
    cout << res;
}