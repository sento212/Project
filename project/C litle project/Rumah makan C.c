#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <stdbool.h>
#include <time.h>

struct data{
int jumlah;
char id[50],nama[50],jenis[50],harga[50];

}k[100];

struct show{
int jumlah;
char id[50],nama[50],jenis[50],harga[50];

}k1;

int jum=0, t=0,temp, menu1 = 0,tmp;
char swap[30], cri[50];


void login () {
	char ch;
	char username[20]="admin", password[20]="1234";

	printf("\nSELAMAT DATANG DI DATABASE TOKO\n\n");
	get_time();
	printf("\n");
	printf(" Masukkan Username : ");
	scanf("%s", &username);
	printf("\n Masukkan Password : ");
	int i=0;
	 while(1)
    {
        ch = getch();
        if(ch != '\r')
        {
            password[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        else
        {
            break;
        }
        i++;
	}
	printf("\n");

	if (strcmp(username,"admin") == 0 && strcmp(password,"1234") == 0) {
		printf("\n Selamat Datang Admin");
		printf(" Tekan apa saja untuk melanjutkan");
		getch();
		system("cls");
		main_2();

	}
}
void get_time()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime );
    timeinfo = localtime (&rawtime);
    printf ("%s", asctime (timeinfo) );
}

void input(){
    int i, j = 1;
    system("cls");
    printf("Masukkan Jumlah barang yang Ingin Dimasukkan: ");
    scanf("%d", &jum);
    if (jum <= 0) {
    	printf("Barang gagal ditambahkan!");
	}
		else {
		menu1++;
        for(i = t ; i < t+jum ; i++){
        	printf("\n");
            printf("%i.ID Barang\t: ", j); scanf(" %[^\n]", &k[i].id);
            printf(" Nama Barang\t: "); scanf(" %[^\n]", &k[i].nama);
            printf("Harga Barang\t: "); scanf(" %[^\n]", &k[i].harga);
            printf("Stok Barang\t: "); scanf("%d", &k[i].jumlah);
            printf("Jenis Barang\t: "); scanf(" %[^\n]", &k[i].jenis);
            j++;

        }
        printf("\nBarang Berhasil Ditambahkan");

    }
    t += jum;
    printf("\nTekan Enter Untuk Kembali");
    getch();
	main_2();
}

void output()
{
 	int i;
    system("cls");
    if (menu1 <= 0) {
		printf("\n\t\tBarang Belum ada!\n");
		printf("\nTekan Enter Untuk Kembali");
		getch();
		main_2();
	}
		else {
		printf("\tNo\tID Barang\tNama Barang\tHarga\tStok Barang\tJenis Barang\n\n");
	    for(i = 0 ; i < t ; i++){
	    		printf("\t%i.\t%s\t\t%s\t%s\t\t%d\t\t%s\n", i+1, k[i].id, k[i].nama, k[i].harga, k[i].jumlah, k[i].jenis);
	        }
	   printf("Tekan Enter Untuk Kembali");
	getch();
    main_2();
}
}

void hapus()
{
     system("cls");
    printf("\nMasukkan Nama Menu yang ingin Dihapus : ");
    scanf(" %[^\n]", &cri);
    bool temu = false;
    int j,i = 0;
     char pilihan;
    while (i <= t && temu == false){
        if(strcmp(cri,k[i].nama) == 0){
            temu = true;
            tmp = i;
        }
        else {
        	i++;
        }
    }
     if(temu == true ){
        printf("\nID Barang : %s\n", k[i].id);
        printf("Nama Barang: %s\n", k[i].nama);
        printf("Harga Barang: %s\n", k[i].harga);
        printf("Stok Barang: %d\n", k[i].jumlah);
    	printf("Jenis Barang: %s\n", k[i].jenis);
        printf("\nApakah Ingin Menghapus Data ini (y/t): ");
    	scanf("%s", &pilihan);
    	if (pilihan == 'y') {
    		for (j = tmp; j < t; j++) {
    			strcpy(k[j].id, k[j+1].id);
    			strcpy(k[j].nama, k[j+1].nama);
    			strcpy(k[j].harga, k[j+1].harga);
    			k[j].jumlah = k[j+1].jumlah;
    			strcpy(k[j].jenis, k[j+1].jenis);
			}
    		printf("\tSuksess Hapus Data!");
    		t -= 1;
    	}
    	else if (pilihan == 't') {
    		printf("\tData Tidak Berhasil Di Hapus");
		}
    }
    else {
        printf("\n Barang Tidak Ditemukan\n");
    }
       printf("\n Tekan Enter Untuk Kembali\n");
    getch();
    main_2();
}

