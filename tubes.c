//ini buat tubes ppmc
#include <stdio.h> 

int cols;
int rows; 

//supaya tetangga di sekitar bisa bersifat toroidal
int WrapAround (int index, int length) { 
	if (index == -1) { 
		return length - 1; 
	} 
	else if (index == length) { 
		return 0; 
	}
	else {
		return index; 
	}
}

//ini fungsi untuk menghitung tetangga sel (Neighbors) 
//x dan y adalah indeks lokasi saat itu
int Neighbors (char cell[cols][rows],int x, int y) {
	int i,j;
	int sum = 0;
	for (i = -1; i<2; i++) { 
		for (j = -1; j<2; j++) { 
			if (cell[WrapAround(x+i,cols)][WrapAround(y+j,rows)] == 'X') { 
				sum++;
			}
		}
	}
	if (cell[x][y] == 'X') { 
		sum = sum - 1; //karena tidak menghitung dirinya sendiri
	}
	return sum;
} 


