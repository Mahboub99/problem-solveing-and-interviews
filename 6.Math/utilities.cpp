#include <bits/stdc++.h>

#include <utility>

#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long int
#define ld long double
#define EPS 0.00001;
#define INF 1e9
#define N 1000010

using namespace std;
const int MAXN = 1000010;

ll MOD = 2147483647;

ll prime[10000000];
ll fac[N], ifac[N];
ll inv[N];
vector<ll> primes;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool IsPrime(ll x)
{
    if (x == 1)
        return true;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

ll powMod(ll base, ll pw)
{
    ll ret = 1;
    while (pw)
    {
        if (pw & 1)
            ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        pw >>= 1;
    }
    return ret;
}

void makeFact()
{
    fac[0] = ifac[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
        ifac[i] = powMod(fac[i], MOD - 2);
    }
}

ll C(ll a, ll b)
{
    if (a < b)
        return 0;
    return (((fac[a] * ifac[b]) % MOD) * ifac[a - b]) % MOD;
}

ll nCr(ll n, ll k)
{

    if (k > n / 2)
        k = n - k;
    ll ret = 1;
    for (ll i = 0; i < k; i++)
    {
        ret *= (n - i);
        ret /= (i + 1);
    }
    return ret;
}

void seive(ll n)
{
    prime[0] = prime[1] = 1;
    for (ll i = 2; i * i <= n; i++)
        if (!prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= 1e6; j += i)
                prime[j] = 1;
        }
}

ll fact(ll n)
{
    ll ret = 1;
    for (ll i = 1; i <= n; i++)
    {
        ret *= i;
    }
    return ret;
}

// prime factorization even for large number 1e18
// vector{prime , power} , total numbers powers

pair<vector<pair<ll, ll>>, ll> factorize(ll n) {
    ll count = 0;
    ll total = 0;
    vector<pair<ll, ll>> vec;
    while (!(n % 2)) {
        n >>= 1;
        count++;
    }

    if (count) {
        vec.emplace_back(2, count);
        total += count;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count) {
            vec.emplace_back(i, count);
            total += count;
        }
    }

    if (n > 2) {
        vec.emplace_back(n, 1);
        total++;
    }
    return {vec, total};
}
// loop for all diagonals in matrix
/*
 * for( int k = 0 ; k <= WIDTH + HEIGHT - 2; k++ ) {
        for( int j = 0 ; j <= k ; j++ ) {
            int i = k - j;
            if( i < HEIGHT && j < WIDTH ) {
                System.out.print( array[i][j] + " " );
            }
        }
        System.out.println();
    }
 * */

int main()
{

    return 0;
}