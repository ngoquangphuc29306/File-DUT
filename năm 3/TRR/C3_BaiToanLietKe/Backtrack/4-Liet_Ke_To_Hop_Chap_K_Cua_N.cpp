#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, k;
int x[100];

void Try(int i){
	for(int j = x[i - 1] + 1; j <= n - k + i; j++){
		x[i] = j;
		if(i == k){
			for(int i = 1; i <= k; i++){
				cout << x[i] << " ";
			}
			cout << endl;
		}
		else{
			Try(i + 1);
		}
	}
}

int main(){
	faster()
	cin >> n >> k;
	Try(1);
	return 0;
}
