#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 20;
int n;
char a[maxn][maxn];
char ret[maxn*maxn];
int u, d, l, r;
int len;
int offset;
int pos;
int x, y;

void update() {
	if(r == 1) {
		r = 0, d = 1;
		for(int i = 0; i < offset; i++) a[++x][y] = ret[pos++];
	}				
	else if(d == 1) {
		d = 0, l = 1;
		for(int i = 0; i < offset; i++) a[x][--y] = ret[pos++];
	}
	else if(l == 1) {
		l = 0, u = 1;
		for(int i = 0; i < offset; i++) a[--x][y] = ret[pos++];
	}
	else {
		u = 0, r = 1;
		for(int i = 0; i < offset; i++) a[x][++y] = ret[pos++];
	}
}

void solve() {
	for(int i = 0; i < n; i++ ) {
		a[x][++y] = ret[pos++]; 
	}
	r = 1;
	offset = n-1;
	while(offset) {
		update();
		update();
		offset--;			
	}
}
int main() {
	freopen("in.txt","r",stdin);
	cin >> n;
	memset(a, 0, sizeof(a));	
	memset(ret, 0, sizeof(ret));	
	len = n*n;
	pos = 0;
	x = 0, y = -1;
	for(int i = 0; i < len; i++) {
		cin >> ret[i];
	}
	u = d = l = r = 0;
	solve();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}		
    return 0;
}
