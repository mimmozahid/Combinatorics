#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1000003;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e6+9;
ll fact[mxN+7];

void pre_calculate_factorial ()
{
    fact[0] = 1;
    for (int i = 1; i <= mxN; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

ll power (ll x, ll n)
{
    ll ans = 1%MOD;
    while (n)
    {
        if (n & 1)
        {
            ans = (1LL * ans%MOD * x%MOD);
        }
        x = 1LL * x * x % MOD;
        n>>=1;
    }
    return ans;
}

ll moduler_inverse (ll b)
{
    ll pow = power (b, MOD-2);
    return pow%MOD;
}

ll nCr (ll n, ll r)
{
    ll a = fact[n];
    ll b = (fact[r]*fact[n-r])%MOD;

    return (a*moduler_inverse(b))%MOD;
}

void solve (int tc)
{
    ll n, r;
    cin >> n >> r;

    cout << "Case " << tc << ": " << nCr (n, r) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_calculate_factorial ();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve (i);

    return 0;
}

