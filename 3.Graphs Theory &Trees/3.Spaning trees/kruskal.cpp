#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int MAXN = 100100;

struct edge
{
    ll from, to, weight;
    edge(ll u, ll v, ll w) : from(u), to(v), weight(w) {}

    bool operator<(const edge &e) const
    {
        return (weight < e.weight);
    }
};

int n, m;
ll par[MAXN], siz[MAXN];
vector<edge> edges;

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

ll kruskalMST()
{
    init();
    sort(edges.begin(), edges.end());

    ll ret = 0;
    for (auto e : edges)
    {
        if (!same(e.from, e.to))
        {
            unit(e.from, e.to);
            ret += e.weight;
        }
    }
    return ret;
}
int main()
{
    cin >> n >> m;
    ll u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }
    cout << kruskalMST() << endl;
    return 0;
}
