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
		if(m == 3){
			if(n%3 == 0){
				cout << n/3 << " " << n/3 << " " << n/3 << endl;
			}
			else if(n%2 == 1){
				cout << "1 " << n/2 << " " << n/2 << endl;
			}
			else if(n % 4 == 0)
				cout << n/2 << " " << n/4 << " " << n/4 << endl;
			else
				cout << "2 " << (n-2)/2 << " " << (n-2)/2 << endl;
			continue;
 		}
		if(m%2 == n%2){
			for(int i = 0 ; i < m - 2; i++)
				cout << "1 ";
			cout << (n-(m-2))/2 << " " << (n-(m-2))/2 << endl; 
		}
		else{
			if(((n-m+1)/2) %2 == 1){
				if(m == 4){
					if((n-1)%4 == 0){
						cout << "1 " << (n-1)/2 << " " << (n-1)/4 << " " << n/4 << endl;
						continue;
					}
					cout << "1 " << n/3 << " " << n/3 << " " << n/3 << endl;
					continue;
				}
				for(int i = 0 ; i < m - 5 ; i++)
					cout << "1 ";
				cout << "2 2 ";
				cout << "2 " << (n-(m+1))/2 << " " << (n-(m+1))/2 << endl;
				continue;
			}
			for(int i = 0 ; i < m - 3 ; i++)
				cout << "1 ";
			cout << "2 " << (n-(m-1))/2 << " " << (n-(m-1))/2 << endl;
		}
	}
	return(0);
}