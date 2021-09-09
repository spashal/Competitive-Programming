#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
		int roadToPalindrome = 0;
		for(int i = 0 ; i < n ; i++)
			if(s[i] == '0')
				roadToPalindrome++;
		
		int alice = 1, bob = 0;
		bool a = false, b = true;
		roadToPalindrome--;
		if(n%2 == 0 or (n%2 and s[(n-1)/2] == '1')){
			alice = 0;
			a = true;
			b = false;
			roadToPalindrome++;
		}
		while(roadToPalindrome){
			if(roadToPalindrome >= 2){
				if(a){
					// cout << "a " << roadToPalindrome << endl;
					alice += 2;
					a = false;
					b = true;
				}
				else{
					// cout << "b " << roadToPalindrome << endl;
					bob += 2;
					a = true;
					b = false;
				}
				roadToPalindrome -= 2;
			}
			else{
				if(a){
					alice += 1;
					a = false;
					b = true;
				}
				else{
					bob += 1;
					a = true;
					b = false;
				}
				roadToPalindrome--;
			}
		}
		if(alice > bob)
			cout << "BOB" << endl;
		else if(bob > alice)
			cout << "ALICE" << endl;
		else
			cout << "DRAW" << endl;
	}
	return(0);
}