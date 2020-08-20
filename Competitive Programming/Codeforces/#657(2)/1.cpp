#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

int main(){
	char sample[] = {'a','b','a','c','a','b','a'};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		string s;
		int cnt = 0;
		cin >> s;
		for(int i = 0 ; i < n - 6 ; i++){
			int ctr = 0;
			for(int j = 0 ; j < 7 ; j++)
				if( s[i + j] == sample[j] )
					ctr++;
			if( ctr == 7 )
				cnt++;
		}
		bool flag = false;
		if( cnt > 1 )
			cout << "NO" << endl;
		else{
			if( cnt == 1 ){
				cout << "YES" << endl;
				for(int i = 0 ; i < n ; i++){
					if( s[i] == '?' )
						cout << 'z';
					else
						cout << s[i];
				}
				cout << endl;
			}
			else{
				for(int i = 0 ; i < n - 6 ; i++){
					int ctr = 0;
					for(int j = 0 ; j < 7 ; j++)
						if( s[i + j] == sample[j] or s[i + j] == '?' )
							ctr++;
					if( ctr == 7 ){
						// cout << i << " " << n - 10 
						if( i < n - 10 ){
							for(int j = 7 ; j <= 10 ; j++)
								if( s[i + j] == sample[j - 4] ){
									// cout << s[i + j] << " ";
									ctr++;
								}
						}
						if( ctr == 11 )
							continue;
						ctr = 0;
						if( i < n - 12 ){
							for(int j = 7 ; j <= 12 ; j++)
								if( s[i + j] == sample[j - 6] )
									ctr++;
						}
						if( ctr == 6 )
							continue;
						flag = true;
						for(int j = 0 ; j < 7 ; j++)
							s[i + j] = sample[j];
						break;
					}
				}
				if( flag ){
					cout << "YES" << endl;
					for(int i = 0 ; i < n ; i++){
						if( s[i] == '?' )
							cout << "z";
						else
							cout << s[i];
					}
					cout << endl;
				}
				else
					cout << "NO" << endl;
			}
		}
	}
	return(0);
}