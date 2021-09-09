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
		string s;
		cin >> s;
		ll one = 0, zero = 0, ans = 0;
		if(s[0] == '?'){
			one++;
			zero++;
		}
		else if(s[0] == '0')
			zero++;
		else
			one++;
		for(int i = 1 ; i < s.size() ; i++){
			if(s[i] == s[i-1]){
				if(s[i] == '?'){
					zero++;
					one++;
					continue;
				}
				ans += (one * (one+1))/2;
				ans += (zero * (zero+1))/2;
				zero = one = 0;
				if(s[i] == '1')
					one++;
				else
					zero++;
			}
			else if(s[i-1] == '?' and s[i] == '0'){
				if(zero > one){	
					if(zero%2 == 0){
						zero++;
						// ans += (one*(one+1))/2;
						one = 0;
					}
					else{
						one++;
						ans += one;
						one = 0;
						ans += (zero*(zero+1))/2;
						zero = 0;
					}
				}
				else{
					if(one % 2 != 0){
						one++;
						// ans += (zero*(zero+1))/2;
						zero = 0;
					}
					else{
						zero++;
						ans += zero;
						zero = 0;
						ans += (one*(one+1))/2;
						one = 0;
					}
				}
			}
			else if(s[i-1] == '?'){
				if(one > zero){
					if(one % 2 == 0){
						one++;
						// ans += (zero*(zero+1))/2;
						zero = 0;
					}
					else{
						zero++;
						ans += zero;
						zero = 0;
						ans += (one*(one+1))/2;
						one = 0;
					}
				}
				else{
					if(zero%2 != 0){
						zero++;
						// ans += (one*(one+1))/2;
						one = 0;
					}
					else{
						one++;
						ans += one;
						one = 0;
						ans += (zero*(zero+1))/2;
						zero = 0;
					}
				}
			}
			else{
				if(s[i] == '?'){
					one++;
					zero++;
					cout << one << " " << zero << endl;
					continue;
				}
				if(one)
					one++;
				else
					zero++;
			}
			cout << one << " " << zero << " " << ans << endl;
		}
		if(one <= zero)
			one = 0;
		else
			zero = 0;
		ans += (one*(one+1))/2;
		ans += (zero*(zero+1))/2;
		cout << ans << endl;
	}
	return(0);
}