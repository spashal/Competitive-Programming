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
		int min = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			if(a[min] > a[i])
				min = i;
		}
		cout << n - 1 << endl;
		for(int i = min + 1 ; i < n ; i++)
			cout << min + 1 << " " << i + 1 << " " << a[min] << " " << a[min] + i - min << endl;
		for(int i = min - 1 ; i >= 0 ; i--)
			cout << min + 1 << " " << i + 1 << " " << a[min] << " " << a[min] + min - i << endl;
	}
	return(0);
}