#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 1e18

const int MAXN = 100010;

ll n, m, k;
vector<vector<pair<ll, ll>>> adj;
ll freq[MAXN];

vector<ll> K_shortest_paths(ll src)
{
    vector<ll> ret;
    priority_queue<pair<ll, ll>> q;
    q.push({0, src});

    while (!q.empty() && freq[n] < k)
    {
        pair<ll, ll> cur = q.top();
        q.pop();

        if (cur.second == n)
            ret.push_back(-cur.first);

        freq[cur.second]++;
        if (freq[cur.second] <= k)
        {
            for (auto child : adj[cur.second])
            {
                ll des = child.first, w = child.second;
                q.push({-(-cur.first + w), des});
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

void read()
{
    cin >> n >> m >> k;
    ll u, v, w;
    adj.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}