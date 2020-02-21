#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <assert.h>
using namespace std;

long n, x;

long mod = 1000000007;
struct SegmentTree
{
    vector<long> nums;
    vector<long> max_nums;
    long elems;

    SegmentTree(long num_elems, const vector<long> &numbers)
    {
        elems = pow(2, ceil(log(num_elems) / log(2)));
        nums = vector<long>(2 * elems, 0);
        max_nums = vector<long>(2 * elems, 0);
        for (int i = 0; i < (long)numbers.size(); i++)
        {
            max_nums[elems + i] = numbers[i];
            long pos = (elems + i) / 2;
            while (pos >= 1)
            {
                max_nums[pos] = max(max_nums[pos * 2], max_nums[pos * 2 + 1]);
                pos /= 2;
            }
        }
    }

    long find(long num)
    {
        long pos = 1;
        while (pos < (long)max_nums.size() / 2)
        {
            if (max_nums[pos * 2] >= num)
                pos = pos * 2;
            else
                pos = pos * 2 + 1;
        }
        return pos;
    }

    void insert(long num)
    {
        long total = 0;
        long pos_el = find(num + 1);
        long pos = pos_el;
        while (pos >= 1)
        {
            if (pos % 2 == 1)
                total = (total + nums[pos - 1]) % mod;
            pos /= 2;
        }
        nums[pos_el] += total + 1;

        for (pos = (pos_el) / 2; pos >= 1; pos /= 2)
            nums[pos] = (nums[pos * 2] + nums[pos * 2 + 1]) % mod;
    }

    void print_arr()
    {
        for (auto numba : nums)
            cout << numba << " ";
    }
};

int main()
{
    cin >> n;

    vector<long> num_arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num_arr[i];

    vector<long> sorted_nums(num_arr);
    sort(sorted_nums.begin(), sorted_nums.end());
    SegmentTree seg = SegmentTree(n, sorted_nums);

    for (auto num : num_arr)
        seg.insert(num - 1);

    cout << seg.nums[1];
}
