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
		vector< string > inp(n);
		for(int i  = 0 ; i < n ; i++)
			cin >> inp[i];
		for(int i = 0 ; i < n - 2 ; i++)
			for(int j = 0 ; j < n - 2 ; j++){
				if( inp[i][j] == 'X' and (inp[i + 1][j] == 'X' and inp[i + 2][j] == 'X') and (inp[i][j + 1] == 'X' and inp[i][j + 2] == 'X'))
					inp[i][j] = 'O';
				// if( inp[i][j] == 'X' and (inp[i][j + 1] == 'X' and inp[i][j + 2] == 'X'))
				// 	inp[i][j + 1] = 'O';
			}
		for(int i = 2 ; i < n ; i++)
			for(int j = 2 ; j < n ; j++)
				if( inp[i][j] == 'X' and ((inp[i - 2][j] == 'X' and inp[i - 1][j] == 'X') or (inp[i][j - 2] == 'X' and inp[i][j - 1] == 'X')))
					inp[i][j] = 'O';

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++)
				cout << inp[i][j];
			cout << endl;
		}		
	}
	return(0);
}