#include <bits\stdc++.h>
#define ll long long int
using namespace std;

const int MAXN = 10010;
ll tree[MAXN];
ll n;

void add(ll pos, ll val)
{
    while (pos <= MAXN)
    {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}
ll sum(ll pos)
{
    ll sum = 0;
    while (pos)
    {
        sum += tree[pos];
        pos -= (pos & -pos);
    }
    return sum;
}
int main()
{
    cin >> n;
    ll x;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x;
        add(x, i);
    }
    cout << sum(5) << endl;
    return 0;
}
