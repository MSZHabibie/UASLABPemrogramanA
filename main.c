#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct info
{
	char username[10];
	char password[10];
}terkini;
typedef struct User
{
	char nama[20];
	char id[5];
	char alamat[20];
	char lahir[15];
	char hp[15];
}pelanggan;

terkini admin;											
pelanggan pengguna[10];

pelanggan addPengguna();									//untuk input data pengguna
terkini getAdmin();											//untuk input id admin

int main()
{
	char fa[] = "Data\\login.bin";							//agar dapat mengambil dari file directory
	char fb[] = "Data\\data.txt";
	int ia, ib, ic = 0, ie;
	char ca[10], cb[10], cc[10], cd[10], ce[10], cg[10], ch[10], ci[10];
	char cj, ck, cl, cm, cn, co, cp[10], cq;
	const char cca[] = "menikah", ccb[] = "Menikah";		//sebagai syarat buat ID admin

	do
	{
		FILE *bf;
		bf = fopen("Data\\login.bin", "rb"); 				//buka binary untuk baca aja
		fread(&admin, sizeof(struct info), 1, bf);
		printf("+-/:+-/:+-/:+-/:+-/::\\-+:\\-+:\\-+:\\-+:\\-+\n");
		printf("|                H.MAIL                |\n");
		printf("|          @email kita semua@          |\n");
		printf("+-/:+-/:+-/:+-/:+-/::\\-+:\\-+:\\-+:\\-+:\\-+\n\n");
		printf("Login Akun H.Mail :\n");
		printf("Username : ");
		scanf(" %s", ca);
		printf("Password : ");
		scanf(" %s", cb);
	
		if ((strcmp(admin.username, ca) != 0) || (strcmp(admin.password, cb) != 0))		//syarat apabila nilai pada struct belum ada atau sudah ada tapi salah satu dari variabel struct nya tidak sama
		{
			printf("Status : Username atau Password Salah\n\n");
			printf("Belum Punya Akun Admin? kuy buat disini [Y/N] : ");
			scanf(" %c", &co);
			if (co == 'y' || co == 'Y')
			{
				admin = getAdmin();
				printf("Usia : ");
				scanf(" %d", &ib);
				printf("Status : ");
				scanf(" %s", cp);

				if ((ib >= 18 && strcmp(cp, cca) == 0) || (ib >= 18 && strcmp(cp, ccb) == 0))  //syarat agar ID admin terbuat
				{
					fclose(bf);
					bf = fopen(fa, "wb");												//buka binary untuk buat Id Admin
					fread(&admin, sizeof(struct info), 1, bf);
					fwrite(&admin, sizeof(struct info), 1, bf);

					printf("Selamat Akun Anda Berhasil Dibuat\n\n");
				}
				else
				{
					printf("\nMaaf Anda Tidak Memenuhi Kriteria Admin :\n");					//kalau misalnya tidak memenuhi kriteria
					printf("#Usia >= 18\n");
					printf("#Status >= Menikah\n\n");
				}
			}
			
		}
		else
		{
			printf("\nStatus : Login Berhasil\n\n");

			FILE *tf;
			tf = fopen(fb, "r");					//untuk membaca text
			fscanf(tf, "%s, %s, %s, %s, %s\n", pengguna->nama, pengguna->id, pengguna->alamat, pengguna->lahir, pengguna->hp);

			do
			{
				printf("MENU :\n");
				printf("1. Tampilan Data Pengguna\n");
				printf("2. Cari Data Pengguna\n");
				printf("3. Tambah Data Pengguna\n");
				printf("4. Hapus Data Pengguna\n");
				printf("5. Ubah Data Pengguna\n");
				printf("6. Ubah Password Admin\n");
				printf("7. Ke Halaman Login\n");
				printf("8. Keluar Program\n\n");
				printf("Pilihan : ");
				scanf(" %d", &ia);

				if (ia == 7 || ia == 8)					//biar langsung keluar dari loop balik ke menu utama
				{
					break;
				}
				switch(ia)
				{
					case 1:
						printf("DATA PENGGUNA\n");
						printf("+====+======+======================+======================+================+================+\n");
						printf("| NO | %-5s| %-20s | %-20s | %-15s| %-15s|\n", "ID", "Nama", "Alamat", "Tanggal Lahir", "No.HP");					//untuk header
						printf("+====+======+======================+======================+================+================+\n");
						for (int i = 1; i <= ic; ++i)																								//looping untuk menampilkan sebanyak data yang ada
						{
							printf("| %2d | %-5s| %-20s | %-20s | %-15s| %-15s|\n", i, pengguna[i].id, pengguna[i].nama, pengguna[i].alamat, pengguna[i].lahir, pengguna[i].hp); //%-20d untuk ratain tabel
						}
						printf("+====+======+======================+======================+================+================+\n\n");
					continue;

					case 2:
						printf("CARI DATA PENGGUNA\n");
						printf("ID : ");
						scanf(" %s", cc);
						for (int i = 0; i <= ic; ++i)						//cari sebanyak data yang ada
						{
							if (strcmp(pengguna[i].id, cc) == 0)			//mencari data yang sama dengan yang dicari
							{
								strcpy(ch, "ada");							//variabel pembantu untuk mengetahui ada apa tidak data yang dicari
								printf("Hasil Pencarian : \n");
								printf("+====+======+======================+======================+================+================+\n");
								printf("| NO | %-5s| %-20s | %-20s | %-15s| %-15s|\n", "ID", "Nama", "Alamat", "Tanggal Lahir", "No.HP");					//untuk header
								printf("+====+======+======================+======================+================+================+\n");
								printf("| %2d | %-5s| %-20s | %-20s | %-15s| %-15s|\n", i, pengguna[i].id, pengguna[i].nama, pengguna[i].alamat, pengguna[i].lahir, pengguna[i].hp);	
								printf("+====+======+======================+======================+================+================+\n\n");
							}
						}
						if (strcmp(ch, "ada") != 0)							//kalau gk ada berarti gk ada data di directory
						{
							printf("Mohon Maaf Data Yang Dicari Tidak Ada\n\n");
						}
					continue;
					
					case 3:
						fclose(tf);
						tf = fopen(fb, "w");			//untuk menambah data ke file text
						fscanf(tf, "%s, %s, %s, %s, %s\n", pengguna->nama, pengguna->id, pengguna->alamat, pengguna->lahir, pengguna->hp);
						printf("TAMBAH DATA PENGGUNA\n");						
						printf("Jumlah Data Yang Ingin Ditambahkan : ");
						scanf(" %d", &ic);
						for (int i = 1; i <= ic; ++i)
						{
							pengguna[i] = addPengguna();
							fprintf(tf, "%s, %s, %s, %s, %s\n", pengguna[i].nama, pengguna[i].id, pengguna[i].alamat, pengguna[i].lahir, pengguna[i].hp);
							
						}
						printf("Status : Data Berhasil Ditambahkan\n\n");

					break;
					
					case 4:
						fclose(tf);
						tf = fopen(fb, "w");				
						fscanf(tf, "%s, %s, %s, %s, %s\n", pengguna->nama, pengguna->id, pengguna->alamat, pengguna->lahir, pengguna->hp);
						
						printf("HAPUS DATA PENGGUNA\n");
						printf("ID : ");
						scanf(" %s", cd);

						printf("Yakin Ingin Menghapus %s ? [Y/N] : ", cc);
						scanf(" %c", &cj);
						if (cj == 'y' || cj == 'Y')
						{
							for (int i = 1; i <= ic; ++i)
							{
								if (strcmp(pengguna[i].id, cd) == 0)				//mencari data yang akan dihapus
								{
									for (int j = i; j <= 10; ++j)
									{
										strcpy(cg, "ada");												//penanda kalau data ditemukann
										strcpy(pengguna[i].nama, pengguna[i + 1].nama);					//penggeseran indeks
										strcpy(pengguna[i].id, pengguna[i + 1].id);
										strcpy(pengguna[i].alamat, pengguna[i + 1].alamat);
										strcpy(pengguna[i].lahir, pengguna[i + 1].lahir);
										strcpy(pengguna[i].hp, pengguna[i + 1].hp);
										fprintf(tf, "%s, %s, %s, %s, %s\n", pengguna[i].nama, pengguna[i].id, pengguna[i].alamat, pengguna[i].lahir, pengguna[i].hp);
									}
								}
							}
							if (strcmp(cg, "ada") == 0)
							{
								printf("Status : Data Berhasil Dihapus\n\n");
							}
							else
							{
								printf("Status : Data Tidak Ditemukan\n\n");
							}
							
						}
					continue;
					
					case 5:
						fclose(tf);
						tf = fopen(fb, "w");
						fscanf(tf, "%s, %s, %s, %s, %s\n", pengguna->nama, pengguna->id, pengguna->alamat, pengguna->lahir, pengguna->hp);
		
						printf("UBAH DATA PENGGUNA\n");
						printf("ID : ");
						scanf(" %s", ce);

						int i;
						for (i = 1; i <= ic; ++i)
						{
							if (strcmp(pengguna[i].id, ce) == 0)				//untuk mencari data yang ingin diubah
							{
								printf("Apakah Ingin Mengubah ID [Y/N] : ");
								scanf(" %c", &ck);
								if (ck == 'y' || ck == 'Y')
								{
									printf("ID : ");
									scanf(" %s", pengguna[i].id);

								}
								printf("Apakah Ingin Mengubah Nama [Y/N] : ");
								scanf(" %c", &cl);
								if (cl == 'y' || cl == 'Y')
								{
									printf("Nama : ");
									scanf(" %s", pengguna[i].nama);
								}
								printf("Apakah Ingin Mengubah Alamat [Y/N] : ");
									scanf(" %c", &cm);
								if (cm == 'y' || cm == 'Y')
									{
									printf("Alamat : ");
									scanf(" %s", pengguna[i].alamat);
								}
								printf("Apakah Ingin Mengubah Tanggal Lahir [Y/N] : ");
								scanf(" %c", &cn);
								if (cn == 'y' || cn == 'Y')
								{
									printf("Tanggal Lahir : ");
									scanf(" %s", pengguna[i].lahir);
								}
								printf("Apakah Ingin Mengubah No.HP? [Y/N] : ");
								scanf(" %c", &cq);
								if (cq == 'y' || cq == 'Y')
								{
									printf("No.HP : ");
									scanf(" %s", pengguna[i].hp);
								}
								fprintf(tf, "%s, %s, %s, %s, %s\n", pengguna[i].nama, pengguna[i].id, pengguna[i].alamat, pengguna[i].lahir, pengguna[i].hp);
							}
						}		

						if (ck == 'y' || cl == 'y' || cm == 'y' || cn == 'y' || cq == 'y' || ck == 'Y' || cl == 'Y' || cm == 'Y' || cn == 'Y' || cq == 'Y') //jika salah satu y/Y maka pasti ada yang berubah
						{
							printf("\nStatus : Data Berhasil Di Ubah\n\n");
							ck = cl = cm = cn = cq = '\0';										//untuk merefresh setelah keluar looping agar datanya tidak tetap tersimpan 'y'
						}
						else
						{
							printf("\nStatus : Tidak Ada Data Yang Di Ubah\n\n");
						}
					continue;
					
					case 6:
						fclose(bf);
						bf = fopen(fa, "w");										//buka binary untuk ubah password
						fread(&admin, sizeof(struct info), 1, bf);

						printf("UBAH PASSWORD ADMIN\n");
						printf("Password : ");
						scanf(" %s", ci);
						printf("Berapa Umur Admin Saat Mendaftar?\n");
						scanf(" %d", &ie);
						if (ie == ib)												//untuk verifikasi agar yang ubah bukan orang lain
						{
							strcpy(admin.password, ci);
							fwrite(&admin, sizeof(struct info), 1, bf);	
							printf("Password Berhasil Diubah\n\n");
						}
						else
						{
							printf("Silahkan Coba Lagi\n\n");
						}
					continue;

					default:
						printf("Pilihan Tidak Ada Di Menu\n\n");
					continue;
				}
			}while(ia != 7);			//untuk keluar dari loop jika ketemu 7
			if (ia == 8)				//setelah keluar ke menu utama keluar lagi ke luar
			{
				break;
			}
		}
	}while(1);	
	return 0;
}

terkini getAdmin()
{
	terkini admins; 
	printf("Username : ");
	scanf(" %s", admins.username);
	printf("Password : ");
	scanf(" %s", admins.password);
	return admins;
}
pelanggan addPengguna()
{
	pelanggan penggunas;
	printf("Nama		: ");
	scanf(" %[^\n]s", penggunas.nama);
	printf("ID		: ");
	scanf(" %s", penggunas.id);
	printf("Alamat 		: ");
	scanf(" %[^\n]s", penggunas.alamat);
	printf("Tanggal Lahir 	: ");
	scanf(" %s", penggunas.lahir);
	printf("No.HP 		: ");
	scanf(" %s", penggunas.hp);
	return penggunas;	
}