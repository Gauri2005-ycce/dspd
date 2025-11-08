#include <stdio.h>
int* binarySearch(int arr[], int n, int key) 
{
    if (arr == NULL || n == 0) 
	{
        printf("NULL\n");
        return NULL;
    }
    int start = 0, end = n - 1, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        printf("Middle value: %d (Index %d)\n", arr[mid], mid);
        if (arr[mid] == key) 
		{
            printf("Found at index %d\n", mid);
            return &arr[mid];
        } else if (key > arr[mid]) {
            printf("Key greater, move start to index %d\n", mid + 1);
            start = mid + 1;
        } 
		else 
		{
            printf("Key smaller, move end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }
    printf("NULL\n");
    return NULL;
}
int main() 
{
    int n, key, i, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    binarySearch(arr, n, key);
    return 0;
}
