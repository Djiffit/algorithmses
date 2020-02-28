#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> code(n - 2, 0);
    for (int i = 0; i < n - 2; i++)
        cin >> code[i];

    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> degree(n + 1, 0);
    priority_queue<int> nodes;

    for (int i = 1; i <= n; i++)
        degree[i] = 1;

    for (auto val : code)
        degree[val] += 1;

    for (int i = 1; i <= n; i++)
        if (degree[i] == 1)
            nodes.push(-i);

    for (auto val : code)
    {
        auto i = nodes.top();
        nodes.pop();
        cout << val << " " << -i << '\n';
        degree[val] -= 1;
        if (degree[val] == 1)
            nodes.push(-val);
    }
    int u = nodes.top();
    nodes.pop();
    int v = nodes.top();
    cout << -u << " " << -v;
}