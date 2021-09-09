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
		cin >> n;
		ari;
		ll minin = INT_MAX;
		ll maxin = 0;
		for(int i = 0 ; i < n ; i++){
			minin = min(minin, a[i]);
			maxin = max(maxin, a[i]);
		}
		ll ans = 0;
		bool one = false, two = false;
		for(int i = 0 ; i < n ; i++){
			if(maxin == a[i])
				one = true;
			if(minin == a[i])
				two = true;
			if(one and two){
				ans = i+1;
				break;
			}
		}
		one = false;
		two = false;
		for(int i = n-1 ; i >= 0 ; i--){
			if(maxin == a[i])
				one = true;
			if(minin == a[i])
				two = true;
			if(one and two){
				ans = min(ans, n-i);
				break;
			}
		}
		ll temp = 0;
		one = false;
		two = false;
		for(int i = 0 ; i < n ; i++){
			if(maxin == a[i])
				one = true;
			if(minin == a[i])
				two = true;
			if(one or two){
				temp = i+1;
				break;
			}
		}
		for(int i = n-1 ; i >= 0 ; i--){
			if(maxin == a[i] and !one)
				one = true;
			if(minin == a[i] and !two)
				two = true;
			if(one and two){
				temp += n-i;
				break;
			}
		}
		ans = min(ans, temp);
		cout << ans << endl;

	}
	return(0);
}