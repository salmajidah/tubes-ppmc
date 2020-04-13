#include <stdio.h> 
#include <time.h>
#include <string.h>
#include <stdlib.h>
int rows; 
int cols;
const NMAX=50;

//membaca input file eksternal
void inputseed(char (*seed)[NMAX][NMAX]){
	char c, *file;
	file = (char*)malloc(sizeof(char));
	int i,j;
	FILE *fp;
	printf("Input File: ");
	gets(file);
	fp=fopen(file,"r");

	fscanf(fp,"%d", &rows);
	fscanf(fp,"%d", &cols);

	fgetc(fp);
	for (i=0; i<rows; i++){
		for (j=0; j<=cols; j++){
			c = fgetc(fp);
			if (c!='\n'){			
				(*seed)[i][j]=c;
			}
		}
	}
	
	free(file);
	fclose(fp);
	return ;
}


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
int Neighbors (char cell[NMAX][NMAX],int x, int y) {
	int i,j;
	int sum = 0;
	for (i = -1; i<2; i++) { 
		for (j = -1; j<2; j++) { 
			if (cell[WrapAround(x+i,rows)][WrapAround(y+j,cols)] == 'X') { 
				sum++;
			}
		}
	}
	if (cell[x][y] == 'X') { 
		sum = sum - 1; //karena tidak menghitung dirinya sendiri
	}
	return sum;
}

//Mengganti array sebelum dengan array sesudah sesuai dengan keadaannya, mati atau hidup
//ini kodenya belum ku coba, tapi ku kepikirannya kayak gini, jadi langsung mainin arraynya aja
void Condition (char (*seed)[NMAX][NMAX], char (*nextseed)[NMAX][NMAX]) { 
	int i, j;
	for (i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if (Neighbors(*seed, i, j)<=1)
				(*nextseed)[i][j] = '-';
			else if(Neighbors(*seed, i, j)<3)
				(*nextseed)[i][j] = (*seed)[i][j];
			else if (Neighbors(*seed, i, j)<4)
				(*nextseed)[i][j] = 'X';
			else
				(*nextseed)[i][j]= '-';
		}
	}
	for (i=0; i<rows; i++){
		for (j=0; j<cols; j++){
			(*seed)[i][j] = (*nextseed)[i][j];
		}
	}
	return;
}

//untuk delay
void delay(int number_of_milliseconds) 
{  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + number_of_milliseconds) 
        ; 
}

//Sambutan awal
void greetings(){
	printf("Selamat datang di Conway Game of Life!\n\n");
	printf("Game ini merupakan game mengenai sel yang dapat mati maupun hidup, bergantung pada kondisi sel tetangganya\n\n");
	
	printf("Aturan:\n");
	printf("1. Jika terdapat sebuah sel hidup yang memiliki kurang dari 1 tetangga yang hidup,\n   sel tersebut mati pada iterasi selanjutnya (underpopulation)\n");
	printf("2. Jika terdapat sebuah sel hidup yang memiliki 2 tetangga yang hidup, sel tersebut\n   tetap hidup pada iterasi selanjutnya (next generation).\n");
	printf("3. Jika terdapat sebuah sel hidup yang memiliki lebih dari 4 tetangga yang hidup,\n   sel tersebut mati pada iterasi selanjutnya (overpopulation).\n");
	printf("4. Jika terdapat sebuah sel mati yang memiliki 3 tetangga yang hidup, sel tersebut\n   menjadi hidup pada iterasi selanjutnya (reproduction).\n");
	printf("\nPermainan akan dimulai dengan kondisi awal sesuai dengan file yang Anda masukkan\n");
	return;
}


//PROGRAM UTAMA
int main(){
	//Deklarasi Variabel
	char file[100], seed[NMAX][NMAX], newseed[NMAX][NMAX];
	FILE *fp;
	int i, loop, pilihan;
	char simpan = 'Y';
	
	//Sambutan awal
	greetings();
	
	//Menerima nama file, buka file, dan input file ke array
	inputseed(&seed);
	
	//MENU
	system("CLS");
	do{
		//Membaca pilihan
		printf("MENU:\n1. Tick\n2. Animate\n3. Quit\nPilihan anda: ");
		scanf("%d", &pilihan);
		
		//TICK : Animasi sekali
		if (pilihan == 1){
			system("CLS");
			Condition(&seed, &newseed);
			//printseed(seed);
		}
		
		//ANIMATE : Animasi sesuai banyak iterasi
		else if(pilihan == 2){
			printf("Banyaknya iterasi yang diinginkan: ");
			scanf("%d", &loop);
			for (i=0; i<loop; i++){
				system("CLS");
				Condition(&seed, &newseed);
				//printseed(seed);
				delay(250);
			}
		}
		
		//QUIT : keluar
		else if (pilihan == 3){
			printf("Input seed baru? (Y/N) : ");
			scanf(" %c", &simpan);
			if (simpan == 'Y'){
				getchar();
				inputseed(&seed);
				system("CLS");
			}
		}
		
		//Masukan salah
		else{
			printf("\nMasukan salah! Silahkan masukkan kembali pilihan Anda!\n\n");
		}	
		
	}while(simpan =='Y');
	
	return 0;
}
