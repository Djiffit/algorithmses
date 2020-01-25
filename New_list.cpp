#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<long> items;
long n, x;

int main()
{
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        cin >> x;
        items.push(-x);
    }

    while (items.size() > 1)
    {
        long num1 = items.top();
        items.pop();
        long num2 = items.top();
        items.pop();

        cout << abs(num1 + num2) << '\n';
        items.push(num1 + num2);
    }
}