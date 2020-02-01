// Given n children in a queue who overtake by c children when they go back to the queue,
// how many children never reach the front of the queue? n <= 5 * 10e5, ci <= n-1

#include <iostream>
#include <vector>
#include <set>

using namespace std;

long n, c;
multiset<long> jumpers;
vector<int> jumps;

bool can_get_candy(int pos)
{
    int total = 0;
    vector<int> jump_counts(pos);
    for (int i = 0; i < pos - 1; i++)
    {
        auto jump = jumps[i];
        if (jump > n - pos)
        {
            jump_counts[n - jump] += 1;
            total += 1;
            if (jump_counts[n - jump] >= n - jump)
                return false;
        }
    }

    for (int i = 1; i < pos; i++)
    {
        jump_counts[i] += jump_counts[i - 1];
        if (jump_counts[i] >= i)
            return false;
    }

    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        jumps.push_back(c);
    }

    int left = 1;
    int right = n;
    int mid;

    while (left < right)
    {
        mid = (left + right) / 2;
        bool mid_can = can_get_candy(mid);

        if (mid_can)
        {
            if (!can_get_candy(mid + 1))
            {
                cout << n - mid;
                return 0;
            }
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    if (can_get_candy(min(left, right)))
        cout << n - min(left, right);
    else
        cout << n - max(left, right);
}