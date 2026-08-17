#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, a[100], ok;

void init(){
	for(int i = 1; i <= n; i++) a[i] = i;
}

void sinh(){
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]){
		i--;
	}
	if(i == 0) ok = 0;
	else{
		int j = n;
		while(a[i] > a[j]) j--;
		
		// swap(a[i], a[k])
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		
		// reverse(a + i + 1, a + n + 1)
		int l = i + 1, r = n;
		while(l < r){
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			l++; r--;
		}
		
	}
}

int main(){
	faster()
	cin >> n;
	init();
	ok = 1;
	int cnt = 0;
	
	while(ok){
		cnt++;
		for(int i = 1;i <= n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		sinh();
	}
	cout << cnt;
	return 0;
}
