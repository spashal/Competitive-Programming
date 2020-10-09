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
    t = 1;
	while( t-- ){
		cin >> n;
		ari;
		map< ll, bool > sums;
		vector< ll > s;
		ll ans = 0, ctr = 0;
		for(int i = 0 ; i < n ; i++){
			ans += a[i];
			if( sums[ans] or ans == 0 ){
				ctr++;
				sums[ans] = false;
				ans = 0;
				for(int j = 0 ; j < s.size() ; j++)
					sums[s[j]] = false;
				s.clear();
				i--;
			}
			else{
				sums[ans] = true;
				s.pb(ans);
			}
		}
		cout << ctr << "\n";
	}
	return(0);
}