#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
using namespace std;

deque<int> path;
int N,i,j,sumOfAdj;
vector<vector<bool>> mat;
vector<bool> visited(N);

bool cekSq(int n){
	//kalau n bil kuadrat, outputkan TRUE
	double x = sqrt(n);
	return (!(x - floor(x)));
}

bool tetangga(int a, int b){
	return ((mat[a][b]) || (mat[b][a]));
}

void printPath(int v){
	if(path.size() == N){
	cout << "KETEMU!:\n";	
	//print semuanya karena kita sudah dapat
		while(path.size()){
			cout << path.front() << " ";
			path.pop_front();
		}
		cout << endl;
		return;	//selesai
	}
	for(int i = 1; i <= N; i++){
		if((!visited[i-1]) && (tetangga(i-1, v-1)) && (i != v)){
			visited[i-1] = true;
			path.push_back(i);
			printPath(i);	//periksa masih mengarah ke solusi apa nggak
			//backtracking
			visited[i-1] = false;
			if (!path.empty()) path.pop_back();
		}
	}	
}

int main(){
	cout << "Masukan N:\n";
	cin >> N;	
	//inisialisasi
	mat.resize(N);
	for(i = 0; i < N; i++){
		mat[i].resize(N);
	}
	//bilangannya dioffset 1 -> 0, 2 -> 1, dst..
	//lalu bangun matriks ketetanggaannya
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			sumOfAdj = i+j+2;
		  mat[i][j] = cekSq(sumOfAdj);
		}
	}
	visited.resize(N);
	for(i = 0; i < N; i++){
		path.clear();
		visited.assign(N,false);
		visited[i] = true;	//start dari i
		path.push_back(i+1);
		printPath(i+1);
	}
	return 0;
}
