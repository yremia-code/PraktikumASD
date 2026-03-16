#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// deklarasi tipe data
typedef char typeInfo;
typedef struct Node tree;
struct Node
{
    typeInfo info;
    tree *left;
    tree *right;
};

// deklarasi fungsi
int menu_kunjungan();
tree *bentuk(typeInfo value);
void sisip(tree **root, typeInfo value);
void inorderTraversal(tree *root);
void preorderTraversal(tree *root);
void postorderTraversal(tree *root);
tree *cari(tree *root, typeInfo value);

int main(void)
{
    int pilihan;          // untuk menyimpan pilihan menu
    tree *root = NULL;    // pointer ke root tree
    char input[1000];     // untuk menyimpan input dari pengguna
    char mode, cari_data; // untuk menyimpan pilihan mode dan cari data

    printf("MEMBENTUK & MENGUNJUNGI SEBUAH BINARY TREE\n");
    puts(" ");
    printf("Ketikkan sekumpulan data/infonya, pisahkan dengan spasi : ");
    fgets(input, sizeof(input), stdin); // Menggunakan fgets untuk membaca input
    input[strcspn(input, "\n")] = 0;    // Menghapus newline karakter

    char *token = strtok(input, " "); // Memisahkan input berdasarkan spasi
    while (token != NULL)
    {
        typeInfo value = token[0]; // Mengambil karakter pertama dari token
        sisip(&root, value);       // Menyisipkan nilai ke dalam tree
        token = strtok(NULL, " "); // Mengambil token berikutnya
    }

    do
    {
        pilihan = menu_kunjungan(); // Menampilkan menu penelusuran
        switch (pilihan)            // Memilih penelusuran tree
        {
        case 1:
            // Preorder
            printf("\nHasil penelusuran Preorder : ");
            preorderTraversal(root); // Menampilkan hasil penelusuran preorder
            printf("\n");
            break;

        case 2:
            // Postorder
            printf("\nHasil penelusuran Postorder : ");
            postorderTraversal(root); // Menampilkan hasil penelusuran postorder
            printf("\n");
            break;

        case 3:
            // Inorder
            printf("\nHasil penelusuran Inorder : ");
            inorderTraversal(root); // Menampilkan hasil penelusuran inorder
            printf("\n");
            break;

        case 0:
            // Keluar
            printf("\nKeluar dari program\n");
            break;

        default:
            // Pilihan tidak valid
            printf("\nPilihan tidak valid, silakan coba lagi.\n");
            break;
        }
        if (pilihan != 0)
        {
            // Menanyakan apakah ingin mencoba mode lain
            printf("\nMencoba mode yang lain [y/t] ? ");
            scanf(" %c", &mode);
            if (mode == 't' || mode == 'T')
            {
                pilihan = 0; // Keluar dari loop
            }
        }

    } while (pilihan != 0);

    typeInfo cariData;
    do
    {
        // Mencari data dalam tree
        printf("\nMencari data dalam tree..\n");
        printf("Masukkan data yang dicari : ");
        scanf(" %c", &cariData);
        tree *result = cari(root, cariData); // Mencari data dalam tree
        getchar();

        if (result != NULL)
        {
            printf("\nData %c ditemukan dalam tree.\n", cariData); // Menampilkan hasil pencarian
        }
        else
        {
            printf("\nData %c tidak ditemukan dalam tree.\n", cariData); // Menampilkan hasil pencarian
        }
        printf("\nMau mencari data yang lain [y/t] ? ");
        scanf(" %c", &cari_data);
        getchar();
    } while (cari_data != 't' && cari_data != 'T');

    return 0;
}

int menu_kunjungan()
{
    int pilihan;
    // Menampilkan menu penelusuran tree
    printf("\nPilih Penelusuran Tree\n");
    printf("1. Preorder\n");
    printf("2. Postorder\n");
    printf("3. Inorder\n");
    printf("0. Keluar\n");
    printf("Pilihan anda : ");
    scanf("%d", &pilihan);

    return pilihan; // Mengembalikan pilihan pengguna
}

tree *bentuk(typeInfo value)
{
    tree *nodeBaru = (tree *)malloc(sizeof(tree)); // Mengalokasikan memori untuk node baru
    if (nodeBaru == NULL)                          // Memeriksa apakah alokasi memori berhasil
    {
        printf("Gagal mengalokasikan memori untuk node baru.\n"); // Menampilkan pesan kesalahan
        exit(1);
    }
    nodeBaru->info = value; // Mengisi informasi node baru
    nodeBaru->left = NULL;  // Menginisialisasi subtree kiri
    nodeBaru->right = NULL; // Menginisialisasi subtree kanan
    return nodeBaru;        // Mengembalikan pointer ke node baru
}

void sisip(tree **root, typeInfo value)
{
    if (*root == NULL) // Jika tree kosong, buat node baru
    {
        *root = bentuk(value); // Membentuk node baru
    }
    else if (value < (*root)->info) // Jika nilai lebih kecil dari node saat ini
    {
        sisip(&(*root)->left, value); // Sisipkan ke subtree kiri
    }
    else // Jika nilai lebih besar atau sama dengan node saat ini
    {
        sisip(&(*root)->right, value); // Sisipkan ke subtree kanan
    }
}

void inorderTraversal(tree *root)
{
    if (root == NULL) // Jika tree kosong, tidak ada yang perlu dilakukan
    {
        return;
    }
    inorderTraversal(root->left);  // Kunjungi subtree kiri
    printf("%c ", root->info);     // Tampilkan node saat ini
    inorderTraversal(root->right); // Kunjungi subtree kanan
}

void preorderTraversal(tree *root)
{
    if (root == NULL) // Jika tree kosong, tidak ada yang perlu dilakukan
    {
        return;
    }
    printf("%c ", root->info);      // Tampilkan node saat ini
    preorderTraversal(root->left);  // Kunjungi subtree kiri
    preorderTraversal(root->right); // Kunjungi subtree kanan
}

void postorderTraversal(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);  // Kunjungi subtree kiri
    postorderTraversal(root->right); // Kunjungi subtree kanan
    printf("%c ", root->info);       // Tampilkan node saat ini
}

tree *cari(tree *root, typeInfo value)
{
    if (root == NULL || root->info == value) // Jika tree kosong atau nilai ditemukan
        return root;                         // Mengembalikan pointer ke node yang ditemukan
    if (value < root->info)                  // Jika nilai lebih kecil dari node saat ini
        return cari(root->left, value);      // Mencari di subtree kiri
    else                                     // Jika nilai lebih besar dari node saat ini
        return cari(root->right, value);     // Mencari di subtree kanan
}