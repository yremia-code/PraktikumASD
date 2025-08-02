#include <stdio.h>
#include <stdlib.h>

void printArr(int data[], int jml);
void swap(int *a, int *b);
int partition(int data[], int low, int high);
void quicksort(int data[], int low, int high);

int main(void)
{
    int data[] = {95, 23, 56, 12, 41, 59, 19, 72, 57, 29};
    int jml = sizeof(data) / sizeof(data[0]);

    puts(" ");
    puts("QUICK SORT");
    puts(" ");

    // Menampilkan list data array sebelum proses sorting
    printf("List data sebelum sorting : ");
    printArr(data, jml);

    // Menjalankan proses sorting
    quicksort(data, 0, jml - 1);
    puts(" ");

    // Menampilkan list data array setelah proses sorting
    printf("List data setelah sorting : ");
    printArr(data, jml);
}

void printArr(int data[], int jml)
{
    for (int i = 0; i < jml; i++)
    {
        printf("%d ", data[i]);
    }
}

void swap(int *a, int *b)
{
    // Melakukan penukaran tempat
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int data[], int low, int high)
{
    int pivot = data[high]; // Memilih elemen terakhir sebagai pivot
    int i = (low - 1);      // Indeks utuk menandai posisi elemen yang lebih kecil dari pivot

    // loop melalui semua elemen kecuali pivot
    for (int j = low; j <= high - 1; j++)
    {
        // Jika elemen lebih kecil atau sama dengan pivot
        if (data[j] <= pivot)
        {
            i++;                      // Pindahkan penanda elemen
            swap(&data[i], &data[j]); // Tukar elemen saat ini dengan elemen posisi i
        }
    }

    swap(&data[i + 1], &data[high]); // Setelah loop selesai letakan pivot di posisi yang tepat
    return (i + 1);                  // Kembalikan indeks pivot yang sekarang sudah di posisi benar
}

void quicksort(int data[], int low, int high)
{
    // Array untuk menyimpan batas subarray
    int temp[high - low + 1];

    // Penunjuk indeks stack (mulai dari -1, kosong)
    int i = -1;

    temp[++i] = low;  // Push low ke stack
    temp[++i] = high; // Push high ke stack

    // Selama stack tidak kosong
    while (i >= 0)
    {
        high = temp[i--]; // Pop high dari stack
        low = temp[i--];  // Pop low dari stack

        int pi = partition(data, low, high); // Menjalankan funsgi untuk mendapatkan indeks pivot

        if (pi - 1 > low) // Jika subarray kiri ada elemen
        {
            temp[++i] = low;    // Push low
            temp[++i] = pi - 1; // Push high
        }

        if (pi + 1 < high) // Jika subarray kanan ada elemen
        {
            temp[++i] = pi + 1; // Push low
            temp[++i] = high;   // Push high
        }
    }
}