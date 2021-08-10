
#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll  long long int
#define ld long double
#define EPS 0.00001;
#define INF 1e18
#define N 1000010

using namespace std;

ll MOD = 2147483647;

ll n, s;
ll vec[100010], com[100010];

ll ok(ll k) {

    ll mx = 0;
    ll ans;
    for (ll i = 0; i < n - k + 1; i++) {
        ans = com[i + k - 1] - com[i] + vec[i];
        mx = max(mx, ans);
    }
    return mx;
}

ll bs() {
    ll l = 0, r = n, mid = (l + r) / 2;
    while (r > l) {
        mid = (l + r) / 2;
        ll ans = ok(mid);
        if (ok(mid) >= s) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    //cout << r << " " << l << " " << mid << endl;
    return r;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    IO;
    while (cin >> n >> s) {
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            if (i == 0) com[i] = vec[i];
            else com[i] = com[i - 1] + vec[i];
        }
        ll ans = bs();
        if (ans == n && com[n - 1] < s) cout << 0 << endl;
        else if (ans == 0) cout << 1 << endl;
        else cout << ans << endl;
        for (int i = 0; i < n + 5; ++i) {
            com[i] = 0;
        }
    }

    return 0;
}