#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 998244353;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 2000;
ll fact[mxN+9];

void pre_compute_factorial ()
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

ll moduler_inverse (ll n)
{
    ll pow = power (n, MOD-2);
    return pow % MOD;
}

ll nCr (ll n, ll r)
{
    ll a = fact[n];
    ll b = (fact[r] * fact[n-r])%MOD;

    return (a * moduler_inverse (b))%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    pre_compute_factorial();
    
    ll n, m, k;
    cin >> n >> m >> k;

    cout << 1LL * ((nCr (n-1, k) * m)%MOD * power (m-1, k))%MOD << endl;
    
    return 0;
}