#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector< pair< int, pair< int, int > > > sums; 
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = 0 ; i < n ; i++)
            for(int j = i + 1 ; j < n ; j++){
                sums.push_back(make_pair(arr[i] + arr[j], make_pair(i, j)));
            }
        sort(sums.begin(), sums.end());
        vector< int > sums2;
        for(int i = 0 ; i < sums.size() ; i++)
            sums2.push_back(sums[i].first);
        vector< int >::iterator found;
        vector< vector< int > > ans;
        for(int i = 0 ; i < sums.size() - 1 ; i++){
            found = upper_bound(sums2.begin() + i + 1, sums2.end(), k - sums2[i]);
            int index = (int)(found - sums2.begin());
            if(sums2[index] != k - sums2[i])
                index--;
            while(i < index and sums2[index] == k - sums2[i] and sums[i].second.second < sums[index].second.first){
                vector< int > temp;
                temp.push_back(arr[sums[i].second.first]);
                temp.push_back(arr[sums[i].second.second]);
                temp.push_back(arr[sums[index].second.first]);
                temp.push_back(arr[sums[index].second.second]);
                bool same = true;
                if(ans.size() > 0)
                    for(int j = 0 ; j < 4 ; j++)
                        if(ans[ans.size() - 1][j] != temp[j])
                            same = false;
                if(!same or ans.size() == 0)
                    ans.push_back(temp);
                index--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector< int > a(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector< vector< int > > ans = ob.fourSum(a, k);
        for (int i = 0 ; i < ans.size() ; i++) {
            for (int j = 0 ; j < ans[i].size() ; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;        
        }
        cout << '\n';
    }
    return 0;
}