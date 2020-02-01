// Given two stacks of height n, what is the maximum average you can get
// by picking numbers from each stack, when you have to pick at least
// one number from each of the stacks. 1 <= n <= 5 * 10e5, 1 <= ai, bi <= 10e6.

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

long n, x;
vector<pair<long double, int>> first;
vector<pair<long double, int>> second;
vector<pair<long double, int>> larger;
vector<pair<long double, int>> smaller;

int main()
{
    cin >> n;
    long double total = 0;
    long double largest = 0;
    long double second_largest = 0;
    for (long double i = 1; i <= n; i++)
    {
        cin >> x;
        total += x;
        first.push_back({total / i, i});
        largest = max(largest, total / i);
    }
    total = 0;
    for (long double i = 1; i <= n; i++)
    {
        cin >> x;
        total += x;
        second.push_back({total / i, i});
        second_largest = max(second_largest, total / i);
    }
    if (largest == second_largest)
    {
        cout << second_largest;
        return 0;
    }

    if (largest > second_largest)
    {
        smaller = second;
        for (auto i : first)
        {
            if (i.first > second_largest)
                larger.push_back(i);
        }
    }
    else
    {
        smaller = first;
        for (auto i : second)
        {
            if (i.first > largest)
            {
                larger.push_back(i);
            }
        }
    }

    sort(larger.rbegin(), larger.rend());
    long double avg = larger[0].first;
    int count = larger[0].second;

    sort(smaller.begin(),
         smaller.end(),
         [avg, count](const pair<long double, int> &i,
                      const pair<long double, int> &j) {
             return ((j.first * j.second) + (avg * count)) / (j.second + count) < ((i.first * i.second) + (avg * count)) / (i.second + count);
         });

    long double best = 0;
    auto j = smaller[0];
    for (auto i : larger)
    {
        best = max(best, ((j.first * j.second) + (i.first * i.second)) / (i.second + j.second));
    }

    cout << setprecision(20) << best;
}