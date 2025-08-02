#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAKS 100000

// Fungsi Umum yang digunakan
int input();
void generate(int data[], int n);
void printArr(int data[], int jml);
void duplicate(int data[], int data_tujuan[], int jml);

// Fungsi untuk Selection Sort & proses sorting
void SelectionSort(int data_selection[], int jml);
void selection_sort(int data[], int jml, int *c, int *s);

// Fungsi untuk Insertion Sort & proses sorting
void InsertionSort(int data[], int jml);
void insertion_sort(int data[], int jml, int *c, int *s);

// Fungsi untuk Bubble Sort & proses sorting
void BubbleSort(int data_bubble[], int jml);
void bubble_sort(int data[], int jml, int *c, int *s);

// Fungsi untuk Shell Sort & proses sorting
void ShellSort(int data_shell[], int jml);
void shell_sort(int data[], int jml, int *c, int *s);

// Fungsi untuk Merge Sort & proses sorting
void MergeSort(int data_merge[], int jml);
void merge_sort(int data[], int left, int right, int *c, int *s);
void merge(int data[], int left, int mid, int right, int *c, int *s);

// Fungsi untuk Quick Sort & proses sorting
void QuickSort(int data_quick[], int jml);
void swap(int *a, int *b, int *s);
int partition(int data[], int low, int high, int *c, int *s);
void quicksort(int data[], int low, int high, int *c, int *s);

int main(void)
{
    // Pembuatan array yang dinamis ukurannya
    int *data_asli = malloc(MAKS * sizeof(int));
    int *data_kerja = malloc(MAKS * sizeof(int));
    int pilihan;

    // Memastikan alokasi memori berhasil
    if (!data_asli || !data_kerja)
    {
        fprintf(stderr, "Gagal mengalokasikan memori\n");
        exit(EXIT_FAILURE);
    }

    int jml = input();        // Memanggil fungsi input untuk jumlah data
    generate(data_asli, jml); // Melakukan random generate number dengan memanggil fungsi

    do
    {
        srand(time(NULL)); // Set waktu NULL

        puts(" ");
        duplicate(data_asli, data_kerja, jml); // Melakukan duplikasi data random ke data kerja yang digunakan sorting

        // printf("List data sebelum sorting : ");
        // printArr(data_asli, jml);
        // puts(" ");

        // Menampilkan menu sorting
        puts("PILIH 1 ALGORITMA");
        puts("1. Selection Sort");
        puts("2. Insertion Sort");
        puts("3. Bubble Sort");
        puts("4. Shell Sort");
        puts("5. Merge Sort");
        puts("6. Quick Sort");
        puts("0. Keluar");
        puts(" ");
        printf("Pilihan Anda : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            SelectionSort(data_kerja, jml); // Memanggil fungsi selection sort
            // printf("List data setelah sorting : ");
            // printArr(data_kerja, jml);
            puts(" ");
            break;

        case 2:
            InsertionSort(data_kerja, jml); // Memanggil fungsi insertion sort
            puts(" ");
            break;

        case 3:
            BubbleSort(data_kerja, jml); // Memanggil fungsi bubble sort
            puts(" ");
            break;

        case 4:
            ShellSort(data_kerja, jml); // Memanggil fungsi shell sort
            puts(" ");
            break;

        case 5:
            MergeSort(data_kerja, jml); // Memanggil fungsi merge sort
            puts(" ");
            break;

        case 6:
            QuickSort(data_kerja, jml); // Memanggil fungsi quick sort
            puts(" ");
            break;

        default:
            break;
        }

    } while (pilihan != 0);

    // Membebaskan memori
    free(data_asli);
    free(data_kerja);

    return 0;
}

int input()
{
    int jml;
    do
    {
        printf("Masukkan jumlah randoman (maks %d): ", MAKS);
        scanf("%d", &jml);
    } while (jml < 1 || jml > MAKS); // Validasi jumlah data
    return jml;
}

