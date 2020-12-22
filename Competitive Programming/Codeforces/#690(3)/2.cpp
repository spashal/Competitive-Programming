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
		string s;
		cin >> s;
		bool flag = false;
		if( s[0] == '2' ){
			if( s[1] == '0' ){
				if( s[2] == '2' ){
					if( s[3] == '0' )
						flag = true;
					else if( s[n - 1] == '0' )
						flag = true;
				}
				else if( s[n - 2] == '2' and s[n - 1] == '0' ){
					flag = true;
				}
			}
			else if( s[n - 3] == '0' and s[n - 2] == '2' and s[n - 1] == '0' )
				flag = true;
		}
		else if( s[n - 4] == '2' and s[n - 3] == '0' and s[n - 2] == '2' and s[n - 1] == '0' )
			flag = true;
		if( flag )
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return(0);
}