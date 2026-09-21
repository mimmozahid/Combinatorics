#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

ll lcm (vector<ll>& v)
{
    ll ret = v[0];
    for (int i = 1; i < (int)v.size(); i++)
    {
        ret = (v[i]*ret / __gcd (v[i], ret));
    }
    return ret;
}

ll interset (vector<ll> &v, ll n)
{
    return n/lcm (v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> x(k);
    for (auto &i : x) cin >> i;

    ll sub = 0;

    for (ll mask = 1; mask < (1<<k); mask++)
    {
        vector<ll> v;
        for (int i = 0; i < k; i++)
        {
            ll bitmask = (1LL << i);
            if (bitmask&mask)
                v.push_back (x[i]);
        }
        
        if (v.size() & 1) sub += interset (v, n);
        else sub -= interset (v, n);
    }

    cout << n-sub << endl;
    
    return 0;
}