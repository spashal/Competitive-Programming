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
		ll ans = 0, zero = 0;
		for(int i = 0 ; i < n ; i++)
			if(a[i] <= 0){
				ans++;
				if(a[i] == 0)
					zero++;
			}
		// for(int i = 0 ; i < n ; i++)
		// 	if(a[i] == 0){
		// 		maxi = 0;
		// 		ans++;
		// 	}
		ll temp = (ll)INT_MAX * 2;
		sort(a, a + n);
		for(int i = 1 ; i < n ; i++){
			if(a[i] > 0){
				temp = min(llabs(a[i] - a[i-1]), temp);
				break;
			}
			temp = min(llabs(a[i] - a[i-1]), temp);
		}
		if(zero > 1)
			cout << ans << endl;
		else if(ans == 0)
			cout << min(n, (ll)1) << endl;
		else if(ans < n and a[ans] <= temp)
			cout << min(ans + 1, n) << endl;
		else
			cout << ans << endl;
	}
	return(0);
}