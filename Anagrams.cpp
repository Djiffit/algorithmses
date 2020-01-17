#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
string word;
unordered_set<string> sorted_words;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        sort(word.begin(), word.end());
        sorted_words.insert(word);
    }
    cout << sorted_words.size();
}