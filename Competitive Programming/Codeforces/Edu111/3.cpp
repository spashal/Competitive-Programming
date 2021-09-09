#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
		int ans = 0;
		ans = n + n-1;
		for(int i = 0 ; i < n-2 ; i++){
			if(max(a[i], max(a[i+1], a[i+2])) != max(a[i], a[i+2]))
				ans++;
			else if(min(a[i], min(a[i+1], a[i+2])) != min(a[i], a[i+2]))
				ans++;
		}
		for(int i = 0 ; i < n-3 ; i++){
			if(a[i] < a[i+1] and a[i+2] < a[i] and a[i+3] > a[i+2] and a[i+3] < a[i+1])
				ans++;
			else if(a[i] > a[i+1] and a[i+2] > a[i] and a[i+3] < a[i+2] and a[i+3] > a[i+1])
				ans++;
		}		
		cout << ans << endl;
	}
	return(0);
}