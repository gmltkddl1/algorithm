#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> c[15];
int money;
int maxmoney = 0;



int main(){

	int numzero=0;

	

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> c[i].first >> c[i].second;
	}
	while (numzero <= N){
		vector<int> v;
		
		for (int i = 0; i < N; i++){
			if (i < numzero)
				v.push_back(1);
			else
				v.push_back(0);
		}

		do{
			int ct[15] = { 0, };
			bool vaild = true;
			money = 0;

			for (int i = 0; i < N; i++){
				if (v[i] == 1){
					
					for (int j = 0; j < c[i].first; j++){
						if (ct[i + j] == 0&&i+j<N){
							ct[i + j] = 1;
						}
						else{
							vaild = false;
							break;
						}

					}
					money += c[i].second;
				}
				if (vaild == false){
					money = 0;
					break;
				}
				
			}

			if (maxmoney < money)
				maxmoney = money;
		} while (prev_permutation(v.begin(), v.end()));

		numzero++;
	}
	cout << maxmoney;
	return 0;
}