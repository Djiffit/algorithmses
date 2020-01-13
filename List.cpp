#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    if (n < 4 && n > 1)
    {
        std::cout << "NO SOLUTION";
        return 0;
    }
    std::vector<int> evens;
    std::vector<int> odds;
    for (int i = 1; i <= n; i++)
    {
        if ((i % 2) == 1)
        {
            odds.push_back(i);
        }
        else
        {
            evens.push_back(i);
        }
    }
    evens.insert(evens.end(), odds.begin(), odds.end());
    for (auto i = evens.begin(); i != evens.end(); ++i)
    {
        std::cout << *i << ' ';
    }
}
