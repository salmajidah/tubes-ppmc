//ini buat tubes ppmc
#include <stdio.h> 
#include <time.h>

int cols;
int rows; 

//membaca input file eksternal
char inputseed (FILE *fp){
	int rows,cols;
	fscanf(fp,"%d",&rows);
	fscanf(fp,"%d",&cols);
	char seed[rows][cols];
	int n=0,i=0;
	
	while (n<rows && fgets(seed[n],sizeof(*seed),stdin)!=NULL){ //di geany compile, di command prompt ga bisa keluar outputnya gatau knp
		n++;
		}
	while (i<cols && fgets(seed[i],sizeof(*seed),stdin)!=NULL){
		i++;
		}
	return(seed[n][i]);
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

int Condition (int element, int neighbors) { 
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
	}while(pilihan!=3);
	
	return 0;
}



