#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, univctr = 0, a[100005];
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
vector< int > sam(3, 0);
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

void checkmat(vector< vector< bool > > mat, vector< ll > ans){
	bool flag = false;
	for(int i = 0 ; i < 8 ; i++)
		for(int j = 0 ; j < 8 ; j++)
			if( !mat[i][j] )
				flag = true;
	if( !flag ){
		univctr++;
		cout << setw(2)      // : gives a minimum width for the next output operation
            << setfill(' ')  // : sets the padding character
            << setiosflags(ios::right);
		cout << univctr;
		cout << "     ";
		for(int i = 0 ; i < 8 ; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}

void setmat(int x, int y, vector< vector< bool > > &mat){
	for(int i = 1 ; i < 8 ; i++)
		for(int j = 0 ; j < 3 ; j++)
			for(int k = 0 ; k < 3 ; k++)
				if( x + i * sam[j] < 8 and x + i * sam[j] >= 0 and
					y + i * sam[k] < 8 and y + i * sam[k] >= 0 )
					mat[x + i * sam[j]][y + i * sam[k]] = true;
}

void rec(int x, int y, vector< vector< bool > > mat, vector< ll > ans){
	if( x == 7 ){
		setmat(x, y, mat);
		ans[x] = y + 1;
		checkmat(mat, ans);
		return;
	}
	ans[x] = y + 1;
	setmat(x, y, mat);
	int nxt = x + 1;
	while( nxt < 8 and ans[nxt] != 0 )
		nxt++;
	if( nxt == 8 )
		checkmat(mat, ans);
	else
		for(int i = 0 ; i < 8 ; i++)
			if( !mat[nxt][i] )
				rec(nxt, i, mat, ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    sam[1] = -1;
    sam[2] = 1;
    ll a, b;
    bool flag = false, flg = false;
    vector< vector< bool > > inp(8, vector< bool > (8, false));
    vector< ll > ans(8, 0);
    for(int i = 0 ; i < n ; i++){
    	cin >> a >> b;
    	ans[a - 1] = b;
    	a--;
    	b--;
    	if( inp[a][b] )
    		flg = true;
    	setmat(a, b, inp);
    }
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl;
        cout << endl;
    if( flg )
    	return (0);
    int nxt = 0;
    while( nxt < 8 and ans[nxt] != 0 )
    	nxt++;
    if( nxt == 8 )
    	checkmat(inp, ans);
    else
	   	for(int i = 0 ; i < 8 ; i++){
   			if( !inp[nxt][i] )
   				rec(nxt, i, inp, ans);
   		}

	return(0);
}