#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

string inp;

vector<int> create_z(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = max(0, min(z[i - l], r - i));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main()
{
    cin >> inp;

    auto z = create_z(inp);
    auto n = inp.size();
    for (int i = n - 1; i >= 1; i--)
        if (z[i] == n - i)
            cout << n - i << " ";
}