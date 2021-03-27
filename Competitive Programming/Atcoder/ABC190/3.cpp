#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[1005], b[1005], c[17], d[17];
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
    t = 1;
    while( t-- ){
		ll k, ans = 0;
		cin >> n >> m;
		vector< ll > adj[101];
		for(int i = 0 ; i < m ; i++){
			cin >> a[i] >> b[i];
		}
		cin >> k;
		for(int i = 0 ; i < k ; i++)
			cin >> c[i] >> d[i];
		for(int mask = 0 ; mask < (1 << k) ; mask++){
			vector< ll > temp(n + 1, 0);
			for(int j = 0 ; j < k ; j++)
				if(mask & (1 << j))
					temp[c[j]]++;
				else
					temp[d[j]]++;
			ll anst = 0;
			for(int j = 0 ; j < m ; j++){
				if(temp[a[j]] and temp[b[j]])
					anst++;
			}
			ans = max(anst, ans);
		}
		cout << ans << endl;
			
	}
	return(0);
}