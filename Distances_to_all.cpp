#include <iostream>
#include <vector>
using namespace std;
long n, x, y;

vector<vector<long>> conns;
vector<pair<long, long>> down_dist;
vector<pair<long, long>> up_dist;

pair<long, long> dfs_down(long node, long prev = 0)
{
    long num_paths = 1;
    long total_dist = 0;

    for (auto nei : conns[node])
    {
        if (nei != prev)
        {
            auto [paths, dist] = dfs_down(nei, node);
            num_paths += paths;
            total_dist += paths + dist;
        }
    }
    down_dist[node] = {num_paths, total_dist};

    return {num_paths, total_dist};
}

void dfs_up(long node, long prev = 0)
{
    long paths = 0;
    long total = 0;
    if (prev == 0)
        up_dist[node] = down_dist[node];
    else
    {
        auto [prev_p, prev_t] = up_dist[prev];
        auto [down_p, down_t] = down_dist[node];
        auto [prev_down_p, prev_down_t] = down_dist[prev];
        if (prev == 1)
        {
            paths = prev_p - down_p;
            total = prev_t - down_t - down_p + paths;
        }
        else
        {
            paths = prev_p + 1;
            total = prev_t + paths;
            paths += prev_down_p - down_p - 1;
            total += prev_down_p - down_p - 1 + prev_down_t - down_p - down_t;
        }
        up_dist[node] = {paths, total};
    }
    for (auto n : conns[node])
    {
        if (n != prev)
            dfs_up(n, node);
    }
}

int main()
{
    cin >> n;

    conns = vector<vector<long>>(n + 1, vector<long>());
    down_dist = vector<pair<long, long>>(n + 1, {0, 0});
    up_dist = vector<pair<long, long>>(n + 1, {0, 0});
    for (long i = 1; i < n; i++)
    {
        cin >> x >> y;
        conns[x].push_back(y);
        conns[y].push_back(x);
    }

    dfs_down(1);
    dfs_up(1);

    for (long i = 1; i <= n; i++)
        cout << up_dist[i].second + (i != 1 ? down_dist[i].second : 0) << '\n';
}