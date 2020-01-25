#include <iostream>
#include <set>
using namespace std;

long m, n, x;
multiset<long> rooms;

int main()
{
    cin >> n >> m;
    for (auto i = 0; i < n; i++)
    {
        cin >> x;
        rooms.insert(x);
    }

    for (auto i = 0; i < m; i++)
    {
        cin >> x;
        auto room = rooms.lower_bound(x);
        if (room == rooms.end())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << *room << '\n';
            rooms.erase(room);
        }
    }
}