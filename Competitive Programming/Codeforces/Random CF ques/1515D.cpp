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
		ll l, r;
		cin >> n >> l >> r;
		vector< ll > L(n + 1, 0), R(n + 1, 0);
		for(int i = 0 ; i < l ; i++){
			ll u;
			cin >> u;
			L[u]++;
		}
		for(int i = 0 ; i < r ; i++){
			ll u;
			cin >> u;
			R[u]++;
		}
		ll ans = 0, remainingL = 0, remainingR = 0, LL = 0, RR = 0;
		for(int i = 1 ; i <= n ; i++){
			ans += llabs(L[i]-R[i])/2;
			if(llabs(L[i]-R[i])>0){
				if(L[i] > R[i])
					remainingL+= L[i]-R[i];
				else
					remainingR+= R[i] - L[i];
			}
			if(llabs(L[i]-R[i])%2){
				if(L[i] > R[i])
					LL++;
				else
					RR++;
			}
		}
		if(remainingL != remainingR)
			cout << ans + max(LL, RR) << endl;
		else
			cout << remainingL << endl;
	}
	return(0);
}