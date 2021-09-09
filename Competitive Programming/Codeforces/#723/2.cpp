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
    map< int, int> pre;
    for(int i = 0 ; i <= 100 ; i++)
    	pre[(i*11)%100] = i;
    cin >> t;
	while( t-- ){
		cin >> n;
		bool no = false;
		if(pre[n%100]*11 <= n){
			ll temp = n/100;
			if(temp > pre[n%100] and temp < 11){
				no = true;
			}
		}
		else
			no = true;
		if(no)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return(0);
}