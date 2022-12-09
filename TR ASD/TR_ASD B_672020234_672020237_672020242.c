#include <stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

/*Anggota Kelompok Pasrah
1. Pray Lexcaesar Manopo (672020234)
2. Risna Anggita Sari (672020237)
3. Tiara syah I.P (672020242)
*/

void gotoxy(int x, int y){
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int angka ,cpy;

struct history{
	int num;
	char his[45];
	struct history *next;
}*head1;

struct anak{
	int no;
	int idmenu;
	char namamenu[45];
	char porsi[45];
	int harga;
	char jenismenu[45];
	struct anak *next;
}*head, *ptr, *start;

void login(){
	int per = 0;
	char username[20];
	char password[20];
	char cur_time[128];
	time_t t;
  	struct tm* ptm;
  	t = time(NULL);
  	ptm = localtime(&t);
  	strftime(cur_time, 128, "%b %d %Y \t\t    %H:%M:%S", ptm);
	system("color 9F");
	while(per == 0){
		gotoxy(50,10);
		printf("DATABASE RESTORAN\n\n");
		gotoxy(39,12);
		printf("======================================\n");
		gotoxy(39,16);
		printf("======================================\n");
		gotoxy(40,17);
		printf("%s\n", cur_time);
		gotoxy(40,13);
		printf("Masukkan username\t: ");
		scanf(" %s]", &username);
		gotoxy(40,15);
		printf("Masukkan password\t: ");
		scanf(" %s", &password);
		if(strcmp(username,"admin")==0 && strcmp(password,"admin")==0){
        		printf("\n\n\n\t\t\t\t\t\t   Login Berhasil!");
        		printf("\n\n\n\t\t\t\t\t       Klik enter untuk lanjut");
        		getch();
				system("cls");
				menu();

		}
		else{
			printf("\n\n\n\t\t\t\t\t\t   Username dan password salah");
			getch();
			system("cls");
		}
	}
}

void buatList(int banyak){
	struct anak *newNode, *temp;
	int data, i;
	head = (struct anak *)malloc(sizeof(struct anak));
	if(head == NULL){
		printf("Error");
	}
	else{
		angka = 1;
		printf("\n\t\t\t\t\t\t\tDATA MENU KE-1\n");
		printf("\t\t\t\t\t*id menu\t\t: "); scanf("%d", &head->idmenu);
		printf("\t\t\t\t\t*nama menu\t\t: "); scanf(" %[^\n]", head->namamenu);
		printf("\t\t\t\t\t*porsi\t\t\t: "); scanf(" %[^\n]", head->porsi);
		printf("\t\t\t\t\t*jenis menu\t\t: "); scanf(" %[^\n]", head->jenismenu);
		printf("\t\t\t\t\t*harga\t\t\t: "); scanf("%d", &head->harga);
		head->next=NULL;
		temp = head;
		for(i=2; i<=banyak; i++){
			newNode = (struct anak *)malloc(sizeof(struct anak));
			if(newNode == NULL){
				printf("Error");
				break;
			}
			else{
				angka++;
				printf("\n\t\t\t\t\t\tDATA MENU KE-%d\n", i);
				printf("\t\t\t\t\t*id menu\t\t: "); scanf("%d", &newNode->idmenu);
				printf("\t\t\t\t\t*nama menu\t\t: "); scanf(" %[^\n]", newNode->namamenu);
				printf("\t\t\t\t\t*porsi\t\t\t: "); scanf(" %[^\n]", newNode->porsi);
				printf("\t\t\t\t\t*jenis menu\t\t: "); scanf(" %[^\n]", newNode->jenismenu);
				printf("\t\t\t\t\t*harga\t\t\t: "); scanf("%d", &newNode->harga);
				newNode->next = NULL;
				temp->next = newNode;
				temp = temp->next;
			}
		}
	}
}

void insertData(){
	struct anak *newNode, *temp;
    newNode = (struct anak*)malloc(sizeof(struct anak));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
    	angka++;
		printf("\n\t\t\t\t\t\t\tDATA MENU KE-%d\n", angka);
		printf("\t\t\t\t\t*id menu\t\t: "); scanf("%d", &newNode->idmenu);
		printf("\t\t\t\t\t*nama menu\t\t: "); scanf(" %[^\n]", newNode->namamenu);
		printf("\t\t\t\t\t*porsi\t\t\t: "); scanf(" %[^\n]", newNode->porsi);
		printf("\t\t\t\t\t*jenis menu\t\t: "); scanf(" %[^\n]", newNode->jenismenu);
		printf("\t\t\t\t\t*harga\t\t\t: "); scanf("%d", &newNode->harga);
        newNode->next = NULL;
        temp = head;
        // Traverse to the last node
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode; // Link address part
    }
}

