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
    string steps = "RLUD";
    vector< pair< ll, ll> > step;
    step.pb(mp(1, 0));
    step.pb(mp(-1, 0));
    step.pb(mp(0, 1));
    step.pb(mp(0, -1));
	while( t-- ){
		vector< pair< ll, ll> > pos;
		string s;
		cin >> s;
		ll x = 0, y = 0, ansx = 0, ansy = 0;
		for(int i = 0 ; i < s.size() ; i++){
			for(int j = 0 ; j < 4 ; j++)
				if( s[i] == steps[j] ){
					x += step[j].ff;
					y += step[j].ss;
					pos.pb(mp(x, y));
					// cout << x << " * " << y << endl;
					break;
				}
		}
		for(int i = 0 ; i < pos.size() ; i++){
			ll fixedx = pos[i].ff;
			ll fixedy = pos[i].ss;
			x = y = 0;
			if( fixedy == 0 and fixedx == 0 )
				continue;
			for(int j = 0 ; j < s.size() ; j++){
				for(int k = 0 ; k < 4 ; k++)
					if( s[j] == steps[k] ){
						ll temp1 = x, temp2 = y;
						x += step[k].ff;
						y += step[k].ss;
						if( x == fixedx and y == fixedy ){
							x = temp1;
							y = temp2;
						}
					}
				// cout << x << " & " << y << endl;
			}
			if( x == 0 and y == 0 ){
				// cout << i << endl;
				ansx = pos[i].ff;
				ansy = pos[i].ss;
				break;
			}
		}
		cout << ansx << " " << ansy << endl;
	}
	return(0);
}