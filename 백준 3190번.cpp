#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main(){
	vector<vector<pair<int, int>>> map;
	queue<pair<int, char>> tur;
	queue<pair<int, int>> sna;

	pair<int, int> head;
	head.first = 0;
	head.second = 0;
	int dx = 1;
	int dy = 0;
	int time = 0;

	int N, K, L;

	pair<int, int> temp;
	pair<int, char> temp1;

	cin >> N;
	for (int i = 0; i < N; i++){
		vector<pair<int, int>> v(N, { 0, 0 });
		map.push_back(v);
		
	}

	cin >> K;
	for (int i = 0; i < K; i++){
		cin >> temp.first >> temp.second;
		map[temp.first - 1][temp.second - 1].second = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++){
		cin >> temp1.first >> temp1.second;
		tur.push(temp1);
	}
	sna.push(head);
	map[head.first][head.second].first = 1;
	
	while (time <= 10000){
		time++;
		head.first += dy;
		head.second += dx;
		if (head.first<0 || head.second<0 || head.first>N - 1 || head.second>N - 1){
			break;
		}
		if (map[head.first][head.second].first == 1)
			break;
	
		map[head.first][head.second].first = 1;
		sna.push(head);
		if (map[head.first][head.second].second != 1){
			map[sna.front().first][sna.front().second].first = 0;
			sna.pop();
		}
		else{
			map[head.first][head.second].second = 0;
			
		}
		if (!tur.empty()&&tur.front().first == time){
			if (dx == 1&&dy==0){				
				if (tur.front().second == 'D'){
					dx = 0; dy = 1;
				}
				else{
					dx = 0; dy = -1;
				}
			}
			else if (dx == -1 && dy == 0){
				if (tur.front().second == 'D'){
					dx = 0; dy = -1;
				}
				else{
					dx = 0; dy = +1;
				}
			}
			else if (dx == 0 && dy == 1){
				if (tur.front().second == 'D'){
					dx = -1; dy = 0;
				}
				else{
					dx = +1; dy = 0;
				}
			}
			else if (dx == 0 && dy == -1){
				if (tur.front().second == 'D'){
					dx = 1; dy = 0;
				}
				else{
					dx = -1; dy = 0;
				}
			}

			tur.pop();
		}
		
	}
	cout << time;

	return 0;
	

}