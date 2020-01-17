// Find first sum a list of coins cant sum up to
// N <= 10e5, ci <= 10e9

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nums;
long last_sum = 0;
int n, c;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        nums.push_back(c);
    }
    sort(nums.begin(), nums.end());

    for (int num : nums)
    {
        if (num > last_sum + 1)
        {
            break;
        }
        last_sum += num;
    }

    cout << last_sum + 1 << '\n';
}