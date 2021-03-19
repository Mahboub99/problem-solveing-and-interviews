#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int MAXN = 100100;

int n, m;
ll par[MAXN], siz[MAXN];

// zero based
void init()
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        siz[i] = 1;
    }
}

ll find(ll x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}
bool same(ll a, ll b)
{
    return find(a) == find(b);
}

bool unit(ll a, ll b)
{
    a = find(a);
    b = find(b);

    if (siz[b] > siz[a])
        swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
}

int main()
{

    cout << endl;
    cin >> n >> m;
    init();
    ll u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        unit(u, v);
    }
    for (int i = 0; i < n; i++)
    {
        cout << find(i) << " ";
    }

    return 0;
}