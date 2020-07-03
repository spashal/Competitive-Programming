#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

void fun(int i, int j){
	cout << i << " " << j + 1 << endl;
	cout << i + 1 << " " << j << endl;
	cout << i + 1 << " " << j + 1 << endl;
}
int main(){
	cin >> n;
	cout << 3 * n + 4 << endl;
	cout << "0 0\n";
	for(int i = 0 ; i < n ; i++){
		// cout << i << " " << i << endl;
		fun(i,i);
	}
	fun(n,n);
	return(0);
}