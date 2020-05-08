#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

long color = 1;

long jump(long curr, long num_steps, vector<vector<long>> &jump_table)
{
    int i = 0;
    while ((num_steps >> i) > 0)
    {
        if (((long)pow(2, i) & num_steps) > 0)
            curr = jump_table[curr][i];
        i++;
    }
    return curr;
}

void find(long a, long b, vector<vector<long>> &jump_table, vector<pair<long, long>> &stats)
{
    long col = stats[a].first;
    long target_col = stats[b].first;
    long dist = stats[a].second;
    long target_dist = stats[b].second;

    if (col != target_col)
        cout << -1 << '\n';
    else if (a == b)
        cout << 0 << '\n';
    else
    {
        if (dist > target_dist)
        {
            if (jump(a, dist - target_dist, jump_table) == b)
            {
                cout << dist - target_dist << '\n';
                return;
            }
        }

        a = jump(a, dist, jump_table);
        long jump_dist = stats[jump_table[a][0]].second - target_dist + 1;
        if (stats[jump_table[a][0]].second < target_dist || jump(a, jump_dist, jump_table) != b)
            cout << -1 << '\n';
        else
            cout << jump_dist + dist << '\n';
    }
}

void mark_nodes(long curr, vector<pair<long, long>> &stats, vector<vector<long>> &connectors)
{
    deque<pair<long, long>> que;
    que.push_back({curr, 0});
    stats[curr] = {color, 0};

    while (que.size() > 0)
    {
        auto curr_data = que.front();
        long c_node = curr_data.first;
        long dist = curr_data.second;
        que.pop_front();

        for (auto prev : connectors[c_node])
        {
            if (stats[prev].second == -1)
            {
                que.push_back({prev, dist + 1});
                stats[prev] = {color, dist + 1};
            }
        }
    }
}

void find_root(long curr, const vector<vector<long>> &jump_table, vector<pair<long, long>> &stats, vector<vector<long>> &connectors)
{
    while (stats[curr].first == 0)
    {
        stats[curr] = {color, -1};
        curr = jump_table[curr][0];
    }

    mark_nodes(curr, stats, connectors);

    color++;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    long n, q, a, b, x;
    cin >> n >> q;

    vector<pair<long, long>> stats(n + 1, {0, -1});
    vector<long> jumps_to(n + 1, 0);
    vector<vector<long>> jump_table(n + 1, vector<long>(18));
    vector<vector<long>> connectors(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        jumps_to[x] += 1;
        connectors[x].push_back(i);
        jump_table[i][0] = x;
    }

    for (int i = 1; i <= n; i++)
        if (jumps_to[i] == 0 && stats[i].first == 0)
            find_root(i, jump_table, stats, connectors);

    for (int i = 1; i <= n; i++)
        if (stats[i].first == 0)
            mark_nodes(i, stats, connectors);

    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++)
            jump_table[j][i] = jump_table[jump_table[j][i - 1]][i - 1];

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        find(a, b, jump_table, stats);
    }
}