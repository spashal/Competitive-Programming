#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, ar[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}



int main(){
	int a, b, c;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		cin >> a >> b >> c;
		if( !ar[a] and !ar[b] and !ar[c] ){
			ar[a] = 1;
			ar[b] = 2;
			ar[c] = 3;
		}
		else if( ar[a] * ar[b] or ar[b] * ar[c] or ar[c] * ar[a] ){
			if( !ar[a] )
				ar[a] = 6 - ar[b] - ar[c];
			else if( !ar[b] )
				ar[b] = 6 - ar[a] - ar[c];
			else
				ar[c] = 6 - ar[a] - ar[b];
		}
		else{
			if( ar[a] ){
				if( ar[a] == 1 ){
					ar[b] = 2;
					ar[c] = 3;
				}
				else if( ar[a] == 2 ){
					ar[b] = 1;
					ar[c] = 3;
				}
				else{
					ar[b] = 1;
					ar[c] = 2;
				}
			}
			else if( ar[b] ){
				if( ar[b] == 1 ){
					ar[a] = 2;
					ar[c] = 3;
				}
				else if( ar[b] == 2 ){
					ar[a] = 1;
					ar[c] = 3;
				}
				else{
					ar[a] = 1;
					ar[c] = 2;
				}	
			}
			else{
				if( ar[c] == 1 ){
					ar[b] = 2;
					ar[a] = 3;
				}
				else if( ar[c] == 2 ){
					ar[b] = 1;
					ar[a] = 3;
				}
				else{
					ar[b] = 1;
					ar[a] = 2;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; i++)
		cout << ar[i] << " ";
	cout << endl;
	return(0);
}