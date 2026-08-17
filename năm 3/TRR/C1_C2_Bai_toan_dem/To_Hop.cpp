#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

//Cach 1
ll gt(int n){
	ll res = 1;
	for(int i = 1; i <= n; i++){
		//code
		res *= i;
	}
	return res;
}

ll gt2(ll n){
	if(n == 1) return 1;
	return n * gt2(n - 1);
}

ll tohop(int n, int k){
	ll tu = gt(n);
	ll mau1 = gt(k);
	ll mau2 = gt(n - k);
	return tu / (mau1 * mau2);
}

//Cach 2: C(n, k) = (n - k + 1)/k * C(n, k - 1)
ll tohop2(int n, int k){
	if(k < 0 || k > n){
		return 0;
	}
	k = min(k, n - k); // Cong thuc doi xung : C(n, k) = C(n, n - k)
	ll res = 1;
	for(int i = 1; i <= k; i++){
		res = res * (n - i + 1) / i;
	}
	return res;
}

//Cach 3: de quy: C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
ll C(int n, int k){
	if(k == 0 || k == n) return 1;
	return C(n - 1, k - 1) + C(n - 1, k);
}

//To hop lap
ll C_lap(int n, int k){
	return C(n + k - 1, n - 1);
}

int main(){
	faster()
	cout << tohop(7, 2) << endl;
	cout << tohop2(7, 2) << endl;
	return 0;
}
