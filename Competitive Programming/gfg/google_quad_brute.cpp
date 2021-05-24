#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	while(t--){
		int n, kk;
		cin >> n >> kk;
		vector< int > inp(n);
		for(int i = 0 ; i < n ; i++)
			cin >> inp[i];
		sort(inp.begin(), inp.end());
		vector< vector< int > > ans;
		for(int i = 0 ; i < n ; i++)
			for(int j = i + 1 ; j < n ; j++)
				for(int k = j + 1 ; k < n ; k++)
					for(int l = k + 1 ; l < n ; l++)
						if(inp[i] + inp[j] + inp[k] + inp[l] == kk){
							vector< int > temp;
							temp.push_back(inp[i]);
							temp.push_back(inp[j]);
							temp.push_back(inp[k]);
							temp.push_back(inp[l]);
							bool same = true;
							for(int )
						}
	}
	return 0;
}