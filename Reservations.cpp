#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long num, m, x;

struct SegmentTree
{
    vector<long> nums;

    SegmentTree(long n)
    {
        nums = vector<long>(n * 2, 0);
    };

    void add_hotel(long pos, long n)
    {
        nums[pos] = n;
        pos /= 2;
        while (pos >= 1)
        {
            nums[pos] = max(nums[pos * 2], nums[pos * 2 + 1]);
            pos /= 2;
        }
    }

    void book_hotel(long ppl)
    {
        if (nums[1] < ppl)
            cout << -1 << '\n';
        else
        {
            long pos = 1;
            while (pos < (long)nums.size() / 2)
            {
                if (nums[pos * 2] >= ppl)
                    pos = pos * 2;
                else
                    pos = pos * 2 + 1;
            }
            cout << pos + 1 - nums.size() / 2 << '\n';
            add_hotel(pos, nums[pos] - ppl);
        }
    }
};

int main()
{
    cin >> num >> m;
    long arr_size = pow(2, ceil(log(num) / log(2)));
    SegmentTree seg = SegmentTree(arr_size);
    for (int i = 0; i < num; i++)
    {
        cin >> x;
        seg.add_hotel(arr_size + i, x);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        seg.book_hotel(x);
    }
}