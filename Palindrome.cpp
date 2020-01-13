#include <iostream>
#include <fstream>

int main()
{
    int counts[26] = {0};
    std::string word;
    std::cin >> word;
    std::string palind = "";
    int odd = -1;

    for (auto &c : word)
    {
        counts[int(c) - int('A')] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] % 2 == 1)
        {
            if (odd != -1)
            {
                std::cout << "NO SOLUTION";
                return 0;
            }
            odd = i;
            for (int j = 0; j < counts[i]; j++)
            {
                char actual = 'A' + i;
                palind += actual;
            }
            counts[odd] = 0;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        char ch = 'A' + i;
        palind = std::string(counts[i] / 2, ch) + palind + std::string(counts[i] / 2, ch);
    }
    std::cout << palind;
}