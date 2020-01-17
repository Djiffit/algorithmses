#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, c, best = 0;
vector<int> nums;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        nums.push_back(c);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        int remaining = n - i;
        if (remaining < nums[i])
        {
            best = max(best, remaining);
            break;
        }
        best = max(best, nums[i]);
    }
    cout << best;
}