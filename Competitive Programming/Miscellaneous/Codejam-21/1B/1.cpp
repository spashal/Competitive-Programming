#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
ll mod = (36*12*1e11);
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
    
	for(int i = 1 ; i <= t ; i++){
		ll inp[3] = {0, 0, 0};
		bool found = false;
		cin >> inp[0] >> inp[1] >> inp[2];
		for(int j = 0 ; j < 6 ; j++){
			ll h = inp[0], m = inp[1], s = inp[2];
			for(int k = 0 ; k < 720 ; k++){
				if((s + k) % 720 == 0 and (m + k) % 12 == 0){
					for(ll l = k ; l < mod ; l += 720){
							h = (h + l) % mod;
							ll hr = h / (36*1e11);
							h %= (ll)(36*1e11);
							ll min = (h/(6*1e10));
							h %= (ll)(6*1e10);
							ll sec = h / 1e9;
							h %= (ll)1e9;
							if( hr < 12 and min < 60 and sec < 60 and min == (m + l)/12 and sec == (s+l)/720){
								cout << k << "**" << h << "**" << l << endl;
								cout << "Case #" << i << ": " << hr << " " << min << " " << sec << " " << h << endl;
								found = true;
							}
							if(found)
								break;
						}
				}
				if(found)
					break;
			}
			if(found)
				break;

			next_permutation(inp, inp + 3);
		}
	}
	return(0);
}