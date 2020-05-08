#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<tuple<int, int, int>> candidates;
vector<int> visited;
vector<vector<int>> nodes;

int main()
{
    int n, x, y;
    long total = 0;
    cin >> n;
    visited = vector<int>(n + 1, 0);
    nodes = vector<vector<int>>(n + 1, vector<int>());
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
}