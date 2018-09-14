#include <iostream>
#include<string>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
const char *dirs = "NESW", *turns = "FLR";
int has_edge[10][10][4][3], d[10][10][4];
int map[10][10];
int r0, c0;
int dir0;

int return_dir(char d) {
	return strchr(dirs, d) - dirs;
}

int return_turn(char t) {
	return strchr(turns, t) - turns;
}

struct Node {
	int r, c, dir;
	Node(int r = 0, int c = 0, int dir = 0) :r(r), c(c), dir(dir) {}
} start, goal, p[10][10][4];

const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };

Node walk(const Node &n, int turn) {
	int dir = n.dir;
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return Node(n.r + dr[dir], n.c + dc[dir], dir);
}

bool inside(int r, int c) {
	return bool(map[r][c]);
}

void print_ans(Node u) {
	vector<Node> path;
	while (true) {
		path.push_back(u);
		if (d[u.r][u.c][u.dir] == 0) break;
		u = p[u.r][u.c][u.dir];
	}
	path.push_back(Node(r0, c0, dir0));

	for (int i = path.size() - 1, cnt = 0; i >= 0; i--, cnt++) {
		cout << "(" << path[i].r << "," << path[i].c << ")";
		//if (cnt % 10) cout << endl;
	}
	cout << endl;




}

void solve() {
	queue<Node> q;
	q.push(start);
	memset(d, -1, sizeof(d));
	d[start.r][start.c][start.dir] = 0;
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		if (u.r == goal.r && u.c == goal.c) { print_ans(u); return; }
		for (int i = 0; i<3; i++) {
			Node v = walk(u, i);
			if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] == -1)
			{
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	cout << "No Solution" << endl;

}

int main(int argc, const char * argv[]) {
	string name;
	while (cin >> name) {
		if (name == "END") break;

		char ch_dir0;
		cin >> r0 >> c0 >> ch_dir0;
		dir0 = return_dir(ch_dir0);

		start = walk(Node(r0, c0, dir0), 0);
		cin >> goal.r >> goal.c;
		

		memset(has_edge, 0, sizeof(has_edge));
		memset(map, 0, sizeof(map));
		map[goal.r][goal.c] = 1;
		while (true) {
			int r, c;
			cin >> r;
			if (r == 0) break;
			cin >> c;
			map[r][c] = 1;

			while (true) {
				char ch[5];
				cin >> ch;
				if (ch[0] == '*') break;
				for (int i = 1; ch[i] != '\0'; i++) {
					has_edge[r][c][return_dir(ch[0])][return_turn(ch[i])] = 1;
				}
			}
		}

		cout << name << endl;
		solve();

	}
}
