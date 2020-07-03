#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, k, m, t, a[105], val[55], b[27], b2[27], reval[55];
bool inc[55];
string s;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < m ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> s;
		cin >> m;
		ari;
		int now = 1, length = 0;
		vector< int > ar;
		for(int i = 0 ; i < m ; i++){
			if( a[i] == 0 ){
				val[i]= 1;
				inc[i] = true;
				ar.push_back(i);
				length++;
			}
		}
		while( length < m ){
			now++;
			for(int i = 0 ; i < m ; i++){
				if( !inc[i] ){
					val[i] = 0;
					for(int j = 0 ; j < ar.size() ; j++)
						val[i] += llabs(ar[j] - i);
				}
			}
			for(int i = 0 ; i < m ; i++){
				if( !inc[i] ){
					if( a[i] == val[i] ){
						val[i] = now;
						ar.push_back(i);
						length++;
						inc[i] = true;
					}	
				}
			}
		}
		for(int i = 0 ; i < m ; i++)
			reval[i] = val[i];
		// cout << endl;
		sort(s.begin(), s.end());
		sort(val, val + m);
		string ans;
		for( int i = 0 ; i < m ; i++ ){
			inc[i] = false;
			b[val[i]-1]++;
		}
		for(int i = 0 ; i < s.size() ; i++){
			b2[s[i]-'a']++;
		}
		priority_queue< pair< ll, char> > final;
		priority_queue< pair< ll, ll> > finally;
		for(int i = 0 ; i < 26 ; i++ ){
			if( b[i] )
				finally.push( make_pair(26-i, b[i]));
			if( b2[i] )
				final.push( make_pair('a' + i, b2[i]));
		}
		while( !finally.empty() ){
			if( final.top().second >= finally.top().second ){
				int temp = b[26-finally.top().first];
				while( temp-- )
					ans.push_back( final.top().first);
				finally.pop();
			}
			final.pop();
		}
		string fin;
		vector< pair< ll, ll> > arr;
		for(int i = 0 ; i < m ; i++){
			arr.push_back( make_pair(reval[i], i));
			fin.push_back('a');
		}
		sort(arr.begin(), arr.end());
		sort(ans.begin(), ans.end(), greater< char >());
		for(int i = 0 ; i < m ; i++){
			fin[arr[i].second] = ans[i];
		}
		for(int i = 0 ; i < 27 ; i++){
			b2[i] = 0;
			b[i] = 0;
			// reval[i]
		}
		for(int i = 0 ; i < m ; i++)
			cout << fin[i];
		cout << endl;
		s.clear();
	}
	return(0);
}