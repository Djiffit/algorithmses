#include <iostream>

int main()
{
    int m, x, y;
    std::cin >> m;

    for (long i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        if (std::min(x, y) * 2 < std::max(x, y) || ((x + y) % 3 != 0))
        {
            std::cout << "NO"
                      << "\n";
        }
        else
        {
            std::cout << "YES"
                      << "\n";
        }
    }
}