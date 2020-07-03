#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[300005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> n;
	ari;
	sort(a, a + n);
	freopen("A.txt", "w", stdout);
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << " ";
	cout << endl;
	fclose(stdout);
	return(0);
}