void generate(int data[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        data[i] = rand() % 1000; // Melakukan random generate
    }
}

void printArr(int data[], int jml)
{
    for (int i = 0; i < jml; i++)
    {
        printf("%d ", data[i]); // Mencetak data
    }
}

void duplicate(int data[], int data_tujuan[], int jml)
{
    for (int i = 0; i < jml; i++)
    {
        data_tujuan[i] = data[i];
    }
}

void SelectionSort(int data_selection[], int jml)
{
    int c = 0;
    int s = 0;

    clock_t start = clock();                     // Mengambil waktu awal sebelum proses sorting dimulai
    selection_sort(data_selection, jml, &c, &s); // Menjalankan fungsi proses sorting
    clock_t end = clock();                       // Mengambil waktu akhir setelah proses sorting selesai

    // Menghitung waktu eksekusi yang dibutuhkan dengan mengkonversi ke dalam milisecond
    // Menggunakan Konstanta yang menyatakan jumlah clock licks per detik
    double waktu_ms = (long)(end - start) * 1000 / CLOCKS_PER_SEC;

    // Menampilkan hasil pengukuran waktu komputasi, pembandingan, dan penukaran
    printf("\nWaktu Komputasi Selection Sort = %.2f ms", waktu_ms);
    printf("\nTotal Pembandingan            = %d kali", c);
    printf("\nTotal Penukaran               = %d kali", s);
}

void selection_sort(int data[], int jml, int *c, int *s)
{
    int i, min, temp;
    for (i = 0; i < jml; i++)
    {
        min = i;
        for (int j = i + 1; j < jml; j++)
        {
            if (data[j] < data[min])
            {
                (*c)++;
                min = j;
            }
        }
        if (min != i)
        {
            temp = data[i];
            data[i] = data[min];
            data[min] = temp;
            (*s)++;
        }
    }
}

void InsertionSort(int data_insertion[], int jml)
{
    int c = 0;
    int s = 0;

    clock_t start = clock();                     // Mengambil waktu awal sebelum proses sorting dimulai
    insertion_sort(data_insertion, jml, &c, &s); // Menjalankan fungsi proses sorting
    clock_t end = clock();                       // Mengambil waktu akhir setelah proses sorting selesai

    // Menghitung waktu eksekusi yang dibutuhkan dengan mengkonversi ke dalam milisecond
    // Menggunakan konstanta yang menjalankan jumlah clock licks per detik
    double waktu_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    // Menampilkan hasil pengukuran waktu komputasi, pembandingan, dan penukaran
    printf("\nWaktu omputasi Insertion Sort = %.2f ms", waktu_ms);
    printf("\nTotal Pembandingan            = %d kali", c);
    printf("\nTotal Penukaran               = %d kali", s);
}

void insertion_sort(int data[], int jml, int *c, int *s)
{
    for (int i = 1; i < jml; i++)
    {
        int key = data[i]; // Mengambil nilai saat ini sebagai key untuk dibandingkan
        (*s)++;
        int j = i - 1; // Mulai dari elemen sebelum posisi saat ini

        // Geser elemen yang lebih besar dari key ke sebelah kanan
        while (j >= 0) // Selama masih ada elemen sebeumnya dan elemen tersebut lebih besar
        {
            (*c)++;
            if (data[j] > key)
            {
                // Geser elemen ke kanan
                data[j + 1] = data[j];
                (*s)++;
                // Pindah ke elemen sebelumnya
                j--;
            }
            else
            {
                break;
            }
        }
        // Tempatkan key pada posisi yang tepat dalam bagian array
        data[j + 1] = key;
        (*s)++;
    }
}

