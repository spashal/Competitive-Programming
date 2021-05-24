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
	for(int i = 1 ; i <= t ; i++){
		cin >> n >> m;
		vector< ll > num(n, 0);
		for(int j = 1 ; j <= n ; j++)
			num[j - 1] = j;
		if(m < n - 1 or m > (n * (n + 1)) / 2 - 1)
			cout << "Case #" << i << ": IMPOSSIBLE\n";
		else{
			ll temp = m - n + 1;
			ll cur = n - 1;
			ll iteration = 0;
			while(temp){
				if(temp < cur)
					break;
				temp -= cur;
				cur--;
				iteration++;
			}
			ll last = temp;
			last++;
			// cout << last << " " << iteration << endl;
			for(int k = n - last ; k <= n - last + (last - 1) / 2 ; k++){
				ll temp = num[k];
				num[k] = num[2*n - 1 - last - k];
				num[2*n - 1 - last - k] = temp;
			}
			for(int j = iteration - 1 ; j >= 0 ; j--){
				for(int k = j ; k < j + (n - j) / 2 ; k++){
					ll temp = num[k];
					num[k] = num[n + j - 1 - k];
					num[n + j - 1 - k] = temp;
				}
			}
			cout << "Case #" << i << ": ";
			for(int j = 0 ; j < n ; j++)
				cout << num[j] << " ";
			cout << endl;
		}
	}
	return(0);
}