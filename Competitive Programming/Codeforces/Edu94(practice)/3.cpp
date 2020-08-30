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
		ll x;
		string s;
		cin >> s;
		cin >> x;
		n = s.size();
		vector< bool > zero(s.size(), false);
		vector< char > w(s.size(), '1');
		for(int i = 0 ; i < s.size() ; i++){
			if( s[i] == '0' and i >= x )
				w[i - x] = '0';
			if( s[i] == '0' and i + x < n )
				w[i + x] = '0';
		}
		string temp(s.size(), '0');
		for(int i = 0 ; i < s.size() ; i++)
			if( i >= x and w[i - x] == '1' )
				temp[i] = '1';
			else if( i + x < n and w[i + x] == '1' )
				temp[i] = '1';
		if( s == temp ){
			for(int i = 0 ; i < s.size() ; i++)
				cout << w[i];
			cout << endl;
		}
		else
			cout << "-1" << endl;
	}
	return(0);
}