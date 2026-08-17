#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

// x1 + x2 + x3 = 15, x1 >= 0, x2 >= 0, x3 >= 0

int x[4];

void Try(int i){
	if(i == 3){
		x[3] = 15 - x[1] - x[2];
		if(x[3] >= 0){
			cout << x[1] << " " << x[2] << " " << x[3] << endl;
		}
		return;
	}
	for(int j = 0; j <= 15; j++){
		x[i] = j;
		if(x[1] + x[2] <= 15){
			Try(i + 1);
		}
	}
}

int main(){
	faster()
	Try(1);
	return 0;
}
