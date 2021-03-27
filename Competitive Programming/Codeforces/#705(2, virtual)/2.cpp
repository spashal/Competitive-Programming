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
    vector< ll > valid(10, -1);
    valid[0] = 0;
    valid[1] = 1;
    valid[2] = 5;
    valid[5] = 2;
    valid[8] = 8;
	while( t-- ){
		string s;
		cin >> n >> m;
		cin >> s;
		// cout << s << " haha " << endl;
		ll h = (s[0] - '0') * 10 + s[1] - '0';
		ll mn = (s[3] - '0') * 10 + s[4] - '0';
		// cout << h << " " << mn << endl;
		bool found = false;
		string ans;
		ll min = mn;
		for(int hr = h ; found == false and hr < n ; hr++){
			for(; found == false and min < m ; min++){
				// cout << hr << " * " <<
				if(valid[hr/10] > -1 and valid[hr%10] > -1 and valid[min/10] > -1 and valid[min%10] > -1 ){
					if(valid[hr/10] + valid[hr%10] * 10 < m and valid[min/10] + valid[min%10] * 10 < n){

						found = true;
						ans.pb(hr/10 + '0');
						ans.pb(hr%10 + '0');
						ans.pb(':');
						ans.pb(min/10 + '0');
						ans.pb(min%10 + '0');
					}
				}
			}
			if(min == m)
				min = 0;
		}
		if( found )
			cout << ans << endl;
		else
			cout << "00:00\n";
	}
	return(0);
}