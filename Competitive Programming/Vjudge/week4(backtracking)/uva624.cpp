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
	ll k, ans = 0;
	cin >> k >> n;
    ari;
    vector< ll > final;
    for(int i = 0 ; i < (1 << n) ; i++){
    	vector< ll > temp;
    	ll cur = 0;
    	for(int j = 0 ; j < n ; j++)
    		if( i & (1 << j) ){
    			cur += a[j];
    			temp.pb(a[j]);
    		}
    	if( k - ans > k - cur and k >= cur ){
    		ans = cur;
    		final = temp;
    	}
    }
    for(int i = 0 ; i < final.size() ; i++)
    	cout << final[i] << " ";
    cout << "sum:" << ans << endl;
	return(0);
}