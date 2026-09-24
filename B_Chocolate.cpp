#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (x) v.push_back (i);
    }

    if (v.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = 1;

    for (int i = 0; i < (int)v.size()-1; i++)
    {
        ans *= v[i+1]-v[i];
    }
    cout << ans << endl;
    
    return 0;
}