#include <stdio.h>
#include <stdlib.h>

void printArr(int data[], int jml);
void merge_sort(int data[], int left, int right);
void merge(int data[], int left, int mid, int right);

int main(void)
{
    int data[10] = {95, 23, 56, 12, 41, 59, 19, 72, 57, 29};

    printf("\n");
    puts("MERGE SORTING");
    printf("\n");

    // Menampilkan list data array sebelum proses sorting
    printf("List data sebelum sorting : ");
    printArr(data, 10);

    // Menjalankan proses sorting
    merge_sort(data, 0, 9);
    printf("\n");

    // Menampilkan list data array setelah proses sorting
    printf("List data setelah sorting : ");
    printArr(data, 10);

    return 0;
}

void printArr(int data[], int jml)
{
    for (int i = 0; i < jml; i++)
    {
        printf("%d ", data[i]);
    }
}

void merge_sort(int data[], int left, int right)
{
    // Basis rekursi : hanya proses jika subarray memiliki lebih dari 1 elemen
    if (left < right)
    {
        // Hitung titik tengah untuk membagi array menjadi dua bagian
        int mid = left + (right - left) / 2;

        // Rekursi : urutkan subarray kiri
        merge_sort(data, left, mid);

        // Rekursi : urutkan subarray kanan
        merge_sort(data, mid + 1, right);

        // Gabungan dua subarray yang sudah terurut
        merge(data, left, mid, right);
    }
}

void merge(int data[], int left, int mid, int right)
{
    int i, j, k; // variabel iterator

    // Hitung ukuran dua subarray yang akan digabungkan
    int s1 = mid - left + 1; // Ukuran subarray kiri
    int s2 = right - mid;    // Ukuran subarray kanan

    // Buat array temporer untuk menyimpan dua subaray
    int left_arr[s1];  // Menyimpan subarray kiri
    int right_arr[s2]; // Menyimpan subarray kanan

    // Salin data dari array utama ke subarray kiri
    for (i = 0; i < s1; i++)
    {
        left_arr[i] = data[left + i];
    }

    // Salin data dari array utama ke subarray kanan
    for (j = 0; j < s2; j++)
    {
        right_arr[j] = data[mid + 1 + j];
    }

    // Prses penggabungan dua subarray
    i = 0, j = 0, k = left;

    // Bandingkan elemen dari kedua subarray dan gabungan secara terurut
    while (i < s1 && j < s2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            data[k] = left_arr[i]; // Masukkan elemen dari subarray kiri
            i++;
        }
        else
        {
            data[k] = right_arr[j]; // Masukan elemen dari subarray kanan
            j++;
        }
        k++;
    }

    // Salin sisa elemen dari subarray kiri (jika ada)
    while (i < s1)
    {
        data[k] = left_arr[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari subarray kanan (jika ada)
    while (j < s2)
    {
        data[k] = right_arr[j];
        j++;
        k++;
    }
}