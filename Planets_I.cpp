#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;
long n, x;

int main()
{
    cin >> n;
    vector<long> conns(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> conns[i];

    vector<long> result(n + 1, 0);

    set<long> visited;
    for (long start = 1; start <= n; start++)
    {
        if (visited.find(start) == visited.end())
        {
            auto curr = start;
            vector<long> history;
            while (visited.find(curr) == visited.end())
            {
                history.push_back(curr);
                visited.insert(curr);
                curr = conns[curr];
            }

            auto element = find(history.begin(), history.end(), curr);
            if (element == history.end())
            {
                auto dist = result[curr];
                for (int i = history.size() - 1; i >= 0; i--)
                {
                    dist++;
                    result[history[i]] = dist;
                }
            }
            else
            {

                auto repeat = curr;
                long length = history.size() - distance(history.begin(), element);
                bool looped = false;
                while (history.size() > 0)
                {
                    auto node = history.back();
                    history.pop_back();
                    if (looped)
                    {
                        length++;
                        result[node] = length;
                    }
                    else
                    {
                        if (repeat == node)
                            looped = true;
                        result[node] = length;
                    }
                }
            }
        }
    }

    for (auto i = 1; i <= n; i++)
        cout << result[i] << '\n';
}