void BubbleSort(int data_bubble[], int jml)
{

    int c = 0;
    int s = 0;

    clock_t start = clock();               // Mengambil waktu awal sebelum proses sorting dimulai
    bubble_sort(data_bubble, jml, &c, &s); // Menjalankan proses sorting
    clock_t end = clock();                 // Mengambil waktu akhir setelah proses sorting selesai

    // Menghitung waktu eksekusi yang dibutuhkan dengan mengkonversi ke dalam milisecond
    // Menggunakan konstanta yang menjalankan jumlah clock licks per detik
    double waktu_ms = (long)(end - start) * 1000 / CLOCKS_PER_SEC;

    // Menampilkan hasil pengukuran waktu komputasi, pembandingan, dan penukaran
    printf("\nWaktu Komputasi Bubble Sort   = %.2f ms", waktu_ms);
    printf("\nTotal Pembandingan            = %d kali", c);
    printf("\nTotal Penukaran               = %d kali", s);
}

void bubble_sort(int data[], int jml, int *c, int *s)
{
    int i, j;
    // Mengontrol jumlah perulangan sebanyak banyak data
    for (i = 0; i < jml - 1; i++)
    {
        // Pengulangan untuk membandingkan elemen bersebelahan
        // jml - i - 1 karena elemen terbesar sudah di posisi terakhir
        for (j = 0; j < jml - i - 1; j++)
        {
            (*c)++;
            // Jika elemen saat ini lebih besar dari elemen berikutnya
            if (data[j] > data[j + 1])
            {
                // Tukar posisi elemen
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                (*s)++;
            }
        }
    }
}

void ShellSort(int data_shell[], int jml)
{
    int c = 0;
    int s = 0;

    clock_t start = clock();             // Mengambil waktu awal sebelum proses sorting dimulai
    shell_sort(data_shell, jml, &c, &s); // Menjalankan proses sorting
    clock_t end = clock();               // Mengambil waktu akhir setelah proses sorting selesai

    // Menghitung waktu eksekusi yang dibutuhkan dengan mengkonversi ke dalam milisecond
    // Menggunakan konstanta yang menjalankan jumlah clock licks per detik
    double waktu_ms = (long)(end - start) * 1000 / CLOCKS_PER_SEC;

    // Menampilkan hasil pengukuran waktu komputasi, pembandingan, dan penukaran
    printf("\nWaktu Komputasi Shell Sort = %.2f ms", waktu_ms);
    printf("\nTotal Pembandingan            = %d kali", c);
    printf("\nTotal Penukaran               = %d kali", s);
}

void shell_sort(int data[], int jml, int *c, int *s)
{
    // Loop untuk menentukan interval/gap (dimulai dari setengah panjang array)
    for (int interval = jml / 2; interval > 0; interval /= 2)
    {
        // Loop pertama : melakukan insertion sort untuk setiap interval
        for (int i = interval; i < jml; i++)
        {
            // Simpan nilai elemen saat ini untuk dibandingkan
            int tempvar = data[i];
            int j;

            // Loop kedua : bandingkan dan geser elemen dengan jarak interval
            for (j = i; j >= interval && data[j - interval] > tempvar; j -= interval)
            {
                (*c)++;
                // Geser elemen ke kanan sebesar interval
                data[j] = data[j - interval];
                (*s)++;
            }

            (*c)++;
            // Tempatkan nilai sementara pada posisi yang tepat
            data[j] = tempvar;
            if (j != i)
            {
                (*s)++;
            }
        }
    }
}

void MergeSort(int data_merge[], int jml)
{
    int c = 0;
    int s = 0;

    clock_t start = clock();                    // Mengambil waktu awal sebelum proses sorting dimulai
    merge_sort(data_merge, 0, jml - 1, &c, &s); // Menjalankan proses sorting
    clock_t end = clock();                      // Mengambil wamtu akhir setelah proses sorting selesai

    // Menghitung waktu eksekusi yang dibutuhkan dengan mengkonversi ke dalam milisecond
    // Menggunakan konstanta yang menjalankan jumlah clock licks per detik
    double waktu_ms = (long)(end - start) * 1000 / CLOCKS_PER_SEC;

    // Menampilkan hasil pengukuran waktu komputasi, pembandingan, dan penukaran
    printf("\nWaktu komputasi Merge Sort = %.2f ms", waktu_ms);
    printf("\nTotal Pembandingan            = %d kali", c);
    printf("\nTotal Penukaran               = %d kali", s);
}

