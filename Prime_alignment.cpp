#include <iostream>
#include <vector>
#include <algorithm>

bool is_prime(int num)
{
    if (num <= 3)
    {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i * i <= num; i = i + 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;

    return true;
}

std::vector<int> other;
void get_alignment(int n)
{
    long target = n + 1;
    while (!is_prime(target))
    {
        target += 1;
    }

    // assert(is_prime(target));

    for (int i = n; i >= 1; i--)
    {
        if (target - i <= n)
            other.push_back(target - i);
        else
        {
            get_alignment(i);
            break;
        }
    }
}

int main()
{
    int n = 61;
    std::cin >> n;

    get_alignment(n);
    std::reverse(other.begin(), other.end());
    // assert(other.size() == n);

    for (int i = 0; i < n; i++)
    {
        // assert(is_prime(other[i] + i + 1));
        std::cout << i + 1 << " ";
    }
    std::cout << '\n';
    for (auto num : other)
    {
        std::cout << num << " ";
    }
}
