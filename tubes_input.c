#include <stdio.h>
#include <string.h>


void inputseed (char in[50]){
	FILE *input, *seed;
	char in[700],seed_temp[700],seed_final[700],seed_fix[100][100];
	int baris, int kolom;
	int i,j,k;
	
	fgets(in, sizeof(in),stdin);//baca input
	for (i=0;in[i]!='.';i++){	//ngambil nama file input
		seed_temp[i]=in[i];
	}
	input=fopen(strcat(seed_temp,".txt"),r++);	//buka file eksternal
	
	for (i=0;in[i]!='.';i++){	//ngambil nama file 
		seed_final[i]=in[i];
	}
	seed=fopen(strcat(seed_final,"seed_final.txt"), w++);//file yang isinya nanti seed yang siap simulasi
	
	while(//isi file bukan #){
		scanf("%d", &baris);
		scanf("%d", &kolom);
		char seed_fix[baris][kolom];
		//baca array yang ada di file eksternal
		//masukkin elemen array yang ada di file eksternal ke array yang baru biar jadi seed
		for (i=0;i<baris;i++){
			for (j=0;j<kolom,j++){
				fputs(seed_fix[i][j],seed);
			}
		}
	}
	return (seed_fix[i][j]);
	fclose(input);
	fclose(seed);
}
