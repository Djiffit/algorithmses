#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<long> nums;
vector<long> arr;
long n, x;

int main()
{
    long left = 0;
    long right = 0;
    long total = 0;
    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    while (right < (long)arr.size())
    {
        if (nums.find(arr[right]) == nums.end())
        {
            total += right - left + 1;
            nums.insert(arr[right]);
            right += 1;
        }
        else
        {
            nums.erase(arr[left]);
            left += 1;
            if (right < left)
            {
                right = left;
            }
        }
    }
    cout << total;
}