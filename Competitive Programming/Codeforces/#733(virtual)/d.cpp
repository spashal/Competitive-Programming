#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
		ari;
		vector<bool> taken(n+1, false);
		vector<int> seating(n, 0);
		int ctr = 0, left = 0;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(!taken[a[i]]){
				// cout << i << " " << a[i] << endl;
				seating[i] = a[i];
				taken[a[i]] = true;
				ctr++;
				ans++;
			}
			else
				left = i;
		}
		// for(int i = 0 ; i < n ; i++)
		// 	cout << seating[i] << " ";
		// cout << endl;
		if(ctr == n-1){
			for(int i = 1 ; i <= n ; i++)
				if(!taken[i]){
					if(i == left+1){
						seating[i-1] = a[i-1];
						for(int j = 0 ; j < n ; j++)
							if(seating[j] == a[i-1]){
								seating[j] = i;
								break;
							}
						break;
					}
					else{
						seating[left] = i;
						break;
					}
				}
		}
		else{
			int l = n-1;
			int bad = 0;
			for(int i = 1 ; i <= n ; i++)
				if(!taken[i]){
					for(; l >= 0 ; l--)
						if(seating[l] == 0){
							// cout << i << " * " << l << endl;
							taken[i] = true;
							seating[l] = i;
							if(i == l+1)
								bad = i;
							l--;
							break;
						}
				}
			if(bad){
				ans--;
				for(int i = 0 ; i < n ; i++)
					if(a[i] != seating[i] and i+1 != bad){
						seating[bad-1] = seating[i];
						seating[i] = bad;
						break;
					}
			}
		}
		ans = 0;
		for(int i = 0 ; i < n ; i++)
			if(seating[i] == a[i])
				ans++;
		cout << ans << endl;
		for(int i = 0 ; i < n ; i++)
			cout << seating[i] << " ";
		cout << endl;
	}
	return(0);
}