void displayList(){
	int i = 0;
    struct anak *temp;
    if(head == NULL){
        printf("\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
        temp = head;
        while(temp != NULL){
        	gotoxy(23,10+i); printf("%d", temp->idmenu);
            gotoxy(41,10+i); printf("%s", temp->namamenu);
            gotoxy(65,10+i); printf("%s", temp->porsi);
            gotoxy(81,10+i); printf("%s", temp->jenismenu);
            gotoxy(97,10+i); printf("%d", temp->harga);
            i++;
            temp = temp->next;
        }
    }
}

void printList(){
    FILE *fp;
    fp = fopen("Menu Makanan.csv", "w");
	int i = 0;
    struct anak *temp;
    if(head == NULL){
        printf("\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
        temp = head;
        while(temp != NULL){
            fprintf(fp,"idmenu;namamenu;porsi;jenismenu;harga\n");
            fprintf(fp,"%d;%s;%s;%s;%d\n", temp->idmenu, temp->namamenu, temp->porsi, temp->jenismenu, temp->harga);
            i++;
            temp = temp->next;
        }
    }

    fclose(fp);
}

void menu9(){
	Sleep(1000);
	system("cls");
	printf("This program will close in 3...");
	Sleep(1000);
	system("cls");
	printf("This program will close in 2...");
	Sleep(1000);
	system("cls");
	printf("This program will close in 1...");
	Sleep(1000);
	system("cls");
	exit(0);
}

typedef struct anak node; //nama lain dari tipe data

void delete_item(int value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;
	angka--;
    while(myNode!=NULL)
    {
        if(myNode->idmenu==value)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("\n\t\t\t\t\t\tData berhasil dihapus");
            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }
        previous = myNode;
        myNode = myNode->next;
    }
    if(flag==0)
        printf("\n\n\t\t\t\t\t\t   Data tidak ditemukan!\n");
}

int search_item(int value)
{
    node *searchNode = head;
    int flag = 0;
    while(searchNode!=NULL)
    {
        if(searchNode->idmenu==value)
        {
        	printf("\n");
        	printf("\t\t\t\t\t\t\t\t DATA\n");
            printf("\t\t\t\t\t\t *id menu \t: %d\n", value);
			printf("\t\t\t\t\t\t *nama menu \t: %s\n", searchNode->namamenu);
            printf("\t\t\t\t\t\t *porsi\t\t: %s\n", searchNode->porsi);
            printf("\t\t\t\t\t\t *jenis menu\t: %s\n", searchNode->jenismenu);
			printf("\t\t\t\t\t\t *harga\t\t: %d\n", searchNode->harga);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }
    if(flag==0){
		printf("\n\n\t\t\t\t\t\t   Data tidak ditemukan!");
		return 1;
	}

    return 0;
}

char hehehe[45];

int search_namamenu(int value){
    node *searchNode = head;
    int flag = 0;
	while(searchNode!=NULL)
    {
        if(searchNode->idmenu==value)
        {
			printf("\n\t\t\t\t\t\t Data semula \t: %s", searchNode->namamenu);
            flag=1;
			break;
        }
        else{
			searchNode = searchNode->next;
		}
    }
    if(flag==0){
        printf("\n\t\t\t\t\t\t Tidak ada data\n");
        return 1;
	}
	printf("\n\t\t\t\t\t\t Data diubah \t: "); scanf("%s", searchNode->namamenu);
	strcpy(hehehe, searchNode->namamenu);
	printf("\n\t\t\t\t\t\t Berhasil diubah");

	return 0;
}

int search_porsi(int value){
    node *searchNode = head;
    int flag = 0;
	while(searchNode!=NULL)
    {
        if(searchNode->idmenu==value)
        {
			printf("\n\t\t\t\t\t\t Data semula \t: %s", searchNode->porsi);
            flag=1;
			break;
        }
        else{
			searchNode = searchNode->next;
		}
    }
    if(flag==0){
        printf("\n\t\t\t\t\t\t Tidak ada data\n");
        return 1;
	}
	printf("\n\t\t\t\t\t\t Data diubah \t: "); scanf("%s", searchNode->porsi);
	strcpy(hehehe, searchNode->porsi);
	printf("\n\t\t\t\t\t\t Berhasil diubah");
	return 0;
}

int search_jenismenu(int value){
    node *searchNode = head;
    int flag = 0;
	while(searchNode!=NULL)
    {
        if(searchNode->idmenu==value)
        {
			printf("\n\t\t\t\t\t\t Data semula \t: %s", searchNode->jenismenu);
            flag=1;
			break;
        }
        else{
			searchNode = searchNode->next;
		}
    }
    if(flag==0){
        printf("\n\t\t\t\t\t\t Tidak ada data\n");
        return 1;
	}
	printf("\n\t\t\t\t\t\t Data diubah \t: "); scanf("%s", searchNode->jenismenu);
	strcpy(hehehe, searchNode->jenismenu);
	printf("\n\t\t\t\t\t\t Berhasil diubah");
	return 0;
}

int search_harga(int value){
    node *searchNode = head;
    int flag = 0;
	while(searchNode!=NULL){
        if(searchNode->idmenu==value){
			printf("\n\t\t\t\t\t\t Data semula \t: %d", searchNode->harga);
            flag=1;
			break;
        }
        else{
			searchNode = searchNode->next;
		}
    }
    if(flag==0){
        printf("\n\t\t\t\t\t\t Tidak ada data\n");
        return 1;
	}
	printf("\n\t\t\t\t\t\t Data diubah \t: "); scanf("%d", &searchNode->harga);
	cpy = searchNode->harga;
	printf("\n\t\t\t\t\t\t Berhasil diubah");

	return 0;
}

void menu6_1(char value[45]){
	int i = 0;
	struct anak *temp;
    if(head == NULL){
        printf("\n\n\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
    	temp = head;
    	gotoxy (23,16); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
    	printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
        while(temp != NULL){
        	if(strcmp(temp->namamenu, value)==0){
        		gotoxy(23,18+i); printf("%d", temp->idmenu);
            	gotoxy(41,18+i); printf("%s", temp->namamenu);
            	gotoxy(57,18+i); printf("%s", temp->porsi);
            	gotoxy(73,18+i); printf("%s", temp->jenismenu);
            	gotoxy(97,18+i); printf("%d", temp->harga);
            	i++;
			}
            temp = temp->next;
        }
    }
}

void menu6_2(char value[45]){
	int i = 0;
	struct anak *temp;
    if(head == NULL){
        printf("\n\n\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
    	temp = head;
    	gotoxy (23,16); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
    	printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
        while(temp != NULL){
        	if(strcmp(temp->porsi, value)==0){
        		gotoxy(23,18+i); printf("%d", temp->idmenu);
            	gotoxy(41,18+i); printf("%s", temp->namamenu);
            	gotoxy(57,18+i); printf("%s", temp->porsi);
            	gotoxy(73,18+i); printf("%s", temp->jenismenu);
            	gotoxy(97,18+i); printf("%d", temp->harga);
            	i++;
			}
            temp = temp->next;
        }
    }
}

void menu6_3(char value[45]){
	int i = 0;
	struct anak *temp;
    if(head == NULL){
        printf("\n\n\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
    	temp = head;
    	gotoxy (23,16); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
    	printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
        while(temp != NULL){
        	if(strcmp(temp->jenismenu, value)==0){
        		gotoxy(23,18+i); printf("%d", temp->idmenu);
            	gotoxy(41,18+i); printf("%s", temp->namamenu);
            	gotoxy(57,18+i); printf("%s", temp->porsi);
            	gotoxy(73,18+i); printf("%s", temp->jenismenu);
            	gotoxy(97,18+i); printf("%d", temp->harga);
            	i++;
			}
            temp = temp->next;
        }
    }
}

void menu6_4(int value){
	int i = 0;
    struct anak *temp;
    if(head == NULL){
        printf("\n\n\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
    	temp = head;
    	gotoxy (23,16); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
    	printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
        while(temp != NULL){
        	if(temp->harga == value){
        		gotoxy(23,18+i); printf("%d", temp->idmenu);
            	gotoxy(41,18+i); printf("%s", temp->namamenu);
            	gotoxy(57,18+i); printf("%s", temp->porsi);
            	gotoxy(73,18+i); printf("%s", temp->jenismenu);
            	gotoxy(97,18+i); printf("%d", temp->harga);
            	i++;
			}
            temp = temp->next;
        }
    }
}

void menu6_5(int value){
	int i = 0;
    struct anak *temp;
    if(head == NULL){
        printf("\n\n\t\t\t\t\t\t   Tidak ditemukan data");
    }
    else{
    	temp = head;
    	gotoxy (23,16); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
    	printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
        while(temp != NULL){
        	if(temp->idmenu == value){
        		gotoxy(23,18+i); printf("%d", temp->idmenu);
            	gotoxy(41,18+i); printf("%s", temp->namamenu);
            	gotoxy(57,18+i); printf("%s", temp->porsi);
            	gotoxy(73,18+i); printf("%s", temp->jenismenu);
            	gotoxy(97,18+i); printf("%d", temp->harga);
            	i++;
			}
            temp = temp->next;
        }
    }
}

void sortidmenu(){
	int r,u;
	char q [45];
	char s [45];
	char t [45];
	struct anak *temp1, *temp;
    struct anak *temp2;
	for(temp1=head;temp1!=NULL;temp1=temp1->next){
    	for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
            if(temp2->idmenu < temp1->idmenu){
                r = temp1->idmenu;
                temp1->idmenu = temp2->idmenu;
                temp2->idmenu = r;

                strcpy(q, temp1->namamenu);
                strcpy(temp1->namamenu, temp2->namamenu);
                strcpy(temp2->namamenu, q);

                strcpy(s, temp1->porsi);
                strcpy(temp1->porsi, temp2->porsi);
                strcpy(temp2->porsi, s);

                strcpy(t, temp1->jenismenu);
                strcpy(temp1->jenismenu, temp2->jenismenu);
                strcpy(temp2->jenismenu, t); ;

                u = temp1->harga;
                temp1->harga = temp2->harga;
                temp2->harga = u;
        	}
        }
    }
}

void sortharga(){
	int r,u;
	char q [45];
	char s [45];
	char t [45];
	struct anak *temp1, *temp;
    struct anak *temp2;
	for(temp1=head;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
            if(temp2->harga < temp1->harga){
              	r = temp1->idmenu;
                temp1->idmenu = temp2->idmenu;
                temp2->idmenu = r;

                strcpy(q, temp1->namamenu);
                strcpy(temp1->namamenu, temp2->namamenu);
                strcpy(temp2->namamenu, q);

                strcpy(s, temp1->porsi);
                strcpy(temp1->porsi, temp2->porsi);
                strcpy(temp2->porsi, s);

                strcpy(t, temp1->jenismenu);
                strcpy(temp1->jenismenu, temp2->jenismenu);
                strcpy(temp2->jenismenu, t); ;

                u = temp1->harga;
                temp1->harga = temp2->harga;
                temp2->harga = u;
            }
        }
    }
}

void sortnamamenu(){
	int r,u;
	char q [45];
	char s [45];
	char t [45];
	char hasil1[45];
	char hasil2[45];
	struct anak *temp1, *temp;
    struct anak *temp2;
	for(temp1=head;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
          	strcpy(hasil1, temp1->namamenu);
          	strcpy(hasil2, temp2->namamenu);
            if(strcmp(hasil1, hasil2)==1){
              	r = temp1->idmenu;
                temp1->idmenu = temp2->idmenu;
                temp2->idmenu = r;

                strcpy(q, temp1->namamenu);
                strcpy(temp1->namamenu, temp2->namamenu);
                strcpy(temp2->namamenu, q);

                strcpy(s, temp1->porsi);
                strcpy(temp1->porsi, temp2->porsi);
                strcpy(temp2->porsi, s);

                strcpy(t, temp1->jenismenu);
                strcpy(temp1->jenismenu, temp2->jenismenu);
                strcpy(temp2->jenismenu, t); ;

                u = temp1->harga;
                temp1->harga = temp2->harga;
                temp2->harga = u;
            }
        }
    }
}

void sortporsi(){
	int r,u;
	char q [45];
	char s [45];
	char t [45];
	char hasil1[45];
	char hasil2[45];
	struct anak *temp1, *temp;
    struct anak *temp2;
	for(temp1=head;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
          	strcpy(hasil1, temp1->porsi);
          	strcpy(hasil2, temp2->porsi);
            if(strcmp(hasil1, hasil2)==1){
              	r = temp1->idmenu;
                temp1->idmenu = temp2->idmenu;
                temp2->idmenu = r;

                strcpy(q, temp1->namamenu);
                strcpy(temp1->namamenu, temp2->namamenu);
                strcpy(temp2->namamenu, q);

                strcpy(s, temp1->porsi);
                strcpy(temp1->porsi, temp2->porsi);
                strcpy(temp2->porsi, s);

                strcpy(t, temp1->jenismenu);
                strcpy(temp1->jenismenu, temp2->jenismenu);
                strcpy(temp2->jenismenu, t); ;

                u = temp1->harga;
                temp1->harga = temp2->harga;
                temp2->harga = u;
            }
        }
    }
}

void sortjenismenu(){
	int r,u;
	char q [45];
	char s [45];
	char t [45];
	char hasil1[45];
	char hasil2[45];
	struct anak *temp1, *temp;
    struct anak *temp2;
	for(temp1=head;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next){
          	strcpy(hasil1, temp1->jenismenu);
          	strcpy(hasil2, temp2->jenismenu);
            if(strcmp(hasil1, hasil2)==1){
              	r = temp1->idmenu;
                temp1->idmenu = temp2->idmenu;
                temp2->idmenu = r;

                strcpy(q, temp1->namamenu);
                strcpy(temp1->namamenu, temp2->namamenu);
                strcpy(temp2->namamenu, q);

                strcpy(s, temp1->porsi);
                strcpy(temp1->porsi, temp2->porsi);
                strcpy(temp2->porsi, s);

                strcpy(t, temp1->jenismenu);
                strcpy(temp1->jenismenu, temp2->jenismenu);
                strcpy(temp2->jenismenu, t); ;

                u = temp1->harga;
                temp1->harga = temp2->harga;
                temp2->harga = u;
            }
        }
    }
}

void menu(){
	system("cls");
	int index = 0;
	struct history a[45];
	struct anak *newNode, *head, *temp, *new1, *count, *nw, *first, *test;
	int i,banyak, flag, yakin2;
	node *searchNode = head;
	int xx;
	char yy, zz, aa, yakin, menu;
	char value[45];
	struct anak *start = NULL;
	int bb;
	int pilihan, hapus, pilihan2;
	int perulangan = 1;
	while (perulangan == 1){
		system("cls");
		system("color C7");
		gotoxy(30,5);
		printf("+=============================================================+\n\n");
		gotoxy(30,10);
		printf("+-------------------------------------------------------------+\n\n");
		gotoxy(30,25);
		printf("+=============================================================+\n\n");
		char sambutan[] = {'S', 'E', 'L', 'A', 'M', 'A', 'T', ' ', 'D', 'A', 'T', 'A', 'N', 'G', ' ',
						'D', 'I', ' ', 'D', 'A', 'T', 'A', 'B', 'A', 'S', 'E', ' ', 'R', 'E', 'S',
						'T', 'O', 'R', 'A', 'N', '\0'
						};

		gotoxy(44,7);
		for(i = 0; i <36; i++){
			Sleep(10);
			printf("%c", sambutan[i]);
		}
		printf("\n");
		gotoxy(50,8);
		printf("=== DATA RESTORAN ===");
		gotoxy(30,12); printf("|                                                               |\n");
		gotoxy(30,13); printf("|   Tekan 1. Membuat menu                                       |\n");
		gotoxy(30,14); printf("|   Tekan 2. Menampilkan menu                                   |\n");
		gotoxy(30,15); printf("|   Tekan 3. Menambahkan menu baru                              |\n");
		gotoxy(30,16); printf("|   Tekan 4. Menghapus menu                                     |\n");
		gotoxy(30,17); printf("|   Tekan 5. Mengedit menu                                      |\n");
		gotoxy(30,18); printf("|   Tekan 6. Mencari menu                                       |\n");
		gotoxy(30,19); printf("|   Tekan 7. Mengurutkan menu                                   |\n");
        gotoxy(30,20); printf("|   Tekan 8. Cetak data menu                                    |\n");
		gotoxy(30,21); printf("|   Tekan 9. Keluar dari program                                |\n");
		gotoxy(30,22); printf("|                                                               |\n");
		gotoxy(85,23); printf("         |\n");
		gotoxy(30,23); printf("|   Masukkan pilihan Anda : "); scanf("%d", &pilihan);
		struct anak* h = NULL;
		switch(pilihan){
			case 1:
				system("cls");
				system("color 04");
				gotoxy(25,2); printf("+=====================================================================+\n");
				gotoxy(57,4); printf("DATABASE\n");
				gotoxy(46,5); printf(" === Membuat Menu restoran ===");
				gotoxy(25,7); printf("+---------------------------------------------------------------------+\n");
				gotoxy(25,10); printf("+=====================================================================+\n");
				gotoxy(40,8); printf(" Data maksimum yang bisa diinput\t: 5");
				gotoxy(40,9); printf(" Banyak data yang ingin diinput\t\t: "); scanf("%d", &banyak);
				if(banyak >= 5){
					banyak = 5;
					printf("\n\t\t\t\t\t\t\tMaksimal 5!\n");
				}
				buatList(banyak); //u mnbhkn data
				char result[1];
				sprintf(result, "%d", banyak);
				char kal[] = "Admin menambahkan ";
				strcat(kal, result);   //u mnggabungkan 2 buah string kedlm elemen
				strcat(kal, " data");
				a[index].num = index+1;
				for(i=0; i<strlen(kal); i++){  //mnghitung pnjng karakter
					a[index].his[i] = kal[i];
				}
				index++;
				printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
				getch();
				break;

			case 2:
				system("cls");
				system("color 1F");
				char kal_2[] = "Admin melihat data";
				a[index].num = index+1;
				for(i=0; i<strlen(kal_2); i++){
					a[index].his[i] = kal_2[i];
				}
				index++;
				gotoxy(23,2); printf("+=================================================================================+\n");
				gotoxy(55,4); printf("DATA RESTORAN\n");
				gotoxy(48,5); printf("Data menu yang telah diinput");
				gotoxy(23,7); printf("+=================================================================================+\n");
				gotoxy(23,8); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
				printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
				displayList();
				printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
				printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
				getch();
				break;

			case 3:
				system("cls");
				system("color 5");
				gotoxy(25,2); printf("+========================================================================+\n");
				gotoxy(60,4); printf("DATABASE\n");
				gotoxy(46,5); printf(" === Membuat Menu Baru Restoran ===");
				gotoxy(25,7); printf("+------------------------------------------------------------------------+\n");
				gotoxy(25,10); printf("+------------------------------------------------------------------------+\n");
				gotoxy(40,8); printf(" Data maksimum yang bisa diinput\t: 4");
				gotoxy(40,9); printf(" Banyak data yang ingin diinput\t\t: "); scanf("%d", &banyak);
				if(banyak >= 4){
					banyak = 4;
					printf("\n\t\t\t\t\t\t\tMaksimal 4 besti\n");
				}
    			insertData();
    			char result_3[1];
				sprintf(result_3, "%d", banyak); //mnulis string yg di format ke variabel
				char kal_3[] = "Admin menambahkan ";
				strcat(kal_3, result_3);
				strcat(kal_3, " data");
				a[index].num = index+1;
				for(i=0; i<strlen(kal_3); i++){
					a[index].his[i] = kal_3[i];
				}
				index++;
				printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
				getch();
				break;

			case 4:
				system("cls");
				system("color 8");
				gotoxy(25,2); printf("+========================================================================+\n");
				gotoxy(57,4); printf("DATABASE\n");
				gotoxy(46,5); printf(" === Menghapus menu restoran ===");
				gotoxy(25,7); printf("+------------------------------------------------------------------------+\n");
				gotoxy(25,9); printf("+------------------------------------------------------------------------+\n");
				gotoxy(40,8); printf(" Masukkan id menu yang ingin dihapus\t: "); scanf("%d", &hapus);
				yakin2 = search_item(hapus);
				if(yakin2 == 0){
					printf("\n\t\t\t\t\t\tYakin ingin menghapus menu ini? (y/n)");
					yakin = getch();
					if(yakin == 'y' || yakin == 'Y'){
						delete_item(hapus);
						char result_4[10];
						sprintf(result_4, "%d", hapus);
						char kal_4[] = "Admin menghapus menu dengan id menu : ";
						strcat(kal_4, result_4);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_4); i++){
							a[index].his[i] = kal_4[i];
						}
						index++;
					}
					else if(yakin == 'n' || yakin == 'N'){}
					printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
					getch();
					}
				else{
					printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
					getch();
				}
				break;

			case 5:
				system("cls");
				system("color B0");
				gotoxy(25,2); printf("+========================================================================+\n");
				gotoxy(57,4); printf("DATABASE\n");
				gotoxy(46,5); printf(" === Mengubah menu restoran ===");
				gotoxy(25,7); printf("+------------------------------------------------------------------------+\n");
				gotoxy(25,14);printf("+------------------------------------------------------------------------+\n");
				gotoxy(38,8); printf("Apa yang ingin Anda edit?");
				gotoxy(38,9); printf("1. Nama menu \t 3. Jenis menu");
				gotoxy(38,10); printf("2. Porsi \t\t 4. Harga ");
				gotoxy(38,12); printf("Pilihan Anda\t: ");
				gotoxy(38,13); printf("Masukkan id menu\t: ");
				gotoxy(60, 12); scanf("%d", &pilihan2);
				gotoxy(60, 13); scanf("%d", &menu);
				switch(pilihan2){
					case 1:
						printf("\n\t\t\t\t\t\t UBAH DATA NAMA MENU");
						search_namamenu(menu);
						char result_5_1[10];
						sprintf(result_5_1, "%d", menu);
						char kal_5_1[] = "nama menu yang akan dirubah  ";
						strcat(kal_5_1, result_5_1);
						strcat(kal_5_1, " dirubah menjadi ");
						strcat(kal_5_1, hehehe);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_5_1); i++){
							a[index].his[i] = kal_5_1[i];
						}
						index++;
						break;
					case 2:
						printf("\n\t\t\t\t\t\t UBAH DATA PORSI");
						search_porsi(menu);
						char result_5_2[10];
						sprintf(result_5_2, "%d", menu);
						char kal_5_2[] = "porsi menu yang akan dirubah ";
						strcat(kal_5_2, result_5_2);
						strcat(kal_5_2, " dirubah menjadi ");
						strcat(kal_5_2, hehehe);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_5_2); i++){
							a[index].his[i] = kal_5_2[i];
						}
						index++;
						break;
					case 3:
						printf("\n\t\t\t\t\t\t UBAH DATA JENIS MENU");
						search_jenismenu(menu);
						char result_5_3[10];
						sprintf(result_5_3, "%d", menu);
						char kal_5_3[] = "jenis menu yang akan dirubah ";
						strcat(kal_5_3, result_5_3);
						strcat(kal_5_3, " dirubah menjadi ");
						strcat(kal_5_3, hehehe);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_5_3); i++){
							a[index].his[i] = kal_5_3[i];
						}
						index++;
						break;
					case 4:
						printf("\n\t\t\t\t\t\t UBAH HARGA");
						search_harga(menu);
						char result_5_4[10];
						sprintf(result_5_4, "%d", menu);
						char kal_5_4[] = "harga menu dengan id ";
						strcat(kal_5_4, result_5_4);
						strcat(kal_5_4, " dirubah menjadi ");
						strcat(kal_5_4, hehehe);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_5_4); i++){
							a[index].his[i] = kal_5_4[i];
						}
						index++;
						break;
					default:
						break;
				}
				printf("\n\n\t\t\t\t\t\tKlik enter untuk lanjut");
				getch();
				break;

			case 6:
				system("cls");
				system("color D");
				gotoxy(25,2); printf("+========================================================================+\n");
				gotoxy(60,4); printf("DATABASE\n");
				gotoxy(46,5); printf(" === Mencari data menu restoran ===");
				gotoxy(25,7); printf("+------------------------------------------------------------------------+\n");
				gotoxy(25,15); printf("+------------------------------------------------------------------------+\n");
				gotoxy(38,8); printf("Apa yang ingin Anda cari?");
				gotoxy(38,9); printf("1. Nama Menu  \t 3. Jenis Menu");
				gotoxy(38,10); printf("2. Porsi \t\t 4. Harga ");
				gotoxy(38,11); printf("5. ID menu");
				gotoxy(38,13); printf("Pilihan Anda\t\t: ");
				gotoxy(66, 13); scanf("%d", &pilihan2);
				switch(pilihan2){
					case 1:
						gotoxy(38,14); printf("nama menu yang dicari\t: "); scanf(" %[^\n]", value);
						menu6_1(value);
						char kal_6_1[] = "Admin mencari nama menu : ";
						strcat(kal_6_1, value);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_6_1); i++){
							a[index].his[i] = kal_6_1[i];
						}
						index++;
						getch();
						break;
					case 2:
						gotoxy(38,14); printf("porsi yang dicari\t: "); scanf(" %[^\n]", value);
						menu6_2(value);
						char kal_6_2[] = "Admin mencari porsi : ";
						strcat(kal_6_2, value);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_6_2); i++){
							a[index].his[i] = kal_6_2[i];
						}
						index++;
						getch();
						break;
					case 3:
						gotoxy(38,14); printf("jenis menu yang dicari\t: "); scanf(" %[^\n]", value);
						menu6_3(value);
						char kal_6_3[] = "Admin mencari jenis menu : ";
						strcat(kal_6_3, value);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_6_3); i++){
							a[index].his[i] = kal_6_3[i];
						}
						index++;
						getch();
						break;
					case 4:
						gotoxy(38,14); printf("harga menu yang dicari\t: "); scanf("%d", &bb);
						menu6_4(bb);
						char result_6_4[10];
						sprintf(result_6_4, "%d", bb);
						char kal_6_4[] = "Admin mencari harga menu : ";
						strcat(kal_6_4, result_6_4);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_6_4); i++){
							a[index].his[i] = kal_6_4[i];
						}
						index++;
						getch();
						break;
					case 5:
						gotoxy(38,14); printf("id menu yang dicari\t: "); scanf("%d", &xx);
						menu6_5(xx);
						char result_6_5[10];
						sprintf(result_6_5, "%d", menu);
						char kal_6_5[] = "Admin mencari menu dengan id menu : ";
						strcat(kal_6_5, result_6_5);
						a[index].num = index+1;
						for(i=0; i<strlen(kal_6_5); i++){
							a[index].his[i] = kal_6_5[i];
						}
						index++;
						getch();
						break;
					default:
						break;
				}
				break;

			case 7:
				system("cls");
				system("color 3");
				gotoxy(25,2); printf("+========================================================================+\n");
				gotoxy(62,4); printf("DATABASE\n");
				gotoxy(46,5); printf(" === Urutkan data menu RESTORAN ===");
				gotoxy(25,7); printf("+------------------------------------------------------------------------+\n");
				gotoxy(25,15); printf("+------------------------------------------------------------------------+\n");
				gotoxy(38,8); printf("Apa yang ingin Anda urutkan?");
				gotoxy(38,9); printf("1. Nama menu  \t 3. Jenis menu");
				gotoxy(38,10); printf("2. Porsi \t\t 4. Harga ");
				gotoxy(38,11); printf("5. ID menu");
				gotoxy(38,13); printf("Pilihan Anda\t\t: ");
				gotoxy(66, 13); scanf("%d", &pilihan2);
				switch(pilihan2){
					case 1:
						sortnamamenu();
						system("cls");
 						gotoxy(23,2); printf("+=================================================================================+\n");
						gotoxy(62,4); printf("DATA RESTORAN\n");
						gotoxy(54,5); printf("Nama menu yang telah diinput");
						gotoxy(23,7); printf("+=================================================================================+\n");
						gotoxy(23,8); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						displayList();
						char kal_8_1[] = "Admin mengurutkan data berdasarkan nama menu";
						a[index].num = index+1;
						for(i=0; i<40; i++){
							a[index].his[i] = kal_8_1[i];
						}
						index++;
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
						getch();
						break;
					case 2:
						sortporsi();
						system("cls");
 						gotoxy(23,2); printf("+=================================================================================+\n");
						gotoxy(62,4); printf("DATA RESTORAN\n");
						gotoxy(56,5); printf("Porsi yang telah diinput");
						gotoxy(23,7); printf("+=================================================================================+\n");
						gotoxy(23,8); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						displayList();
						char kal_8_2[] = "Admin mengurutkan data berdasarkan porsi";
						a[index].num = index+1;
						for(i=0; i<40; i++){
							a[index].his[i] = kal_8_2[i];
						}
						index++;
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
						getch();
						break;
					case 3:
						sortjenismenu();
						system("cls");
 						gotoxy(23,2); printf("+=================================================================================+\n");
						gotoxy(62,4); printf("DATA RESTORAN\n");
						gotoxy(54,5); printf("Jenis menu yang telah diinput");
						gotoxy(23,7); printf("+=================================================================================+\n");
						gotoxy(23,8); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						displayList();
						char kal_8_3[] = "Admin mengurutkan data berdasarkan jenis menu";
						a[index].num = index+1;
						for(i=0; i<45; i++){
							a[index].his[i] = kal_8_3[i];
						}
						index++;
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
						getch();
						break;
					case 4:
						sortharga();
 						system("cls");
 						gotoxy(23,2); printf("+=================================================================================+\n");
						gotoxy(62,4); printf("DATA RESTORAN\n");
						gotoxy(54,5); printf("Harga menu yang telah diinput");
						gotoxy(23,7); printf("+=================================================================================+\n");
						gotoxy(23,8); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						displayList();
						char kal_8_4[] = "Admin mengurutkan data berdasarkan harga ";
						a[index].num = index+1;
						for(i=0; i<45; i++){
							a[index].his[i] = kal_8_4[i];
						}
						index++;
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
						getch();
						break;
					case 5:
 						sortidmenu();
 						system("cls");
 						gotoxy(23,2); printf("+=================================================================================+\n");
						gotoxy(62,4); printf("DATA RESTORAN\n");
						gotoxy(56,5); printf("ID menu yang telah diinput");
						gotoxy(23,7); printf("+=================================================================================+\n");
						gotoxy(23,8); printf("ID MENU \t\t NAMA MENU \t\t PORSI \t\t JENIS MENU \t HARGA");
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						displayList();
						char kal_8_5[] = "Admin mengurutkan data berdasarkan id menu";
						a[index].num = index+1;
						for(i=0; i<47; i++){
							a[index].his[i] = kal_8_5[i];
						}
						index++;
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
						getch();
						break;

					default:
						printf("\n\t\t       +---------------------------------------------------------------------------------+\n");
						printf("\n\t\t\t\t\t\tInput salah");
						printf("\n\t\t\t\t\t\tKlik enter untuk lanjut");
						getch();
						break;
				}
				break;

            case 8:
               system("cls");
               printList();

			case 9:
				menu9();

				perulangan++;
				break;

			default:
				printf("\n\n\t\t\t\t\t\t\tInput salah");
				printf("\n\t\t\t\t\t\tKlik terserah untuk lanjut");
				getch();
				break;
		}
	}
}

void main(){
    login();
    menu();
}
