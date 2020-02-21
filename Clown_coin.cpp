#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct SegmentTree
{
    vector<long> nums;
    SegmentTree(long size)
    {
        nums = vector<long>(size * 2, 0);
    }

    void change_num(long pos, long new_num)
    {
        nums[pos] = new_num;
        pos /= 2;
        while (pos >= 1)
        {
            nums[pos] = max(nums[pos * 2], nums[pos * 2 + 1]);
            pos = pos / 2;
        }
    }

    void print_arr()
    {
        for (auto n : nums)
            cout << n << " ";
    }

    void get_max(long start, long end)
    {
        long res = -10e-9;
        while (start <= end)
        {
            if (start % 2 == 1)
                res = max(res, nums[start++]); // If left is right child
            if (end % 2 == 0)
                res = max(res, nums[end--]); // If right is left child
            start = start / 2;
            end = end / 2;
        }
        cout << res << '\n';
    }
};

long n, days, x, a, b;

int main()
{
    cin >> n >> days;
    long arr_size = pow(2, ceil(log(n) / log(2)));
    SegmentTree seg(arr_size);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        seg.change_num(arr_size + i, x);
    }

    for (int i = 0; i < days; i++)
    {
        cin >> a >> b;
        seg.get_max(a + arr_size - 1, b + arr_size - 1);
    }
}