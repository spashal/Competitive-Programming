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
		cin >> n;
		vector< int > a(n), b(n);
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		int temp = 0;
		sort(b.begin(), b.end(), greater< int > ());
		for(int i = 0 ; i < n ; i++){
			if( a[i] == b[i] )
				temp++;
		}
		int flag = 0;
		for(int i = 0 ; i < n ; i++){
			if( i > 0 and b[i] == b[i - 1] ){
				temp--;
			}
		}
		if( temp == n )
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return(0);
}