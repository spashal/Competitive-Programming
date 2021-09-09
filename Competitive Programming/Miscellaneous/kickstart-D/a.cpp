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

int temp(ll num[3][3], int x, int y, int a, int b){
	if(x+2*a > 2 or x+2*a < 0 or y + 2*b > 2 or y + 2*b < 0)
		return 0;
	if((num[x][y]+num[x+2*a][y+2*b]) == 2*(num[x+a][y+b]))
		return 1;
	return 0;
}

ll fun(ll num[3][3], ll nn){
	int ans = 0;
	num[1][1] = nn;
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < 3 ; j++){
			ans += temp(num, i, j, 0, 1);
			ans += temp(num, i, j, 1, 0);
			ans += temp(num, i, j, 1, 1);
		}
	ans += temp(num, 0, 2, 1, -1);
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int i = 1 ; i <= t ; i++){
		ll num[3][3];
		for(int j = 0 ; j < 3 ; j++)
			for(int k = 0 ; k < 3 ; k++)
				if(j != 1 or k != 1)
					cin >> num[j][k];
		ll ans = 0;
		if((num[0][0]+num[2][2])%2 == 0)
			ans = max(ans, fun(num, (num[0][0]+num[2][2])/2));
		if((num[0][1]+num[2][1])%2 == 0)
			ans = max(ans, fun(num, (num[0][1]+num[2][1])/2));
		if((num[0][2]+num[2][0])%2 == 0)
			ans = max(ans, fun(num, (num[0][2]+num[2][0])/2));
		if((num[1][0]+num[1][2])%2 == 0)
			ans = max(ans, fun(num, (num[1][0]+num[1][2])/2));
		cout << "Case #" << i << ": " << ans << endl;
	}
	return(0);
}