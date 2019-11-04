#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[8][8]; 
int copymap[8][8];
int visited[8][8] = { 0, };
queue<pair<int, int>> q;

int N, M;

vector<pair<int, int>> v;
vector<int> c;
vector<pair<int, int>> vir;

void bfs(){

	while (!q.empty()){

		int y = q.front().first;
		int x = q.front().second;
		int dy[] = { 0, 0, 1, -1 };
		int dx[] = { 1, -1, 0, 0 };

		q.pop();

		for (int i = 0; i < 4; i++){
			if (y + dy[i] >= N || y + dy[i] < 0 || x + dx[i] >= M || x + dx[i] < 0){
				continue;
			}
			if (visited[y + dy[i]][x + dx[i]] == 0 && copymap[y + dy[i]][x + dx[i]] == 0){
				copymap[y + dy[i]][x + dx[i]] = 2;
				visited[y + dy[i]][x + dx[i]] = 1;
				q.push({ y + dy[i], x + dx[i] });
			}
		}
	}

}

int main(){
	cin >> N>> M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 0){
				v.push_back({ i, j });
			}
			if (map[i][j] == 2){
				vir.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < v.size(); i++){
		if (i < 3){
			c.push_back(1);
		}
		else
		{
			c.push_back(0);
		}
	}

	int max = 0;
	do{
		
		int count = 0;

		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				copymap[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < c.size(); i++){
			if (c[i] == 1){
				copymap[v[i].first][v[i].second] = 1;
			}
		}
		for (int i = 0; i < vir.size(); i++){
			q.push({ vir[i].first, vir[i].second });
			visited[vir[i].first][vir[i].second] = 1;
			bfs();
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (copymap[i][j] == 0){
					count++;
				}
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				visited[i][j] = 0;
			}
		}
		if (max < count)
			max = count;

	} while (prev_permutation(c.begin(), c.end()));
	
	cout << max;

}