void merge_sort(int data[], int left, int right, int *c, int *s)
{
    // Basis rekursi : hanya proses jika subarray memiliki lebih dari 1 elemen
    if (left < right)
    {
        // Hitung titik tengah untuk membagi array menjadi dua bagian
        int mid = left + (right - left) / 2;

        // Rekursi : urutkan subarray kiri
        merge_sort(data, left, mid, c, s);

        // Rekursi : urutkan subarray kanan
        merge_sort(data, mid + 1, right, c, s);

        // Gabungan dua subarray yang sudah terurut
        merge(data, left, mid, right, c, s);
    }
}

void merge(int data[], int left, int mid, int right, int *c, int *s)
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
        (*s)++;
    }

    // Salin data dari array utama ke subarray kanan
    for (j = 0; j < s2; j++)
    {
        right_arr[j] = data[mid + 1 + j];
        (*s)++;
    }

    // Prses penggabungan dua subarray
    i = 0, j = 0, k = left;

    // Bandingkan elemen dari kedua subarray dan gabungan secara terurut
    while (i < s1 && j < s2)
    {
        (*c)++;
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
        (*s)++;
        k++;
    }

    // Salin sisa elemen dari subarray kiri (jika ada)
    while (i < s1)
    {
        data[k] = left_arr[i];
        i++;
        k++;
        (*s)++;
    }

    // Salin sisa elemen dari subarray kanan (jika ada)
    while (j < s2)
    {
        data[k] = right_arr[j];
        j++;
        k++;
        (*s)++;
    }
}

void QuickSort(int data_quick[], int jml)
{
    int c = 0;
    int s = 0;

    clock_t start = clock();                   // Mengambil waktu awal sebelum proses sorting dimulai
    quicksort(data_quick, 0, jml - 1, &c, &s); // Menjalankan proses sorting
    clock_t end = clock();                     // Mengambil waktu akhir setelah proses sorting selesai

    // Menghitung waktu eksekusi yang dibutuhkan dengan mengkonversi ke dalam milisecond
    // Menggunakan konstanta yang menjalankan jumlah clock licks per detik
    double waktu_ms = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    // Menampilkan hasil pengukuran waktu komputasi, pembandingan, dan penukaran
    printf("\nWaktu Komputasi Quick Sort = %.2f ms", waktu_ms);
    printf("\nTotal Pembandingan            = %d kali", c);
    printf("\nTotal Penukaran               = %d kali", s);
}

void swap(int *a, int *b, int *s)
{
    // Melakukan penukaran tempat
    int t = *a;
    *a = *b;
    *b = t;
    (*s)++;
}

int partition(int data[], int low, int high, int *c, int *s)
{
    int pivot = data[high]; // Memilih elemen terakhir sebagai pivot
    int i = (low - 1);      // Indeks utuk menandai posisi elemen yang lebih kecil dari pivot

    // loop melalui semua elemen kecuali pivot
    for (int j = low; j <= high - 1; j++)
    {
        (*c)++;
        // Jika elemen lebih kecil atau sama dengan pivot
        if (data[j] <= pivot)
        {
            i++;                         // Pindahkan penanda elemen
            swap(&data[i], &data[j], s); // Tukar elemen saat ini dengan elemen posisi i
        }
    }

    swap(&data[i + 1], &data[high], s); // Setelah loop selesai letakan pivot di posisi yang tepat
    return (i + 1);                     // Kembalikan indeks pivot yang sekarang sudah di posisi benar
}

void quicksort(int data[], int low, int high, int *c, int *s)
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

        int pi = partition(data, low, high, c, s); // Menjalankan funsgi untuk mendapatkan indeks pivot

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