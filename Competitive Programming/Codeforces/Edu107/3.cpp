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
    t = 1;
	while( t-- ){
		cin >> n >> m;
		vector< ll > index(51, 10000000);
		for(ll i = 0 ; i < n ; i++){
			cin >> a[0];	
			index[a[0]] = min(index[a[0]], i + 1);
		}
		for(int i = 0 ; i < m ; i++){
			cin >> a[0];
			cout << index[a[0]] << " ";
			for(int j = 1 ; j <= 50 ; j++)
				if(j != a[0] and index[j] < index[a[0]])
					index[j] += 1;
			index[a[0]] = 1;
		}
		cout << endl;
	}
	return(0);
}