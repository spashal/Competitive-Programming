#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

int main(){
	cin >> t;
	while( t-- ){
		ll r, c;
		vector< string > a;
		cin >> r >> c;
		for(int i = 0 ; i < r ; i++){
			string s;
			cin >> s;
			a.pb(s);
		}
		ll one = 0, two = 0, three = 0, two2 = 0, four = 0;
		for(int i = 0 ; i < r ; i++){
			ll ctr = 0;
			for(int j = 0 ; j < c ; j++)
				if( a[i][j] == 'A' )
					ctr++;
			if( ctr == c ){
				two++;
				if( i == 0 or i == r - 1 )
					one++;
			}
		}
		for(int i = 0 ; i < c ; i++){
			ll ctr = 0;
			for(int j = 0 ; j < r ; j++)
				if( a[j][i] == 'A' )
					ctr++;
			if( ctr == r ){
				two++;
				if( i == 0 or i == c - 1 )
					one++;
			}
		}
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				if( a[i][j] == 'A' ){
					four++;
					if( i == 0 or i == r - 1 or j == 0 or j == c - 1 ){
						three++;
						if( (i == 0 and j == 0) or (i == 0 and j == c - 1) or (i == r - 1 and j == 0) or (i == r - 1 and j == c - 1) )
							two2++;
					}
				}
			}
			a[i].clear();
		}
		if( two == r + c )
			cout << "0" << endl;
		else if( one )
			cout << "1" << endl;
		else if( two + two2 )
			cout << "2" << endl;
		else if( three )
			cout << "3" << endl;
		else if( four )
			cout << "4" << endl;
		else
			cout << "MORTAL" << endl;
	}
	return(0);
}