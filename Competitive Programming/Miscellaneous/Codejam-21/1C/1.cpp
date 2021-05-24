#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, k, m, t, a[100005];
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
	
ld fun(ld a, ld b){
	ld nk = (int)(a + b)/2;
	ld ans = (ld)((int)((int)a - nk - 1)/2)/(ld)k + (ld)(((int)nk - 1 - (int)b)/2)/(ld)k + (ld)1/(ld)k;
	if(nk - 1 > b){
		nk -= 1;
		ans = max(ans, (ld)((int)((int)a - nk - 1)/2)/(ld)k + (ld)((int)(nk - 1 - (int)b)/2)/(ld)k + (ld)1/(ld)k);
		nk += 1;
		
	}
	nk += 1;
	if(nk < a){
		ans = max(ans, (ld)((int)((int)a - nk - 1)/2)/(ld)k + (ld)((int)(nk - 1 - (int)b)/2)/(ld)k+ (ld)1/(ld)k);
	}
	return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int i = 1 ; i <= t ; i++){
		cin >> n >> k;
		vector< ld > inp(n);
		for(int j = 0 ; j < n ; j++)
			cin >> inp[j];
		vector< pair< ld, ld > > newNos;
		sort(inp.begin(), inp.end());
		for(int j = -1 ; j < n ; j++){
			if(j == -1 and inp[j+1] > 1){
				newNos.pb(mp((ld)((int)inp[j+1] - 1)/(ld)k, inp[j+1] - 1));
			}
			else if(j == n - 1 and inp[j] < k){
				newNos.pb(mp((ld)(k - (int)inp[j])/(ld)k, inp[j]+1));
			}
			else if(j < n - 1 and inp[j] < inp[j+1]-1){
				int newnum = (inp[j+1] + inp[j]) / 2;
				newNos.pb(mp(fun(inp[j+1], inp[j]), (ld)newnum));
			}
		}
		sort(newNos.begin(), newNos.end());

		cout << "Case #" << i << ": ";
		if(newNos.size() == 0)
			cout << setprecision(6)<< "0.0000000" << endl;
		else if(newNos.size() < 2)
			cout << setprecision(6)<< newNos[0].ff << endl;
		else
			cout << setprecision(6)<< newNos[newNos.size() - 1].ff + newNos[newNos.size()-2].ff << endl;
	}
	return(0);
}