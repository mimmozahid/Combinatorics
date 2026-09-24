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

void pre_calculate_factoral ()
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

ll moduler_inverse (ll b)
{
    ll pow = power (b, MOD-2);
    return pow%MOD;
}

ll nCr (ll n, ll r)
{
    ll a = fact[n];
    ll b = (fact[r]*fact[n-r])%MOD;

    return (a* moduler_inverse(b))%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre_calculate_factoral();
    
    ll n;
    cin >> n;

    ll a = n/3, ans = 0;

    for (int i = 1; i <= a; i++)
    {
        ll p = n-(2*i)-1;
        ll k = i-1;

        ans =  (ans + nCr(p, k))%MOD;
    }
    


    cout << ans << endl;
    
    return 0;
}