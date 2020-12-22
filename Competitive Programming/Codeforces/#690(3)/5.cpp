#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll m, t, a[200005], nr[200005];
vector< ll > adj[100005];
ll mod = 1e9 + 7;
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

ll modex(ll k){
	ll temp1 = 1, temp3 = k, temp2 = mod - 2;
	while( temp2 ){
		if( temp2 % 2 )
			temp1 = (temp1 * temp3) % mod;
		temp2 /= 2;
		temp3 = (temp3 * temp3) % mod;
	}
	return temp1;
}

ll ncr(ll n){
	if( m == 1 )
		return 1;
	// cout << n << "*";
	if( n < m - 1 )
		return 0;
	if( n == m - 1 )
		return 1;
	else if( nr[n] != -1 )
		return nr[n];
	else{
		nr[n] = (((ncr(n - 1) * n) % mod) * modex(n - m + 1)) % mod;
	}
	return nr[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    // for(int i = 0 ; i < 2e5 + 1 ; i++)
    // 	nr[i] = -1;
	while( t-- ){
		ll n;
		ll k;
		// m = 3;
		cin >> n >> m >> k;
		ari;
		for(int i = 0 ; i <= n ; i++)
			nr[i] = -1;
		nr[m - 1] = 1;
		sort(a, a + n);
		set< ll > st;
		vector< vector< ll > > maap(n + 1, vector< ll > (2, -1));
		for(int i = 0 ; i < n ; i++){
			if( maap[a[i]][0] == -1 ){
				maap[a[i]][0] = i;
				maap[a[i]][1] = i;
			}
			else
				maap[a[i]][1] = i;
			st.insert(a[i]);
		}
		ll ans = 0;
		for(int i = 0 ; i < n - m + 1 ; i++){
			set< ll > :: iterator find = st.upper_bound(a[i] + k);
			ll index = maap[*find][0] - 1;
			if( find == st.end() )
				index = n - 1;
			if( index > i )
				ans = (ans + ncr(index - i)) % mod;
			else
				ans = (ans + ncr(maap[a[i]][1] - i)) % mod;
			// cout << "haha"<< ans<< endl;
		}
		cout << ans << endl;
	}
	return(0);
}