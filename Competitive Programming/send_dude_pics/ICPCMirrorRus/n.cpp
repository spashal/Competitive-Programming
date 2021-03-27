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
		ll a1, a2, a3, a4, a5, c1, c2, c3, o1, o2, o3;
		cin >> c1 >> c2 >> c3;
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
		int flag = true;
		if( a1 > c1 or a2 > c2 or a3 > c3 )
			flag = false;
		o1 = a1;
		if( c3 < a3 + max((ll)0, (a4 - c1 + a1)) + max((ll)0, (a2 + a5 - c2)))
			flag = false;
		if( flag )
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return(0);
}