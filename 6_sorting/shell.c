    #include <stdio.h>
    #include <stdlib.h>

    void printArr(int data[], int jml_elemen);
    void shell(int data[], int jml_elemen);

    int main(void)
    {
        int data[10] = {95, 23, 56, 12, 41, 59, 19, 72, 57, 29};

        // Mendapatkan banyaknya jumlah elemen
        int jarak = sizeof(data) / sizeof(data[0]);

        puts("ALGORITMA SHELL SORTING");

        // Menampilkan list data array sebelum proses sorting
        printf("List data sebelum sorting : ");
        printArr(data, jarak);

        // Menjalankan proses sorting
        shell(data, jarak);

        // Menampilkan list data array setelah proses sorting
        printf("\nList data setelah sorting : ");
        printArr(data, jarak);

        return 0;
    }

    void printArr(int data[], int jml_elemen)
    {
        for (int i = 0; i < jml_elemen; i++)
        {
            printf("%d ", data[i]);
        }
    }

    void shell(int data[], int jml_elemen)
    {
        // Loop untuk menentukan interval/gap (dimulai dari setengah panjang array)
        for (int interval = jml_elemen / 2; interval > 0; interval /= 2)
        {
            // Loop pertama : melakukan insertion sort untuk setiap interval
            for (int i = interval; i < jml_elemen; i++)
            {
                // Simpan nilai elemen saat ini untuk dibandingkan
                int tempvar = data[i];
                int j;

                // Loop kedua : bandingkan dan geser elemen dengan jarak interval
                for (j = i; j >= interval && data[j - interval] > tempvar; j -= interval)
                {
                    // Geser elemen ke kanan sebesar interval
                    data[j] = data[j - interval];
                    
                }
                // Tempatkan nilai sementara pada posisi yang tepat
                data[j] = tempvar;
            }
        }
    }