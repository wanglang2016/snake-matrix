#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;
char a[maxn][maxn];
int r,d,l,u;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int x, y;

int ok(int _x, int _y) {
	if(x < 0 || x >= n || y < 0 || y >= n) return 0;
	return 1;
}

int should_turn(int _x, int _y) {
	if(r == 1) return a[_x][_y+2] == '*';
	else if(d == 1) return a[_x+2][_y] == '*';
	else if(l == 1) return a[_x][_y-2] == '*';	
	else {
		return a[_x-2][_y] == '*';
	}
}

void next_turn_position(int & temp_x, int & temp_y) {
	if(r == 1) {
		r = 0, d = 1;
		++temp_x;
	}
	else if(d == 1) {
		d = 0, l = 1;
		--temp_y;
	}
	else if(l == 1) {
		l = 0, u = 1;
		--temp_x;
	}
	else {
		u = 0, r = 1;
		++temp_y;
	}
}

void next_straight_position() {
	if(r == 1) a[x][++y] = '*';
	else if(d == 1) a[++x][y] = '*';
	else if(l == 1) a[x][--y] = '*';
	else a[--x][y] = '*'; 
}

int done(int _x, int _y) {
	int cnt = 0;
	for(int i = 0; i < 4; i++) {
		int neigh_x = _x + dx[i];
		int neigh_y = _y + dy[i];
		if(ok(neigh_x, neigh_y) && a[neigh_x][neigh_y] == '*') {
			cnt++;
		}
	}
	return cnt > 1;	
}

void solve() {
	u = 1;
	while(1) {
		if(should_turn(x,y)) {
			int temp_x = x, temp_y = y;
			next_turn_position(temp_x, temp_y);
			if(done(temp_x, temp_y)) {
				return;				
			}
			else next_straight_position();
		}
		else {
			next_straight_position();	
		}	
	}
}
int main() {
	memset(a, 0, sizeof(a));	
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i][j] = ' ';
		}
	}
	if(n == 1) cout << "*" << endl;
	else if(n == 2) cout << "**" << endl;
	else if(n == 3) cout << "***" << endl << "  *" << endl  << "***" << endl; 
	else {
		r = d = l = u = 0;
		y = -1, x = 0;
		for(int i = 0; i < n; i++) {
			a[x][++y] = '*';
		}					
		for(int i = 1; i < n; i++) {
			a[++x][y] = '*';
		}
		for(int i = 1; i < n; i++) {
			a[x][--y] = '*';
		}
		solve();
				
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}	
	return 0;
}
