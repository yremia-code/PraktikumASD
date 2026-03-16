#include <stdio.h>
#define M 999
#define MAX 5

int graph[MAX][MAX] = {
    {0, 1, 3, M, M}, // dari node 1
    {M, 0, 1, M, 5}, // dari node 2
    {3, M, 0, 2, M}, // dari node 3
    {M, M, M, 0, 1}, // dari node 4
    {M, M, M, M, 0}  // dari node 5
};

void dijkstra(int graph[MAX][MAX], int n, int start, int end);
void warshall(int graph[MAX][MAX], int n, int start, int end);

int main()
{
    int start_input, end_input;
    char pilihan;
    printf("=== GRAF DAN PENELUSURAN JALUR ===\n");

    do {
    printf("Graf memiliki 5 simpul (1-5).\n");

    printf("Masukkan simpul awal (1-5): ");
    scanf("%d", &start_input);
    printf("Masukkan simpul tujuan (1-5): ");
    scanf("%d", &end_input);

    // Konversi ke indeks array
    int start = start_input - 1;
    int end = end_input - 1;

    printf("\n=== DIJKSTRA ===\n");
    dijkstra(graph, MAX, start, end);

    printf("\n=== WARSHALL ===\n");
    warshall(graph, MAX, start, end);

    printf("\nApakah Anda ingin mencoba lagi? (T/t untuk keluar): ");
    scanf(" %c", &pilihan);
    getchar(); 
    } while (pilihan != 'T' && pilihan != 't');

    return 0;
}

// ---------------------------- DIJKSTRA ----------------------------
void dijkstra(int graph[MAX][MAX], int n, int start, int end)
{
    int distance[MAX], visited[MAX] = {0}, parent[MAX];
    int i, j, min, next;

    for (i = 0; i < n; i++)
    {
        distance[i] = graph[start][i];
        if (graph[start][i] < M && i != start)
            parent[i] = start;
        else
            parent[i] = -1;
    }
    visited[start] = 1;
    distance[start] = 0;

    for (i = 1; i < n; i++)
    {
        min = M;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < min)
            {
                min = distance[j];
                next = j;
            }
        }

        visited[next] = 1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[next] + graph[next][j] < distance[j])
            {
                distance[j] = distance[next] + graph[next][j];
                parent[j] = next;
            }
        }
    }

    if (distance[end] == M)
    {
        printf("Tidak ada jalur dari %d ke %d\n", start + 1, end + 1);
    }
    else
    {
        printf("Jarak terpendek dari %d ke %d adalah %d\n", start + 1, end + 1, distance[end]);
        printf("Jalur: ");
        int path[MAX], count = 0;
        for (i = end; i != -1; i = parent[i])
            path[count++] = i;
        for (i = count - 1; i >= 0; i--)
            printf("%d%s", path[i] + 1, (i == 0 ? "\n" : " -> "));
    }
}

// -------------------------- WARSHALL -----------------------------
void warshall(int graph[MAX][MAX], int n, int start, int end)
{
    int dist[MAX][MAX];
    int i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    if (dist[start][end] == M)
    {
        printf("Tidak ada jalur dari %d ke %d\n", start + 1, end + 1);
    }
    else
    {
        printf("Jarak terpendek dari %d ke %d adalah %d\n", start + 1, end + 1, dist[start][end]);
    }

    // Menampilkan matriks jarak terpendek
    printf("\nMatriks jarak terpendek antar semua simpul:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == M)
                printf("  M ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}