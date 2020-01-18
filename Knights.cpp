// N knights sit in a round table, N values of desired amount of food
// N values of delivered food. What is the minimum number of turns
// where one knight passes food to their neighbor until everyone
// has their desired amount of food. N <= 2 * 10e5, 0 <= ni <= 10e9

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
long n, val;
vector<long> desire, accum;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        desire.push_back(val);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        accum.push_back(desire[i] - val);
        if (i > 0)
            accum[i] += accum[i - 1];
    }

    sort(accum.begin(), accum.end());
    long mid = accum[floor(accum.size() / 2)];
    long sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(accum[i] - mid);

    cout << sum;
}