#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, a[100];
int check;

void init(){
	for(int i = 1; i <= n; i++) a[i] = 0;
}

void sinh(){
	int i = n;
	while(i <= n && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0){
		check = 0;
	}
	else{
		a[i] = 1;
	}
}

int main(){
	faster()
	cin >> n;
	init();
	check = 1;
	while(check){
		for(int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
		sinh();
	}
	return 0;
}
