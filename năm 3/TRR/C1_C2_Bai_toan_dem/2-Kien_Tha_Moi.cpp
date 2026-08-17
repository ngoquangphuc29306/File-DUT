#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, m;

long long C(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

long long Solve(int m, int n) {
    return C(m + n, m);
}

// Backtrack
int dem = 0;
string path;

void backtrack(int i, int j){
	if(i == m && j == n){
		cout << path << endl;
		dem++;
		return;
	}
	
	if(i + 1 <= m){
		path.push_back('D');
		backtrack(i + 1, j);
		path.pop_back();
	}
	
	if(j + 1 <= n){
		path.push_back('R');
		backtrack(i, j + 1);
		path.pop_back();
	}
}

// QHĐ
long long dp[100][100];

void solve(){
	for(int j = 0; j <= n; j++){
		dp[0][j] = 1;
	}
	for(int i = 0; i <= m; i++){
		dp[i][0] = 1;
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[m][n] << endl;
}


int main() {
    cin >> m >> n;
    cout << "So duong di: " << Solve(m, n) << endl;
    backtrack(0, 0);
    cout << dem << endl;
    solve();
    return 0;
}
