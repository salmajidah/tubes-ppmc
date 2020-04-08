//ini buat tubes ppmc
#include <stdio.h> 

int cols;
int rows; 

//ini fungsi untuk menghitung tetangga sel (Neighbor) 
int Neighbors (int cell[cols][rows],int x, int y) {
	int i,j,sum; 
	for (i = -1; i<2; i++) { 
		for (j = -1; j<2; j++) { 
			sum = sum + cell[x+i][y+j];
		}
	}
	sum = sum - cell[x][y]; //karena tidak menghitung dirinya sendiri
	return sum; 
} 



