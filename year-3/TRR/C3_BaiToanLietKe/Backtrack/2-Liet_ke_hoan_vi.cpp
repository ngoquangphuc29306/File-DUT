#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int n, x[100];
bool used[100];

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == false){
			x[i] = j;
			used[j] = true;
			if(i == n){
				for(int i = 1; i <= n; i++){
					cout << x[i] << " ";
				}
				cout << endl;
			}
			else{
				Try(i + 1);
			}
			used[j] = false;
		}
	}
}

int main(){
	faster()
	
	return 0;
}
