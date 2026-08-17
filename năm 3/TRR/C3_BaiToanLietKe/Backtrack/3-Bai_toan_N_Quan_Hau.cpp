#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int c[101], d1[101], d2[101], n, res;
int x[101];

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!c[j] && !d1[i - j + n] && !d2[i + j - 1]){
			
			x[i] = j;
			
			c[j] = d1[i - j + n] = d2[i + j - 1] = 1;
			if(i == n){
				res++;
				for(int i = 1; i <= n; i++){
					cout << x[i] << " ";
				} 
				cout << endl;
			}
			else{
				Try(i + 1);
			}
			c[j] = d1[i - j + n] = d2[i + j - 1] = 0;
		}
	}
}

int main(){
	faster()
	cin >> n;
	res = 0;
	Try(1);
	cout << res << endl;
	return 0;
}
