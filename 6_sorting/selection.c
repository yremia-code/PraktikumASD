#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, temp;

    int deret_bil[10] = {55, 20, 35, 48, 39, 25, 68, 84, 30, 72};

    printf("Deret Bilangan : ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", deret_bil[i]);
    }
    puts(" ");
    puts(" ");

    // Selection Sort algorithm
    for (int i = 0; i < 10; i++)
    {
        min = i; // Assume current element is the minimum
        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < 10; j++)
        {
            if (deret_bil[j] < deret_bil[min])
            {
                min = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = deret_bil[i];
        deret_bil[i] = deret_bil[min];
        deret_bil[min] = temp;

        printf("Sorting ke-%d : ", i+1);
        for (int k = 0; k < 10; k++)
        {
            printf("%d ", deret_bil[k]);
        }
        puts(" "); // Print a newline
    }
}