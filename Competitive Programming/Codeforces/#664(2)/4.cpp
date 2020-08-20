#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, d;
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
    vector< ll > lesser, more;
    cin >> n >> d >> m;
   	for(int i = 0 ; i < n ; i++){
   		ll x;
   		cin >> x;
   		if( x <= m )
   			lesser.pb(x);
   		else
   			more.pb(x);
   	}
   	sort(lesser.begin(), lesser.end(), greater< ll > ());
   	sort(more.begin(), more.end(), greater< ll > ());
   	ll a = lesser.size();
   	ll b = more.size();
   	for(int i = 1 ; i < a ; i++)
   		lesser[i] += lesser[i - 1];
   	for(int i = 1 ; i < b ; i++)
   		more[i] += more[i - 1];
   	ll left;
   	ll k = (b + d) / (d + 1);
   	left = d + 1 - (b - 1) % (d + 1);
   	if( k >= 1 )
   		k--;
   	ll ans;
   	if( a and b )
	   	ans = lesser[a - 1] + more[k];
	else if(a)
		ans = lesser[a - 1];
	else
		ans = more[k];
   	a--;
   	
   	while( a + 1 >= left and k + 1 < b ){
   		a -= left;
   		if( a >= 0 )
	  		ans = max(ans, lesser[a] + more[++k]);
	  	else
	  		ans = max(ans, more[++k]);
  		left = d + 1;
   	}
   	cout << ans << endl;
	return(0);
}