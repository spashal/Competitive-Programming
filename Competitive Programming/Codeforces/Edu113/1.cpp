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
		string s;
		cin >> s;
		int l = -1, r = -1;
		for(int i = 0 ; i < n ; i++){
			int temp = i, count = INT_MIN;
			while(count != 0 and temp < n){
				if(count == INT_MIN)
					count = 0;
				if(s[temp] == 'a')
					count++;
				else
					count--;
				temp++;
			}
			if(count == 0){
				l = i+1;
				r = temp;
				// cout << i << "haha" << endl;
			}
		}
		cout << l << " " << r << endl;
	}
	return(0);
}