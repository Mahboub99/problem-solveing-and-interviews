#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 1e18

const int MAXN = 100010;

ll n, m;
vector<vector<pair<ll, ll>>> adj;
ll dist[MAXN], par[MAXN];
bool visited[MAXN];

void Dijkstra(ll src)
{
    for (ll i = 0; i < MAXN; i++)
        dist[i] = INF;
    memset(par, -1, sizeof(par));
    dist[src] = 0;
    visited[src] = true;
    priority_queue<pair<ll, ll>> q;
    q.push({0, src});

    while (!q.empty())
    {
        ll cur = q.top().second;
        q.pop();
        for (auto child : adj[cur])
        {
            ll des = child.first, w = child.second;

            if (!visited[des])
            {
                par[des] = cur;
                visited[des] = true;
                if (dist[cur] + w < dist[des])
                {
                    dist[des] = min(dist[des], dist[cur] + w);
                    q.push({-dist[des], des});
                }
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
    return path;
}

void read()
{
    cin >> n >> m;
    ll u, v, w;
    adj.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

int main()
{
    // just for testing
    read();
    Dijkstra(1);
    vector<ll> path = getPath(3);
    for (ll i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    for (ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
/*
     5 6
     1 2 5
     1 4 9
     1 5 1
     5 4 2
     4 3 6
     2 3 2
     */