#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

string least_rotation(string word)
{
    auto n = word.size();
    word += word;

    vector<int> failure(word.size(), -1);
    int best_start = 0;

    for (int pos = 1; pos < word.size(); pos++)
    {
        auto curr_char = word[pos];
        auto i = failure[pos - best_start - 1];

        while (i != -1 && curr_char != word[best_start + i + 1])
        {
            if (curr_char < word[best_start + i + 1])
                best_start = pos - i - 1;

            i = failure[i];
        }

        if (curr_char != word[best_start + i + 1])
        {
            if (curr_char < word[best_start])
                best_start = pos;

            failure[pos - best_start] = -1;
        }
        else
            failure[pos - best_start] = i + 1;
    }

    return word.substr(best_start, n);
}

int main()
{
    string s;
    cin >> s;
    cout << least_rotation(s);
}