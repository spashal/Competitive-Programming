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
		bool found = false;
		for(int i = 0 ; i <= s.size() ; i++){
			int last = -2;
			bool thisNoUse = false;
			// cout << 
			for(int j = 0 ; j < i ; j++)
				if( s[j] == '1' ){
					if( j - last >= 2 ){
						// cout << j << " ";
						last = j;
					}
					else{
						thisNoUse = true;
						break;
					}
				}
			if(thisNoUse)
				break;
			for(int j = i ; j < s.size() ; j++){
				if( s[j] == '0' ){
					if(j - last >= 2 )
						last = j;
					else{
						thisNoUse = true;
						break;
					}
				}
			}
			if(!thisNoUse)
				found = true;
		}
		if(found)
			cout << "Yes\n";
		else{
			int firstone = s.size();
			int lastzero = -1;
			for(int i = 0 ; i < s.size() ; i++){
				if(s[i] == '1' and firstone == s.size())
					firstone = i;
				if(s[i] == '0')
					lastzero = i;
			}
			if(lastzero < firstone)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	return(0);
}