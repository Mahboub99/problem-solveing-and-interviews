#include <bits/stdc++.h>

#define ll long long int

using namespace std;

const int MAXN = 100100;
vector<vector<pair<ll, ll>>> adj; // first -> to , second -> weight
int n, m;
bool visited[MAXN];
ll primeMST(ll src)
{
    for (int i = 0; i < n; i++)
        visited[i] = false;
    priority_queue<pair<ll, ll>> q;
    q.push({0, src});

    ll ret = 0;

    while (!q.empty())
    {
        ll cur = q.top().second;
        ll w = -q.top().first;
        q.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        ret += w;

        for (auto child : adj[cur])
        {
            if (!visited[child.first])
            {
                q.push({-child.second, child.first});
            }
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    ll u, v, w;
    adj.resize(n + 2);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << primeMST(1) << endl;

    return 0;
}
