//20181692(정찬진)
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;		//간선 수
const int V = 6;		//정점 수

int visited[V] = { 0, };

struct MST {
	char x;
	char y;
	int cost;
};

MST mst[10];		//데이터 파일로부터 x,y,cost를 입력 받아 넣기


void visitedinit() {

	for (int i = 0; i < V; ++i) {
		visited[i] = i;
	}
}


void Inputprint() {		//Input Data를 출력

	cout << "1 . Input Data : " << endl;
	for (int i = 0; i < MAX; i+=2) {
		cout << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << "\t";
	}
	cout << endl;
	for (int i = 1; i < MAX; i += 2) {
		cout << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << "\t";
	}
	cout << endl;
	cout << endl;

}


void sorted() {

	for (int i = 0; i < MAX; ++i) {
		int min = mst[i].cost;
		int minpos = i;
		for (int j = i; j < MAX; ++j) {
			if (mst[j].cost < min) {
				min = mst[j].cost;
				minpos = j;
			}
		}
		MST temp;
		temp = mst[i];
		mst[i] = mst[minpos];
		mst[minpos] = temp;

	}
}
void sortedprint() {		//정렬된 Sorted Data를 출력
	cout << "2 . Sorted Data : " << endl;
	for (int i = 0; i < MAX; i+=2)
		cout << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << "\t";
	cout << endl;
	for (int i = 1; i < MAX; i += 2)
		cout << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << "\t";
	cout << endl;
	cout << endl;
}




void kruskal() {

	int sum = 0;	
	int a = 1;
	cout << "3 . Minimum Spanning Tree : " << endl;
	cout << endl;

	for (int i = 0; i < MAX; ++i) {
		if (visited[mst[i].x - 'A'] < visited[mst[i].y - 'A']) {
			int accept = visited[mst[i].y - 'A'];
			for (int j = 0; j < V; j++) {
				if (visited[j] == accept) {
					visited[j] = visited[mst[i].x - 'A'];
				}
			}
			sum += mst[i].cost;	

			cout << "Edge " << a++ << ": " << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << endl;	
		}
		else if (visited[mst[i].x - 'A'] > visited[mst[i].y - 'A']) {
			int accept = visited[mst[i].y - 'A'];
			for (int j = 0; j < V; j++) {
				if (visited[j] == accept) {
					visited[j] = visited[mst[i].y - 'A'];
				}
			}
			sum += mst[i].cost;

			cout << mst[i].x << " " << mst[i].cost << " " << mst[i].y << " " << endl;
			break;
		}
	}
	cout << endl;
	cout << "4 . Final cost for Kruskal is : " << sum << endl;
}

int main() {

	ifstream fin;
	fin.open("input.txt");
	for (int i = 0; i < MAX; i++)
		fin >> mst[i].x >> mst[i].cost >> mst[i].y;

	Inputprint();
	sorted();
	sortedprint();
	visitedinit();
	kruskal();
}