void edit(){
system("cls");
printf("\nMasukkan Nama Barang yang Ingin Diedit : ");
scanf(" %[^\n]", &cri);
    bool temu = false;
    int i = 0;
    int pilihan, input1;
    char input[100];
    while (i <= t && temu == false){
        if(strcmp(cri,k[i].nama) == 0){
            temu = true;
        }
        else {
        	i++;
		}
    }
    if(temu == true ){
    		printf("\n");
            printf("1. ID barang\t: %s\n", k[i].id);
            printf("2. Nama barang\t: %s\n", k[i].nama);
            printf("3. Harga barang\t: %s\n", k[i].harga);
            printf("4. Stok barang\t: %d\n", k[i].jumlah);
            printf("5. Jenis barang\t: %s\n", k[i].jenis);

        do {
            printf("\n\t\t\t\tIngin Mengganti Data Nomor Berapa (1/2/3/4/5) : ");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
            	printf("\nData Semula : %s", k[i].id);
            	printf("\nData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(k[i].id, input);
            	printf("Data Berhasil diubah!");

			}
			else if (pilihan == 2) {
				printf("\nData Semula : %s", k[i].nama);
            	printf("\nData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(k[i].nama, input);
            	printf("\t\t\t\tData Berhasil diubah!");

			}
			else if (pilihan == 3) {
				printf("\nData Semula : %s", k[i].harga);
				printf("\nData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(k[i].harga, input);
            	printf("Data Berhasil diubah!");

			}
			else if (pilihan == 4) {
				printf("\nData Semula : %d", k[i].jumlah);
            	printf("\nData diubah : ");
            	scanf("%i", &input1);
            	k[i].jumlah = input1;
            	printf("\t\t\t\tData Berhasil diubah!");

			}
			else if (pilihan == 5) {
				printf("\nData Semula : %s", k[i].jenis);
				printf("\nData diubah : ");
            	scanf(" %[^\n]", &input);
            	strcpy(k[i].jenis, input);
            	printf("\t\t\t\tData Berhasil diubah!");

			}
			else {
				printf("Pilihan Tidak Tersedia!");

			}
		}while (pilihan < 1 || pilihan > 5);
    }
    else {
        printf("\nMenu Tidak Ditemukan\n");
    }
    printf("\nTekan Enter Untuk Kembali");
	getch();
    main_2();
}

void cari(){
    system("cls");
    printf("\nMasukkan Nama Barang yang Ingin Dicari : ");
    scanf(" %[^\n]", &cri);
    bool temu = false;
    int i = 0;
    while (i <= t && temu == false){
        if(strcmp(cri,k[i].nama) == 0){
            temu = true;
        }
        else {
        	i++;
		}
    }
    if(temu == true ){
            printf("1. ID Barang\t: %s\n", k[i].id);
            printf("2. Nama Barang\t: %s\n", k[i].nama);
            printf("3. Harga Barang\t: %s\n", k[i].harga);
            printf("4. Stok Barang\t: %d\n", k[i].jumlah);
            printf("5. Jenis Barang\t: %s\n", k[i].jenis);
    }
    else {
        printf("\nMenu Tidak Ditemukan\n");
    }
    printf("\nTekan Enter Untuk Kembali\n");
    getch();
    main_2();
}

void urut(){
    system("cls");
    int i,j;
    char temp2[100];
    if (menu1 <= 0) {
    	printf("\nMenu Belum Ada!\n");
    }
    else {

printf("\tNo\tID Barang\tNama Barang\tHarga\tStok Barang\tJenis Barang\n\n");
		for (i = 0 ; i < t - 1; i++){
			for (j = 0 ; j < t - i - 1; j++){
	      		if (k[j].jumlah > k[j+1].jumlah){

	        		strcpy(swap, k[j].id);
	        		strcpy(k[j].id, k[j+1].id);
			        strcpy(k[j+1].id, swap);

			        strcpy(swap, k[j].nama);
			        strcpy(k[j].nama, k[j+1].nama);
			        strcpy(k[j+1].nama, swap);

			        strcpy(swap, k[j].harga);
			        strcpy(k[j].harga, k[j+1].harga);
			        strcpy(k[j+1].harga, swap);

			        temp = k[j].jumlah;
			        k[j].jumlah = k[j+1].jumlah;
			        k[j+1].jumlah = temp;

			        strcpy(swap, k[j].jenis);
			        strcpy(k[j].jenis, k[j+1].jenis);
			        strcpy(k[j+1].jenis, swap);
	      		}
	    	}
		}
	}

  	for(i = 0 ; i < t ; i++){
  		printf("\t%i.\t%s\t\t%s\t%s\t\t%d\t\t%s\n", i+1, k[i].id, k[i].nama, k[i].harga, k[i].jumlah, k[i].jenis);
	}
    printf("\nTekan Enter Untuk Kembali");
    getch();
    main_2();
}

void import()
{
    system("cls");
FILE *fp;
 int i;
 char pilihan;
 if (menu1 <= 0) {
		printf("\n\t\tBarang Belum ada!\n");
		getch();
		main_2();
	}
	if((fp = fopen("D:\\data tas.txt","w"))==NULL)
    {
        printf("Error: file tidak ada");
        printf("\nTekan Enter Untuk Kembali");
        getch();
		main_2();
    }
	fp = fopen("D:\\data tas.txt","w") ;

	fclose(fp);

 fp = fopen("D:\\data tas.txt","a") ;
for(i = 0 ; i < t-1 ; i++){
fprintf(fp,"|%s|%s|%s|%d|%s|\n",k[i].id, k[i].nama, k[i].harga, k[i].jumlah, k[i].jenis);
	}
fprintf(fp,"|%s|%s|%s|%d|%s|",k[t-1].id, k[t-1].nama, k[t-1].harga, k[t-1].jumlah, k[t-1].jenis);
 fclose(fp);
 printf("Import data Berhasil!!!");
 printf("\nTekan Enter Untuk Kembali");
 getch();
    main_2();
}

void export1()
{
    system("cls");
FILE *fp;
 int i;
 char pilihan;
 	if((fp = fopen("D:\\data tas.txt","r"))==NULL)
    {
        printf("Error: file tidak ada");
        printf("\nTekan Enter Untuk Kembali");
        getch();
		main_2();
    }
 fp = fopen("D:\\data tas.txt","r") ;
 printf("\tID Barang\tNama Barang\tHarga\tStok Barang\tJenis Barang\n\n");
while(!feof(fp)){
fscanf(fp,"|%[^|]|%[^|]|%[^|]|%d|%[^|]|\n",&k1.id, &k1.nama, &k1.harga, &k1.jumlah, &k1.jenis);
printf("\n\t%s\t\t%s\t\t%s\t%d\t\t%s",k1.id, k1.nama, k1.harga, k1.jumlah, k1.jenis);
	}

 fclose(fp);
printf("\nTekan Enter Untuk Kembali");
 getch();
    main_2();
}

void export2()
{
    system("cls");
FILE *fp;
 char pilihan;
 	if((fp = fopen("D:\\data tas.txt","r"))==NULL)
    {
        printf("Error: file tidak ada");
        printf("\nTekan Enter Untuk Kembali");
        getch();
		main_2();
    }
 fp = fopen("D:\\data tas.txt","r") ;
while(!feof(fp)){
fscanf(fp,"|%[^|]|%[^|]|%[^|]|%d|%[^|]|\n",&k[t].id, &k[t].nama, &k[t].harga, &k[t].jumlah, &k[t].jenis);
t++;
menu1++;
	}
 fclose(fp);
 printf("Import data dari database Berhasil!!!");
printf("\nTekan Enter Untuk Kembali");
 getch();
    main_2();
}

void exit_program()
{
    exit(0);
}

int main_2(){
    system("cls");
  printf("menu pilihan \n");
  int pil;
printf("1.masukan data barang \n");
printf("2.liat barang \n");
printf("3.hapus barang \n");
printf("4.edit barang \n");
printf("5.cari barang \n");
printf("6.urutkan jumlah barang \n");
printf("7.import data \n");
printf("8.tampilkan data yang di import \n");
printf("9.export data dari database \n");
printf("10.logout \n");
 printf("Pilih : ");
scanf("%d", &pil);
	if (pil <= 0 || pil > 10 ) {
		printf("\nPilihan Tidak Tersedia!\n");
		getch();
		main_2();
	}
  else if (pil == 1) {
    printf("\n");
     input();
  }
else if (pil == 2) {
        printf("\n");
output();
}
else if (pil == 3) {
    printf("\n");
hapus();
}
else if (pil == 4) {
    printf("\n");
edit();
}
else if (pil == 5) {
    printf("\n");
cari();
}
else if (pil == 6) {
    printf("\n");
urut();
}
else if (pil == 7) {
    printf("\n");
import();
}
else if (pil == 8) {
    printf("\n");
export1();
}
else if (pil == 9) {
    printf("\n");
export2();
}
else if (pil == 10) {
    printf("\n");
exit_program();
}

return 0;
}

int main()
{
    login();
}

