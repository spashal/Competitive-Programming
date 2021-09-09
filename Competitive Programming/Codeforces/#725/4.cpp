#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[100005];
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
vector< ll > prime;
vector< ll > pf(100001, 0);
vector< bool > vis(100001, false);

ll hcf(ll a, ll b){
	if(b == 0)
		return a;
	return hcf(b, a%b);
}

ll factorize(ll num){
	if(num <= 100000)
		return pf[num];
	ll ans = 0;
	for(int i = 0 ; i < prime.size() ; i++){
		while(num%prime[i]==0){
			ans++;
			num/=prime[i];
			if(num <= 100000)
				return (pf[num]+ans);
		}
		if(num == 1)
			break;
	}
	return ans+1;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 2 ; i < 100001 ; i++)
    	if(!vis[i]){
    		prime.pb(i);
    		pf[i] = 1;
    		for(int j = i*2 ; j < 100001 ; j+=i){
    			ll temp = j;
    			while(temp%i==0){
    				pf[j]++;
    				temp/=i;
    			}
    			vis[j] = true;
    		}
    	}
    cin >> t;
	while( t-- ){
		ll a, b, k;
		cin >> a >> b >> k;
		ll fact1 = factorize(a);
		ll fact2 = factorize(b);
		if(k == 1){
			if(max(a, b) % min(a, b) == 0 and a != b)
				cout << "YES\n";
			else
				cout << "NO\n";
			continue;
		}
		if((fact1+fact2) < k)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return(0);
}