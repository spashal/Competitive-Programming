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
		ari;
		int ctr = 0;
		for(int i = 0 ; i < n ; i++)
			if(a[i] == 1)
				ctr++;
		if(ctr == n){
			cout << n+1 << " ";
			for(int i = 1 ; i < n+1 ; i++)
				cout << i << " ";
			cout << endl;
		}
		else{
			if(a[n-1] == 0){
				for(int i = 1 ; i <= n+1 ; i++)
					cout << i << " ";
				cout << endl;
			}
			else{
				int node = 0;
				for(int i = 0 ; i < n-1 ; i++)
					if(a[i] == 0 and a[i+1] == 1)
						node = i;
				for(int i = 1 ; i <= n ; i++){
					cout << i << " ";
					if(i-1 == node)
						cout << n+1 << " ";
				}
				cout << endl;
			}
		}
	}
	return(0);
}