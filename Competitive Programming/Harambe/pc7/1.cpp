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
    cin >> t;
	while( t-- ){
		ll k;
		vector< pair<ll, ll> > ar;
		cin >> n >> m >> k;
		for(int i = 0 ; i < n ; i++){
			ll u;
			cin >> u;
			ar.pb(mp(u, i+1));
		}
		k = m;
		sort(ar.begin(), ar.end());
		int verdict = -1, index = 0;
		while(k and index < ar.size()){
			ll temp = ar[index].ff, ctr = 0;
			bool foundMe = false;
			while(index < ar.size() and ar[index].ff == temp){
				if(ar[index].ss == 1){
					foundMe = true;
				}
				index++;
				ctr++;
			}
			if(foundMe){
				if(ctr <= k){
					verdict = 2;
					break;
				}
				else{
					verdict = 1;
					break;
				}
			}
			k -= ctr;
		}
		if(verdict == -1)
			cout << "NO" << endl;
		else if(verdict == 1)
			cout << "MAYBE" << endl;
		else
			cout << "YES" << endl;
	}
	return(0);
}