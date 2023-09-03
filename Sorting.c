#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// You can add more sorting algorithms here...

int main()
{
    printf("Welcome to Sorting Algorithm Application!\n");

    int choice, size;

    while (1)
    {
        printf("Choose a sorting algorithm:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
        {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter the size of the array: ");
        scanf("%d", &size);

        int arr[size];
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }

        switch (choice)
        {
        case 1:
            bubbleSort(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            break;
        // Add cases for more sorting algorithms...
        default:
            printf("Invalid choice.\n");
            continue;
        }

        printf("Sorted array: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
