#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> conns;
vector<int> down_dist;
vector<int> up_dist;

int dfs_down(int node, int prev = 0)
{
    for (auto nei : conns[node])
    {
        if (nei != prev)
            down_dist[node] = max(dfs_down(nei, node) + 1, down_dist[node]);
    }

    return down_dist[node];
}

void dfs_up(int node, vector<int> &prev, int prev_node = 0)
{
    prev[node] = 1;
    if (prev_node != 0)
    {
        up_dist[node] = max(up_dist[node], up_dist[prev_node] + 1);
        for (auto nei : conns[prev_node])
        {
            if (nei != node && prev[nei] == 0)
                up_dist[node] = max(down_dist[nei] + 2, up_dist[node]);
        }
    }
    for (auto nei : conns[node])
    {
        if (nei != prev_node)
            dfs_up(nei, prev, node);
    }
    prev[node] = 0;
}

int main()
{
    int n, x, y;
    cin >> n;
    conns = vector<vector<int>>(n + 1, vector<int>());
    down_dist = vector<int>(n + 1, 0);
    up_dist = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        conns[x].push_back(y);
        conns[y].push_back(x);
    }
    dfs_down(1);
    vector<int> visits(n + 1, 0);
    dfs_up(1, visits);

    for (int i = 1; i <= n; i++)
        cout << max(down_dist[i], up_dist[i]) << '\n';
}