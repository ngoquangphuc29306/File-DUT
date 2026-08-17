#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

long long gt(int n){
	if(n == 0) return 1;
	return n * gt(n - 1);
}

long long solve(int n){
	long long sum = gt(n);
	long long canhNhau = 2 * gt(n - 1);
	
	return tong - canhNhau;
}

int main(){
	faster()

	return 0;
}
