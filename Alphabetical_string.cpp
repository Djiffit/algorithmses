// Create lexicographically smallest string where no two adjacent
// characters are the same. len(n) <= 10e6.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int characters[128] = {0};
string s;
string out = "";
int max_count = 0;
char max_char;

void check_max()
{
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (characters[int(i)] > characters[int(max_char)])
        {
            max_count = characters[int(i)];
            max_char = i;
        }
    }
}

bool insert_char(char c)
{
    int rem_spots = s.size() - out.size();
    if (floor(rem_spots / 2) + 1 > max_count || c == max_char || out[out.size() - 1] == max_char)
    {
        characters[int(c)] -= 1;
        out += c;
        if (c == max_char)
            check_max();
        return true;
    }
    return false;
}

void add_chars()
{
    char last = out[out.size() - 1];

    for (auto c = 'A'; c <= 'Z'; c++)
    {
        if (last == c || characters[int(c)] == 0)
            continue;

        auto inserted = insert_char(c);

        if (!inserted)
            continue;
        break;
    }
    if (out.size() != s.size())
        add_chars();
}

int main()
{
    cin >> s;

    for (auto ch : s)
    {
        characters[int(ch)] += 1;
        if (characters[int(ch)] > max_count || (characters[int(ch)] > max_count && ch < max_char))
        {
            max_count = characters[int(ch)];
            max_char = ch;
        }
        if (characters[int(ch)] >= (int)(s.size() - characters[int(ch)] + 2))
        {
            cout << -1;
            return 0;
        }
    }

    add_chars();

    cout << out << "\n ";
    assert(out.size() == s.size());
}