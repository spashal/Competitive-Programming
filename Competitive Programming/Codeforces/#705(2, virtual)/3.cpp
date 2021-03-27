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
		cin >> n >> m;
		string s;
		cin >> s;
		bool found = false;
		ll need = 0;
		vector< ll > ctr(26, 0);

		for(int i = 0 ; i < n ; i++){
			ctr[s[i] - 'a']++;
		}

		for(int i = 0 ; i < 26 ; i++)
			ctr[i] = (m - ctr[i] % m) % m;

		bool already = false;
		for(int i = 0 ; i < 26 ; i++)
			if(ctr[i])
				already = true;
		if(!already){
			cout << s << endl;
			continue;
		}
		already = false;
		if( (n % m) > 0 ){
			cout << "-1\n";
			continue;
		}

		for(int i = n - 1 ; i >= 0 ; i--){

			ctr[s[i] - 'a'] = ((ctr[s[i] - 'a'] + 1)) % m;
			need = 0;
			for(int j = 0 ; j < 26 ; j++)
				need += ctr[j];

			for(int j = (s[i] - 'a' + 1) ; j < 26 ; j++){
				ll tmpneed = need;

				if( ctr[j] == 0 )
					tmpneed += m - 1;
				else
					tmpneed -= 1;

				if((n - i - 1 - tmpneed) % m == 0 and (n - i - 1) >= tmpneed ){
					
					for(int r = 0 ; r < i ; r++)
						cout << s[r];
					cout << (char)(j + 'a');

					for(int r = 0 ; r < (n - i - 1 - tmpneed) ; r++)
						cout << "a";

					for(int r = 0 ; r < 26 ; r++){
						for(int w = 0 ; w < ctr[r] ; w++){
							if(r == j and w == 0)
								continue;
							cout << (char)(r + 'a');
						}
						if(r == j and ctr[j] == 0)
							for(int ss = 0 ; ss < m - 1 ; ss++)
								cout << (char)(r + 'a');
						
					}
					cout << endl;

					found = true;
					break;
				}
			}
			if(found)
				break;
		}
		if(!found)	
			cout << "-1\n";			
	}
	return(0);
}