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
		string s;
		cin >> s;
		if( s[0] == 'R' ){
			if( s[1] == 'S' )
				cout << "1" << endl;
			else if( s[2] == 'S' )
				cout << "2" << endl;
			else
				cout << "3" << endl;
		}
		else if( s[1] == 'R' ){
			if( s[2] == 'R' )
				cout << "2" << endl;
			else
				cout << "1" << endl;
		}
		else if( s[2] == 'R' )
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	return(0);
}