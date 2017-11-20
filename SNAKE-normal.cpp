#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 20;
char a[maxn][maxn];
int n;
int len;
char ret[maxn*maxn];
int flag[maxn];
// ld_ru_flag == 1 means ld, ld_ru_flag == 0 means ru 
int ld_ru_flag;
int x, y;
int pos;

int ok(int t_x, int t_y) {
	if( t_x < 0 || t_x >= n || t_y < 0 || t_y >= n) return 0;
	return 1;
}

void ld() {
	while(ok(x+1,y-1)) {
		ret[pos++] = a[++x][--y];
	}		
}

void ru() {
	while(ok(x-1,y+1)) {
		ret[pos++] = a[--x][++y];
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	len = n * n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	// temp_flag == 1 means right, temp_flag == 0 means down
	int temp_flag = 1;
	for(int i = 0; i < n-1; i++) {
   		flag[i] = flag[2*(n-1)-1-i] = temp_flag;
		temp_flag = !temp_flag;
	}
	ld_ru_flag = 1;
	pos = 1;
	x = y = 0;
	ret[0] = a[0][0];
	for(int i = 0; i < 2*(n-1); i++) {
		if(flag[i] == 1) {
			ret[pos++] = a[x][++y];
		}
		else {
			ret[pos++] = a[++x][y];
		}
		if( ld_ru_flag == 1 ) {
			ld();
		}
		else {
			ru();
		}
		ld_ru_flag = !ld_ru_flag;
	}
	for(int i = 0; i < len; i++) {
		cout << ret[i];
	}
	cout << endl;
	return 0;	 
}
