#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005], k;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	string s, ans;
	while( t-- ){
		cin >> n >> k;
		cin >> s;
		sort(s.begin(), s.end());
		for(int i = 0 ; i < n ; i++)
			a[s[i] - 'a']++;
		if( s[0] == s[k - 1] ){
			vector< int > ctr;
			for(int i = 0 ; i < 26 ; i++)
				if( a[i] % k == 0 )
					ctr.push_back(i);
					
			if( !ctr.empty() and s[0] - 'a' == ctr[0] )
				for(int i = 0 ; i < n and ; i += k)
					ans.push_back(s[i]);
			else{
				int ct = 0;
				for(int i = 0 ; i < n ; i++)
					if(a[i])
						ct++;
				if( ct != 1 )
					for(int i = k - 1 ; i < n ; i++)
						ans.push_back(s[i]);
				else
					for(int i = 0 ; i < ceil((float)n/k) ; i++)
						ans.push_back(s[0]);
			}
		}
		else
			ans.push_back(s[k - 1]);
		cout << ans << endl;
		for(int i = 0 ; i < 26 ; i++)
			a[i] = 0;
		ans.clear();
		s.clear();
	}
	return(0);
}