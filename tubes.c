//ini buat tubes ppmc
#include <stdio.h> 
#include <time.h>

int rows; 
int cols;
const NMAX=50;

//membaca input file eksternal
void inputseed(char (*seed)[NMAX][NMAX]){
	char file[100], c;
	int i=0,j=0;
	gets(file);
	FILE *fp;
	fp=fopen(file,"r");

	fscanf(fp,"%d", &rows);
	fscanf(fp,"%d", &cols);

	while ((i!=rows-1) || (j!=cols-1)){ //selama bukan baris akhir atau kolom akhir
					    //masukkan karakter ke array
		c= fgetc(fp);
		(*seed)[i][j]=c;
		++j; //baca di baris yang sama tapi maju kolom selanjutnya
		
		if(j>cols-1){ //kalau iterasi melebihi kolom akhir, pindah baris, ulang baca kolom dari awal
			c=fgetc(fp);
			j=0;
			i++;
		}
		
		if ((i==rows-1)&&(j==cols-1)){ //udah di baris akhir dan kolom akhir
			c=fgetc(fp);
			(*seed)[i][j]=c;
		}
	}
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
	printf("\nPermainan akan dimulai dengan kondisi awal pada file yang Anda masukkan\n");
	printf("Input file:");
	return;
}


//PROGRAM UTAMA
int main(){
	//Deklarasi Variabel
	char file[100];
	FILE *fp;
	int i, loop, pilihan;
	char simpan;
	
	//Sambutan awal
	greetings();
	
	//Menerima nama file, buka file, dan input file ke array
	gets(file);
	//fp = fopen(file, "r");
	//input file ke array
	
	//MENU
	system("CLS");
	do{
		//Membaca pilihan
		printf("MENU:\n1. Tick\n2. Animate\n3. Quit\nPilihan anda:");
		scanf("%d", &pilihan);
		
		//TICK : Animasi sekali
		if (pilihan == 1){
			//print array
		}
		
		//ANIMATE : Animasi sesuai banyak iterasi
		else if(pilihan == 2){
			printf("Banyaknya iterasi yang diinginkan:");
			scanf("%d", &loop);
			for (i=0; i<loop; i++){
				system("CLS");
				//print array;
				delay(250);
			}
		}
		
		//QUIT : keluar
		else if (pilihan == 3){
			printf("Simpan seed terakhir?(Y/N) : ");
			scanf("%c", &simpan);
			if (simpan == 'Y'){
				printf("Nama file: ");
				gets(file);
				//print ke file eksternal
			}
		}
		
		//Masukan salah
		else{
			printf("Masukan salah! Silahkan masukkan kembali pilihan Anda!\n");
		}	
	}while(pilihan!=3);
	
	return 0;
}



