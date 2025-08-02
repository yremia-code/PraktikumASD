#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int No;
    char Nama[50];
    int Nilai;
} mhs;

mhs dataMhs[30];
int jumlah_data;

void isi_data()
{
    static int counter = 0;

    if (counter < jumlah_data)
    {
        puts(" ");
        printf("Mahaiswa ke-%d\n", counter + 1);
        dataMhs[counter].No = counter + 1;

        printf("Masukkan Nama   : ");
        scanf(" %s[^\n]", dataMhs[counter].Nama);

        printf("Masukkan nilai  : ");
        scanf("%d", &dataMhs[counter].Nilai);

        counter++;
    }
}

void tampil_data()
{
    puts(" ");
    printf("\nData Mahasiswa\n");
    printf("No \t Nama \t\t Nilai\n");
    for (int i = 0; i < jumlah_data; i++)
    {
        printf("%d \t %s \t\t %d", dataMhs[i].No, dataMhs[i].Nama, dataMhs[i].Nilai);
        puts(" ");
    }
}

void sequential_no()
{
    int search_no;

    puts(" ");
    printf("Masukkan nomor yang dicari : ");
    scanf("%d", &search_no);

    for (int i = 0; i < jumlah_data; i++)
    {
        if (dataMhs[i].No == search_no)
        {
            puts(" ");
            printf("\nData ditemukan pada indeks %d\n", i);
            return;
        }
    }
    puts(" ");
    printf("Data tidak ditemukan\n");
}

void sequential_nama()
{
    char search_nama[50];

    puts(" ");
    printf("Masukkan nama yang dicari : ");
    scanf(" %s[^\n]", search_nama);

    for (int i = 0; i < jumlah_data; i++)
    {
        if (strcmp(dataMhs[i].Nama, search_nama) == 0)
        {
            puts(" ");
            printf("Data ditemukan pada indeks %d\n", i);
            return;
        }
    }

    puts(" ");
    printf("Data tidak ditemukan\n");
}

void sort_nama()
{
    for (int i = 0; i < jumlah_data - 1; i++)
    {
        for (int j = 0; j < jumlah_data - i - 1; j++)
        {
            if (strcmp(dataMhs[j].Nama, dataMhs[j + 1].Nama) > 0)
            {
                mhs temp = dataMhs[j];
                dataMhs[j] = dataMhs[j + 1];
                dataMhs[j + 1] = temp;
            }
        }
    }
}

void sort_no()
{
    for (int i = 0; i < jumlah_data - 1; i++)
    {
        for (int j = 0; j < jumlah_data - i - 1; j++)
        {
            if (dataMhs[j].No > dataMhs[j + 1].No)
            {
                mhs temp = dataMhs[j];
                dataMhs[j] = dataMhs[j + 1];
                dataMhs[j + 1] = temp;
            }
        }
    }
}

void binarySearchNama()
{
    char search_nama[50];

    puts(" ");
    printf("Masukkan nama yang dicari : ");
    scanf(" %s[^\n]", search_nama);

    int left = 0, right = jumlah_data - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (strcmp(dataMhs[mid].Nama, search_nama) == 0)
        {
            puts(" ");
            printf("Data ditemukan pada indeks %d\n", mid);
            return;
        }

        if (strcmp(dataMhs[mid].Nama, search_nama) < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    puts(" ");
    printf("Data tidak ditemukan\n");
}

void binary_no()
{
    int search_no;

    puts(" ");
    printf("Masukkan nomor yang dicari : ");
    scanf("%d", &search_no);

    int left = 0, right = jumlah_data - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (dataMhs[mid].No == search_no)
        {
            puts(" ");
            printf("Data ditemukan pada indeks %d\n", mid);
            return;
        }

        if (dataMhs[mid].No < search_no)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    puts(" ");
    printf("Data tidak ditemukan\n");
}

int main()
{
    int pilihan;

    printf("Masukkan jumlah mahasiswa : ");
    scanf("%d", &jumlah_data);

    for (int i = 0; i < jumlah_data; i++)
    {
        isi_data();
    }

    do
    {
        puts("\nDAFTAR MENU");
        printf("1. Tampilkan Data\n");
        printf("2. Sequential Search by No\n");
        printf("3. Sequential Search by Nama\n");
        printf("4. Binary Search by no\n");
        printf("5. Binary Search by name\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tampil_data();
            break;

        case 2:
            sequential_no();
            break;

        case 3:
            sequential_nama();
            break;

        case 4:
            sort_no();
            binary_no();
            break;

        case 5:
            sort_nama();
            binarySearchNama();
            break;

        case 6:
            exit(0);

        default:
            printf("Pilihsn tidak valid \n");
        }
    } while (pilihan != 6);

    return 0;
}