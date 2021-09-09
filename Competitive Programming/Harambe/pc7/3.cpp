#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < m ; i++ ) cin >> a[i];
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
		cin >> m >> n;
		vector< ll > a(m, 0);
		ari;
		vector< pair<ll, ll> > cars;
		for(int i = 0 ; i < n ; i++){
			ll u = 0;
			cin >> u;
			cars.pb(mp(u, -1));
		}
		for(int i = 0 ; i < n ; i++){
			ll u = 0;
			cin >> u;
			cars[i].ss = u;	
		}
		sort(a.begin(), a.end());
		sort(cars.begin(), cars.end());
		bool ans = true;
		vector< vector< pair<ll, ll> > > checks(m-1);
		int index = 0;
		while(index < n and cars[index].ff == a[0])
			index++;
		for(int i = 1 ; i < m ; i++){
			while(index < n and cars[index].ff < a[i] and cars[index].ff > a[i-1]){
				checks[i-1].pb(cars[index]);
				index++;
			}
			int firstPositive = -1, lastNegative = -1;
			for(int j = 0 ; j < checks[i-1].size() ; j++){
				if(checks[i-1][j].ss > 0 and firstPositive == -1)
					firstPositive = j;
				if(checks[i-1][j].ss < 0)
					lastNegative = j;
			}
			if(firstPositive > -1 and lastNegative > -1 and firstPositive < lastNegative){
				ans = false;
				break;
			}
			while(index < n and cars[index].ff == a[i])
				index++;
		}
		for(int i = 1 ; i < m ; i++){
			ld time1 = 0, time2 = 0;
			for(int j = 0 ; j < checks[i-1].size() ; j++){
				if(checks[i-1][j].ff < 0){
					if(time1 > (ld)(checks[i-1][j].ff-a[i-1])/(ld)(llabs(checks[i-1][j].ss)))
						ans = false;
					time1 = (ld)(checks[i-1][j].ff-a[i-1])/(ld)(llabs(checks[i-1][j].ss));
				}
				else if(checks[i-1][j].ff > 0){
					if(time2 < (ld)(a[i] - checks[i-1][j].ff)/(ld)(llabs(checks[i-1][j].ss)))
						ans = false;
					time2 = (ld)(a[i] - checks[i-1][j].ff)/(ld)(llabs(checks[i-1][j].ss));				
				}
			}
			if(!ans)
				break;
		}
		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return(0);
}