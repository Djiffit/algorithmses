#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;

string inp_word;
string match;

struct Trie
{
    struct Trie *children[32];
    long visits = 0;
};

Trie *createNode()
{
    struct Trie *node = new Trie;
    for (int i = 0; i < 32; i++)
        node->children[i] = NULL;
    return node;
}
Trie *insert(struct Trie *root, string key)
{
    struct Trie *curr = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    return curr;
}
void search(struct Trie *root, string &key, int i, int max_len)
{
    struct Trie *curr = root;
    while (i < max_len)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
            return;
        curr = curr->children[index];
        curr->visits += 1;
        i += 1;
    }
}

int num;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    long size = 0;
    cin >> inp_word >> num;
    Trie *root = createNode();
    vector<Trie *> tries;

    for (int i = 0; i < num; i++)
    {
        cin >> match;
        auto node = insert(root, match);
        tries.push_back(node);
    }

    for (int i = 0; i < inp_word.size(); i++)
    {
        search(root, inp_word, i, inp_word.size());
    }

    for (auto n : tries)
        cout << n->visits << '\n';
}