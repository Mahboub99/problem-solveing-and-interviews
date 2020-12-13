#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 1e18

const int MAXN = 100010;

ll n, m;
vector<vector<ll>> adj;
ll dist[MAXN];
bool visited[MAXN];

void bfs(ll src)
{
    for (ll i = 0; i < MAXN; i++)
        dist[i] = INF;
    dist[src] = 0;
    visited[src] = true;
    queue<ll> q;
    q.push(src);
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for (auto child : adj[cur])
        {
            if (!visited[child])
            {
                visited[child] = true;
                dist[child] = dist[cur] + 1;
                q.push(child);
            }
        }
    }
}

void read()
{
    cin >> n >> m;
    ll u, v;
    adj.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main()
{
    read();
    bfs(1);
    for (ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
}