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
ll dist[MAXN], par[MAXN];

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
        dist[i] = INF;
    dist[src] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            if (dist[e.src] + e.wight < dist[e.des])
            {
                par[e.des] = e.src;
                dist[e.des] = dist[e.src] + e.wight;
            }
        }
    }
}

vector<ll> getPath(ll des)
{
    vector<ll> path;
    path.push_back(des);
    while (par[des] != -1)
    {
        path.push_back(par[des]);
        des = par[des];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    read();
    Bellman_Ford(1);
    for (ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
