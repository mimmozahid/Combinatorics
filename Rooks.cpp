#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

ll nCk (int n, int r)
{
    if (r > n) return 0;
    ll ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n-i) / (i+1);
    }
    return ans;
}

void solve (int tc)
{
    ll n, k;
    cin >> n >> k;
    ll k_factor = 1;
    for (int i = 1; i <= k; i++)
    {
        k_factor *= i;
    }
    
    cout << "Case " << tc << ": " << nCk (n,k)*nCk (n,k)*k_factor << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve (i);
    }

    return 0;
}

