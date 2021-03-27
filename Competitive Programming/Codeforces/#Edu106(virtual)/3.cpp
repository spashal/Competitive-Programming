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
		cin >> m;
		vector< ll > ans(m, 0);
		vector< vector< ll > > options(m);
		for(int i = 0 ; i < m ; i++){
			ll num, temp;
			cin >> num;
			for(int j = 0 ; j < num ; j++){
				cin >> temp;
				options[i].pb(temp);
				ans[i] = temp;
			}
		}
		vector< ll > cnt(n + 1, 0);
		for(int i = 0 ; i < m ; i++)
			cnt[ans[i]]++;
		for(int i = 0 ; i <= n ; i++){
			if(cnt[i] > ceil((float)m/2)){
				for(int j = 0 ; j < m ; j++)
					if(ans[j] == i and cnt[i] > ceil((float)m/2)){
						if(options[j].size() > 1){
							if(options[j][0] != i){
								ans[j] = options[j][0];
								cnt[i]--;
								cnt[options[j][0]]++;
							}
							else{
								ans[j] = options[j][1];
								cnt[i]--;
								cnt[options[j][1]]++;
							}
						}
					}
			}
		}
		bool found = true;
		for(int i = 0 ; i <= n ; i++)
			if(cnt[i] > ceil((float)m/2))
				found = false;
		if(found){
			cout << "YES\n";
			for(int i = 0 ; i < m ; i++)
				cout << ans[i] << " ";
			cout << endl;
		}
		else
			cout << "NO\n";
	}
	return(0);
}