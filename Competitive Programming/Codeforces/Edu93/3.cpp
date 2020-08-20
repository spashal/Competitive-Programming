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
		stack< pair<ll, ll> > stk;
		vector< ll > ctr(n, 0);
		ll ans = 0, last = 0, catchup = 0;
		for(int i = 0 ; i < s.size() ; i++){
			if( s[i] == '1' ){
				if( i > 0 ){
					ctr[i] = ctr[i - 1] + 1;
					ctr[i - 1] = 0;
				}
				else
					ctr[0] = 1;
			}
			else if( s[i] == '0' ){
				catchup++;
				if( !stk.empty() and stk.top().ff == catchup + 1 ){
					if( stk.top().ss > 0 ){
						ctr[i] = ctr[stk.top().ss - 1] + 1;
						ctr[stk.top().ss - 1] = 0;
					}
					else
						ctr[i] = 1;
					catchup = 0;
					stk.pop();
				}
			}
			else{
				stk.push(mp(s[i] - '0', i));
			}
		}
		for(int i = 0 ; i < s.size() ; i++)
			ans += ((ctr[i] + 1) * ctr[i]) / 2;
		cout << ans << endl;
	}
	return(0);
}