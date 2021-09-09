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

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		string s;
		cin >> s;
		vector< ll > cntD(n, 0), cntK(n, 0), dp(n, 1);
		map< pair<long long int, ll>, ll > storage;
		ll ctrD = 0, ctrK = 0;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == 'D')
				ctrD++;
			else
				ctrK++;
			cntD[i] = ctrD;
			cntK[i] = ctrK;
			if(ctrD * ctrK == 0){
				if(i > 0)
					dp[i] = dp[i-1] + 1;
				else
					dp[0] = 1;
				cout << dp[i] << " ";
				continue;
			}
			int size = (i+1)/gcd(ctrK, ctrD);
			// for(int j = 1 ; (i+1) > j*size ; j++){
				int g1 = gcd(ctrD, ctrK);
				// int g2 = gcd(cntD[i-j*size], cntK[i-j*size]);
				// if(cntD[i-j*size] * cntK[i-j*size] == 0)
					// continue;
				// if(cntK[i-j*size]/g2 == ctrK/g1 and cntD[i-j*size]/g2 == ctrD/g1){
					dp[i] = ++storage[mp(ctrK/g1, ctrD/g1)];
				// }
			// }
			cout << dp[i] << " ";
		}
		cout << "\n";
	}
	return(0);
}