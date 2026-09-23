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

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        int a = i;

        while (a)
        {
            cnt++;
            a/=10;
        }
        if (cnt&1)
        {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}