/*
	Nama    : Muhamad Fahrul Azimi
	NPM     : 140810180027
	Kelas   : A
	Tanggal : 2 Maret 2020
*/

#include <iostream>
using namespace std;


const int N = 5;
string Nama_Pria[N] = {"Victor","Wyatt","Xavier","Yancey","Zeus"};
string Nama_Wanita[N] = {"Amy","Bertha","Clare","Diane","Erika"};

int Pria_preference[N][N] = {
	{1, 0, 3, 4, 2},
	{3, 1, 0, 2, 4},
	{1, 4, 2, 3, 0},
	{0, 3, 2, 1, 4},
	{1, 3, 0, 4, 2},
};
int Wanita_preference[N][N] = {
	{4, 0, 1, 3, 2},
	{2, 1, 3, 0, 4},
	{1, 2, 3, 4, 0},
	{0, 4, 3, 2, 1},
	{3, 1, 4, 2, 0},
};

int stable[N][2];
bool Pria_match[N];
bool Wanita_match[N];

int getPriaMatch(int wanita){
	for (int i=0; i<N; i++){
		if (stable[i][1]==wanita){
		return stable[i][0];
		break;
		}
	}
	return -1;
}

int getPreferenceLevel(int wanita, int pria){
	for (int i=0; i<N; i++){
		if (Wanita_preference[wanita][i]==pria){
			return i;
			break;
		}
	}
	return -1;
}

void matchingProcess(int M, int W){
	stable[M][0] = M;
	stable[M][1] = W;
	Pria_match[M] = true;
	Wanita_match[W] = true;
}

void traversalMatch(){
	cout << "===== Hasil =====\n";
	for (int i=0;i<N;i++){
		if (i!=0) {
			cout << "\n";
		}
		cout << "(" << Nama_Pria[stable[i][0]] << ","<<Nama_Wanita[stable[i][1]] << ")";
	}
}

int main(){
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int M = j;
			if (Pria_match[M]==false) {
				int W = Pria_preference[M][i];
				if (Wanita_match[W]==true){
					int xM = getPriaMatch(W);
					int xM_prep = getPreferenceLevel(W,xM);
					int M_prep = getPreferenceLevel(W,M);
					if (M_prep<xM_prep){
						matchingProcess(M,W);
						Pria_match[xM] = false;
						stable[xM][1] = -1;
						continue;
					} else {
						continue;
					}
				} else {
				matchingProcess(M,W);
				continue;
				}
			} else {
				continue;
			}
		}
	}
	traversalMatch();
}
