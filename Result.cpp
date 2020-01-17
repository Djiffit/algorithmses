#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, string>> pairs;
int n, x;
string y;

bool sort_pair(const pair<int, string> &a, const pair<int, string> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }

    return a.second < b.second;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> y >> x;
        pairs.push_back({x, y});
    }

    sort(pairs.begin(), pairs.end(), sort_pair);

    for (int i = 0; i < n; i++)
    {
        cout << pairs[i].second << " " << pairs[i].first << "\n";
    }
}