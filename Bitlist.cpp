#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

struct Range
{
    int start;
    int end;
    size_t operator()(const Range &r) const
    {
        return r.start ^ r.end;
    }
};
namespace std
{
template <>
struct hash<Range>
{
    inline size_t operator()(const Range &r) const
    {
        return r.start ^ r.end;
    }
};
} // namespace std

bool operator<(const Range &lhs, const Range &rhs)
{
    return lhs.start < rhs.start && lhs.end < rhs.end;
}

bool operator>(const Range &lhs, const Range &rhs)
{
    return lhs.start > rhs.start && lhs.end > rhs.end;
}

bool operator==(const Range &lhs, const Range &rhs)
{
    return lhs.start == rhs.start && lhs.end == rhs.end;
}

priority_queue<pair<int, Range>> que;
unordered_set<Range> active_ranges;
set<Range> ranges;
long m, n;
string digit;

void swap_bit(int ind)
{
    // cout << "SWAPPING " << ind << '\n';
    if (digit[ind] == '1')
    {
        digit[ind] = '0';
        auto r = *ranges.find({ind, ind});
        ranges.erase(r);
        active_ranges.erase({r.start, r.end});

        if (r.start != ind)
        {
            Range new_pair = {r.start, ind - 1};
            active_ranges.insert(new_pair);
            que.push({(ind - 1) - r.start, new_pair});
            ranges.insert(new_pair);
        }
        if (r.end != ind)
        {
            Range new_pair = {ind + 1, r.end};
            ranges.insert(new_pair);
            active_ranges.insert(new_pair);
            que.push({r.end - (ind + 1), new_pair});
        }
    }
    else
    {
        digit[ind] = '1';
        if (ind > 0 && digit[ind - 1] == '1' && ind < digit.size() - 1 && digit[ind + 1] == '1')
        {
            auto r = *ranges.find({ind - 1, ind - 1});
            ranges.erase(r);
            active_ranges.erase({r.start, r.end});

            auto r2 = *ranges.find({ind + 1, ind + 1});
            ranges.erase(r2);
            active_ranges.erase({r2.start, r2.end});

            Range new_pair = {r.start, r2.end};
            active_ranges.insert(new_pair);
            que.push({r2.end - r.start, new_pair});
            ranges.insert(new_pair);
        }
        else if (ind > 0 && digit[ind - 1] == '1')
        {
            auto r = *ranges.find({ind - 1, ind - 1});
            ranges.erase(r);
            active_ranges.erase({r.start, r.end});

            Range new_pair = {min(r.start, ind), max(r.end, ind)};
            active_ranges.insert(new_pair);
            que.push({max(r.end, ind) - min(r.start, ind), new_pair});
            ranges.insert(new_pair);
        }
        else if (ind < digit.size() - 1 && digit[ind + 1] == '1')
        {
            auto r = *ranges.find({ind + 1, ind + 1});
            ranges.erase(r);
            active_ranges.erase({r.start, r.end});

            Range new_pair = {min(r.start, ind), max(r.end, ind)};
            active_ranges.insert(new_pair);
            que.push({max(r.end, ind) - min(r.start, ind), new_pair});
            ranges.insert(new_pair);
        }
        else
        {
            Range new_pair = {ind, ind};
            active_ranges.insert(new_pair);
            que.push({0, new_pair});
            ranges.insert(new_pair);
        }
    }
}

int main()
{
    cin >> digit >> m;
    bool in_range = false;
    int start;

    for (int i = 0; i < digit.size(); i++)
    {
        auto c = digit[i];
        if (c == '1')
        {
            if (!in_range)
            {
                in_range = true;
                start = i;
            }
        }
        else
        {
            if (in_range)
            {
                in_range = false;
                ranges.insert({start, i - 1});
                active_ranges.insert({start, i - 1});
                que.push({start - (i - 1), {start, i - 1}});
            }
        }
    }
    if (in_range)
    {
        ranges.insert({start, (int)digit.size() - 1});
        active_ranges.insert({start, (int)digit.size() - 1});
        que.push({start - ((int)digit.size() - 1), {start, (int)digit.size() - 1}});
    }

    for (auto i : ranges)
    {
        cout << i.start << " " << i.end << '\n';
    }
    // cout << "RANGES DONE " << '\n';

    for (int i = 0; i < m; i++)
    {
        cin >> n;
        swap_bit(n);
    }
}
