#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 2e6+9;
int fact[mxN+1];

void pre_compute_factorial ()
{
    fact[0] = 1;
    for (int i = 1; i <=mxN; i++)
    {
        fact[i] = (1LL*fact[i-1]*i)%MOD;
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

int moduler_inverse (int b)
{
    int pow = power (b, MOD-2);
    return pow%MOD;
}

int nCp (int n, int r)
{
    int a = fact[n];
    int b = (1LL*fact[r]*fact[n-r])%MOD;

    return (1LL*a*moduler_inverse(b))%MOD;
}

void solve (int tc)
{
    int n, k;
    cin >> n >> k;
    int a = n+k-1;
    int b = k-1;
    cout << "Case " << tc << ": " << nCp (a, b) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_compute_factorial();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve (i);

    return 0;
}

