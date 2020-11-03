#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
int ctr[200005];
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
		for(int i = 0 ; i < n ; i++)
			ctr[i] = 0;
		int p1 = 0, p2 = 0, ans = 0;
		while( p1 < n ){
			ans++;
			while( p1 < n and p2 < n ){
				if( s[p1] == s[p2] or ctr[p2] )
					p2++;
				else{
					ctr[p2] = 1;
					break;
				}
			}
			char temp = s[p1];
			while( p1 < n ){
				if( s[p1] == temp or ctr[p1] )
					p1++;
				else
					break;
			}
			if( p2 == n )
				p2 = p1;
			// cout << p1 << " " << p2 << endl;
		}
		cout << ans << endl;
	}
	return(0);
}