#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[100005];
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

int calc(int a, int b){
	if(a <= 1 or b <= 1)
		return 0;
	return (min(max(a, b), 2*min(a, b))/2 + min(a, b)/2)-2;
}

void print(vector<vector<int> > ar){
	int m = ar.size(), n = ar[0].size();
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++)
			cout << ar[i][j] << " ";
		cout << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int i = 1 ; i <= t ; i++){
		int r, c;
		cin >> r >> c;
		vector<vector<int> > matrix(r, vector<int> (c, 0));
		vector<vector<int> > histx1(r, vector<int> (c, 0));
		vector<vector<int> > histx2(r, vector<int> (c, 0));
		vector<vector<int> > histy1(r, vector<int> (c, 0));
		vector<vector<int> > histy2(r, vector<int> (c, 0));
		for(int j = 0 ; j < r ; j++)
			for(int k = 0 ; k < c ; k++)
				cin >> matrix[j][k];
		for(int j = 0 ; j < r ; j++){
			histy1[j][0] = matrix[j][0];
			for(int k = 1 ; k < c ; k++){
				if(matrix[j][k] == 1)
					histy1[j][k] = histy1[j][k-1]+1;
			}
			histy2[j][c-1] = matrix[j][c-1];
			for(int k = c-2 ; k >= 0 ; k--)
				if(matrix[j][k] == 1)
					histy2[j][k] = histy2[j][k+1]+1;
		}
		for(int k = 0 ; k < c ; k++){
			histx1[0][k] = matrix[0][k];
			histx2[r-1][k] = matrix[r-1][k];
			for(int j = 1 ; j < r ; j++)
				if(matrix[j][k] == 1)
					histx1[j][k] = histx1[j-1][k]+1;
			for(int j = r-2 ; j >= 0 ; j--)
				if(matrix[j][k] == 1)
					histx2[j][k] = histx2[j+1][k]+1;
		}
		int ans = 0;
		for(int j = 0 ; j < r ; j++)
			for(int k = 0 ; k < c ; k++){
				ans += calc(histy1[j][k], histx1[j][k]);
				ans += calc(histx1[j][k], histy2[j][k]);
				ans += calc(histy1[j][k], histx2[j][k]);
				ans += calc(histx2[j][k], histy2[j][k]);
			}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return(0);
}