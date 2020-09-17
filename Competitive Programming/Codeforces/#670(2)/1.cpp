#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[105], ct[103], ct1[103], ct2[103];
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
		for(int i = 0 ; i <= 100 ; i++){
			ct[i] = 0;
			ct1[i] = 0;
			ct2[i] = 0;
		}
		ari;
		vector< int > aa, aaa;
		for(int i = 0 ; i < n ; i++)
			ct[a[i]]++;
		int ctr = 0, ans = 0;
		for(int i = 0 ; i <= 100 ; i++){
			if( ct[i] > 0 )
				aa.pb(i);
			if( ct[i] > 1 )
				aaa.pb(i);
		}
		for(int i = 0 ; i < aa.size() ; i++)
			ct1[aa[i]] = 1;
		for(int i = 0 ; i < aaa.size() ; i++)
			ct2[aaa[i]] = 1;
		for(int i = 0 ; i <= 100 ; i++)
			if( ct1[i] == 0 ){
				ans += i;
				break;
			}
		for(int i  = 0 ; i <= 100 ; i++)
			if( ct2[i] == 0 ){
				ans += i;
				break;
			}
		cout << ans << endl;
	}
	return(0);
}