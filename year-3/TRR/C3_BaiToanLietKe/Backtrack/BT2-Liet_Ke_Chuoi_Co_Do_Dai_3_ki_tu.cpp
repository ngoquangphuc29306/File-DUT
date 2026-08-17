#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

/*
x = {a, b, c}
y = {d, e}
z = {m, n, t}
*/

char s[4];

void Try(int i) {
    if(i == 1) {
        for(char c : {'a', 'b', 'c'}) {
            s[i] = c;
            Try(i + 1);
        }
    }
    else if(i == 2) {
        for(char c : {'d', 'e'}) {
            s[i] = c;
            Try(i + 1);
        }
    }
    else if(i == 3) {
        for(char c : {'m', 'n', 't'}) {
            s[i] = c;
            Try(i + 1);
        }
    }
    else {
        for(int j = 1; j <= 3; j++) {
            cout << s[j];
        }
        cout << '\n';
    }
}

// Sinh

vector<vector<char>> mien = {
	{'a', 'b', 'c'},
	{'d', 'e'},
	{'m', 'n', 't'}
};

int index[10];
int n = 3;
bool check = true;

void init(){
	for(int i = 0; i < n; i++){
		index[i] = 0;
	}
}

void sinh(){
	int i = n - 1;
	
	while(i >= 0 && index[i] == (int)mien[i].size() - 1){
		index[i] = 0;
		i--;
	}
	
	if(i < 0){
		check = false;
	}
	else{
		index[i]++;
	}
}

int main(){
	faster()
	
	init();
	while(check){
		for(int i = 0; i < n; i++){
			cout << mien[i][index[i]];
		}
		cout << endl;
		sinh();
	}
}
