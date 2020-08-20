#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, t;
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

void printar(vector< ll > ar, int f){
	for(int i = 0 ; i < f ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

int maxi(int a, int b){
	if( a < b )
		return b;
	return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin >> n >> k;
    vector< ll > m(n, 0), c(k, 0);
    for(int i = 0 ; i < n ; i++)
    	cin >> m[i];
    for(int i = 0 ; i < k ; i++)
    	cin >> c[i];
    ll min = n + 1;
    sort(m.begin(), m.end());
    for(int i = 0 ; i < k ; i++){
    	if( c[i] < min)
    		min = c[i];
    	else
    		c[i] = min;
    }
    vector< vector< ll > > ans(n, vector< ll > (1));
    int ms = m.size();
    int z = 0;
    for(int i = k - 1 ; i >= 0 ; i--){
    	ll s = 0;
    	while( !m.empty() and m[ms - 1] >= i + 1 ){
    		ll lim = maxi(z, ms - (c[i] - ans[s].size()));
    		for(int j = ms ; j >= lim ; j--){
    			ans[s].pb(m[j]);
    			m.pop_back();
    		}
    		ms = m.size();
    		s++;
    	}
    	t = max(t, s);
    }
    cout << t << endl;
    for(int i = 0 ; i < t ; i++){
    	for(int j = 0 ; j < ans[i].size() ; j++)
    		cout << ans[i][j] << " ";
    	cout << endl;
    }
	return(0);
}