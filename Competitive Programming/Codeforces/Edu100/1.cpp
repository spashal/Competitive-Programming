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
		cin >> n;ari;
		vector< ll > a1, a2;
		ll ans1 = 0, ans2 = 0;
		for(int i = 0 ; i < n ; i++){
			if( i % 2 == 0 ){
				a1.pb(1);
				a2.pb(a[i]);
			}
			else{
				a1.pb(a[i]);
				a2.pb(1);
			}
				ans1 += llabs(a1[i] - a[i]);
				ans2 += llabs(a2[i] - a[i]);
		}
		for(int i = 0 ; i < n ; i++)
			if( ans1 > ans2 )
				cout << a2[i] << " ";
			else
				cout << a1[i] << " ";
		cout << endl;
	}
	return(0);
}