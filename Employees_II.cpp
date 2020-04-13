#include <iostream>
#include <vector>
#include <deque>

using namespace std;

long n, q, p, x, y;

long jump_n(long jumps, long curr, vector<vector<long>> &skip)
{
    for (int j = 0; j < 19; j++)
        if (jumps & (1 << j))
            curr = skip[j][curr];

    if (curr <= 0)
        return 1;
    else
        return curr;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    cin >> n >> q;
    vector<vector<long>> children(n + 2);
    vector<vector<long>> skip(20, vector<long>(n + 2));
    vector<long> depth(n + 2);
    skip[1][0] = 0;

    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        children[p].push_back(i);
        skip[0][i] = p;
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long curr = j;
            auto first = skip[i - 1][j];
            if (first > 0)
                skip[i][j] = skip[i - 1][first];
            else
                skip[i][j] = 0;
        }
    }

    deque<pair<long, long>> queue{{1, 0}};
    depth[1] = 0;

    while (queue.size() > 0)
    {
        auto curr = queue.front();
        queue.pop_front();
        for (auto child : children[curr.first])
        {
            depth[child] = curr.second + 1;
            queue.push_back({child, curr.second + 1});
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;

        long d_x = depth[x];
        long d_y = depth[y];

        if (d_x < d_y)
            y = jump_n(d_y - d_x, y, skip);
        else if (d_y < d_x)
            x = jump_n(d_x - d_y, x, skip);

        if (x == y)
        {
            cout << x << '\n';
            continue;
        }

        long left = min(d_x, d_y);
        long right = 0;
        bool print = true;
        long prev_mid = -1;

        while (left > right)
        {
            long mid = (left + right) / 2;
            long x_val = jump_n(mid, x, skip);
            long y_val = jump_n(mid, y, skip);
            if (mid == prev_mid)
                break;
            prev_mid = mid;
            if (x_val == y_val)
                left = mid;
            else
                right = mid + 1;
        }
        if (print)
            cout << jump_n(left, x, skip) << '\n';
    }
}