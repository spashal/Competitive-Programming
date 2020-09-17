#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ari;
    if( n == 1 )
    	cout << a[0] - 1 << endl;
    else if( n == 2 )
    	cout << min(a[0], a[1]) - 1 << endl;
    else{
    	sort(a, a + n);
    	if( n > 40 ){
    		ll ans = 0;
    		for(int i = 0 ; i < n ; i++)
    			ans += a[i] - 1;
    		cout << ans << endl;
    	}
    	else{
    		ll mini = 1e18;
    		ll max = pow((ld)1e18, (ld)1.0/(n - 1));
    		for(int i = 1 ; i <= min((ll)1e5, max) ; i++){
    			ll ans = 0;
    			vector< ll > po(n + 1, 0);
    			po[0] = 1;
    			for(int j = 1 ; j < n ; j++)
    				po[j] = po[j - 1] * i;
    			for(int j = 0 ; j < n ; j++)
    				ans += llabs(po[j] - a[j]);
    			mini = min(ans, mini);
    		}
    		cout << mini << endl;
    	}
    }
	return(0);
}