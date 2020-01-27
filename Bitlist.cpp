// Given a bit sequence of length n, simulate m bit flips and after each flip,
// print the longest sequence of same bit in the new sequence n <= 2 * 10e5,
// m <= 2 * 10e5

#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

struct Range {
  int start;
  int end;
  size_t operator()(const Range &r) const {
    return hash<long long>()(((long long)r.start) ^ (((long long)r.end) << 32));
  }
};
namespace std {
template <> struct hash<Range> {
  inline size_t operator()(const Range &r) const {
    return hash<long long>()(((long long)r.start) ^ (((long long)r.end) << 32));
  }
};
} // namespace std

bool operator<(const Range &lhs, const Range &rhs) {
  return lhs.start < rhs.start && lhs.end < rhs.end;
}

bool operator>(const Range &lhs, const Range &rhs) {
  return lhs.start > rhs.start && lhs.end > rhs.end;
}

bool operator==(const Range &lhs, const Range &rhs) {
  return lhs.start == rhs.start && lhs.end == rhs.end;
}

priority_queue<pair<int, Range>> que;
unordered_set<Range> active_ranges;
set<Range> ranges;
long m, n;
string digit;

void remove_range(Range r) {
  ranges.erase(r);
  active_ranges.erase(r);
}

void add_range(int start, int end) {
  ranges.insert({start, end});
  active_ranges.insert({start, end});
  que.push({end - start + 1, {start, end}});
}

void swap_bit(int ind) {
  auto r = *ranges.find({ind, ind});
  remove_range(r);

  if (ind == r.start && ind == r.end) {
    auto left = ranges.find({ind - 1, ind - 1});
    auto right = ranges.find({ind + 1, ind + 1});
    int begin, end;
    if (left != ranges.end()) {
      begin = left->start;
      remove_range(*left);
    } else
      begin = ind;

    if (right != ranges.end()) {
      end = right->end;
      remove_range(*right);
    } else
      end = ind;

    add_range(begin, end);
  } else if (ind != r.start && ind != r.end) {
    add_range(r.start, ind - 1);
    add_range(ind + 1, r.end);
    add_range(ind, ind);
  } else if (ind == r.start) {
    add_range(ind + 1, r.end);
    if (ind == 0) {
      add_range(ind, ind);
    } else {
      auto other = *ranges.find({ind - 1, ind - 1});
      remove_range(other);
      add_range(other.start, ind);
    }
  } else if (ind == r.end) {
    add_range(r.start, ind - 1);
    if (ind == digit.size() - 1) {
      add_range(ind, ind);
    } else {
      auto other = *ranges.find({ind + 1, ind + 1});
      remove_range(other);
      add_range(ind, other.end);
    }
  }

  if (digit[ind] == '1')
    digit[ind] = '0';
  else
    digit[ind] = '1';

  while (true) {
    auto top = que.top();
    if (active_ranges.find(top.second) != active_ranges.end()) {
      cout << top.first << '\n';
      break;
    }
    que.pop();
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  active_ranges.reserve(50000);
  cin >> digit >> m;
  char curr = digit[0];
  int start = 0;

  for (int i = 0; i < digit.size(); i++) {
    auto c = digit[i];
    if (curr != c) {
      add_range(start, i - 1);
      start = i;
      curr = c;
    }
  }

  add_range(start, digit.size() - 1);

  for (int i = 0; i < m; i++) {
    cin >> n;
    swap_bit(n - 1);
  }
}
