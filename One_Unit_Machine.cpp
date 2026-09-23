#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e6;
ll fact[mxN+9];

void pre_calculte_factorial ()
{
    fact[0] = 1;
    for (int i = 1; i <= mxN; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

int power (int x, int n)
{
    int ans = 1%MOD;
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

ll module_inverse (int b) 
{
    ll pow = power (b, MOD-2);
    return pow%MOD;
}

ll nCr (ll n, ll r)
{
    ll a = fact[n];
    ll b = (fact[r]*fact[n-r])%MOD;

    return (a * module_inverse (b))%MOD;
}

void solve (int tc)
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll total = 0;
    for (auto &x:v)
    {
        cin >> x;
        total += x;
    }

    ll ans = 1;

    for (int i = n-1; i >= 0; i--)
    {
        ll curr = nCr (total-1, v[i]-1);
        ans = (ans*curr)%MOD;
        total -= v[i];
    }
    cout << "Case " << tc << ": " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_calculte_factorial();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve (i);

    return 0;
}

