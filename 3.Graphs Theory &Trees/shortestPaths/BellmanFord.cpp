#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 1e18

const int MAXN = 100010;

struct edge
{
    ll src, des, wight;
    edge(ll u, ll v, ll w) : src(u), des(v), wight(w){};
};

ll n, m;
vector<edge> edges;
ll dest[MAXN];

void read()
{
    cin >> n >> m;
    ll u, v, w;
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge e(u, v, w);
        edge d(v, u, w);

        edges.push_back(e);
        edges.push_back(d);
    }
}
void Bellman_Ford(ll src)
{
    for (ll i = 0; i < MAXN; i++)
        dest[i] = INF;
    dest[src] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            dest[e.des] = min(dest[e.des], dest[e.src] + e.wight);
        }
    }
}
int main()
{
    read();
    Bellman_Ford(1);
    for (ll i = 1; i <= n; i++)
        cout << dest[i] << " ";
}
