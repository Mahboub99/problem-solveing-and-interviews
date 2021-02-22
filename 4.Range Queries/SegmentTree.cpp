#include <bits\stdc++.h>

using namespace std;

#define ll long long int
const int MAXN = 2 * (1 << 20); // first power of 2 after 1e6 as max n we should make the size is power of 2 and the tree is 2*szie

ll n; // actual size of the array
ll tree[MAXN];

// zero indexing used
void update(ll pos, ll val)
{
    pos += n;
    tree[pos] = val;
    for (pos /= 2; pos >= 1; pos /= 2)
    {
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }
}
// zero based is used
ll sum(ll a, ll b)
{
    a += n, b += n;
    ll ans = 0;
    while (a <= b)
    {
        if (a % 2 == 1) // if a is not a first child (dose not belong to range)
            ans += tree[a++];
        if (b % 2 == 0) // if b is not a first child (dose not belong to range)
            ans += tree[b--];

        a /= 2, b /= 2;
    }
    return ans;
}
int main()
{
    cin >> n;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        update(i, x);
    }
    update(3, 5);
    cout << sum(3, 4) << endl;
    cout << tree[1] << endl;
    return 0;
}