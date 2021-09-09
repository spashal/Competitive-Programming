#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
		cin >> n >> k;
		vector<ll> a(n, 0), b;
		ari;
		b = a;
		map<ll,ll> place;
		sort(b.begin(), b.end());
		for(int i = 0 ; i < n ; i++){
			place[b[i]] = i;
		}
		int count = 1;
		ll last = 0;
		for(int i = 1 ; i < n ; i++){
			if(place[a[i]] - 1 != place[a[i-1]])
				count++;
		}
		if(count <= k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return(0);
}