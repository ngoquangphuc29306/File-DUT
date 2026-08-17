#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, k, a[100], ok;
void ktao(){
	for(int i = 1; i <= k; i++) a[i] = i;
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + i){
		i--;
	}
	if(i == 0) ok = 0;
	else{
		a[i]++;
		for(int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
		}
	}
}

int main(){
	faster()
	cin >> n >> k;
	ktao();
	ok = 1;
	int cnt = 0;
	
	while(ok){
		cnt++;
		for(int i = 1; i <= k; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		sinh();
	}
	cout << cnt;
	return 0;
}
