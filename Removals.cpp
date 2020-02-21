#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long arr_size, x;

struct SegmentTree
{

    vector<long> nums;
    vector<long> actual_nums;
    long elems = 0;

    SegmentTree(long elem_count)
    {
        elems = pow(2, ceil(log(elem_count) / log(2)));
        nums = vector<long>(elems * 2, 0);
        actual_nums = vector<long>(elems, 0);
    }

    void insert(long pos, long num)
    {
        pos += elems;
        nums[pos] = num == 0 ? 0 : 1;
        actual_nums[pos - elems] = num;
        for (int i = pos / 2; i >= 1; i = i / 2)
            nums[i] = nums[i * 2] + nums[i * 2 + 1];
    }

    void remove(long pos)
    {
        long point = 1;
        while (point < elems)
        {
            if (nums[point * 2] >= pos)
                point = point * 2;
            else
            {
                pos -= nums[point * 2];
                point = point * 2 + 1;
            }
        }

        cout << actual_nums[point - elems] << '\n';
        insert(point - elems, 0);
    }

    void print_arr()
    {
        for (auto n : actual_nums)
            cout << n << " ";
    }
};

int main()
{
    cin >> arr_size;
    SegmentTree seg = SegmentTree(arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        cin >> x;
        seg.insert(i, x);
    }
    for (int i = 0; i < arr_size; i++)
    {
        cin >> x;
        seg.remove(x);
    }
}