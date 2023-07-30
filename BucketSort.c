#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the maximum element in the array
int MaxElement(int array[], int size) 
{  
    int max = 0;  
    for (int i = 0; i < size; i++)
        max = fmax(array[i], max);
			
    return max; 
}

// Function to perform Bucket Sort
void BucketSort(int array[], int size) 
{  
    int max = MaxElement(array, size);
    int bucket[max + 1];

    // Initialize the bucket array with 0
    for (int i = 0; i <= max; i++)  
    	bucket[i] = 0;  
 
    // Count the occurrences of each element in the input array
    for (int i = 0; i < size; i++)
    	bucket[array[i]]++;

    // Sort the elements in the array using the bucket counts
    for (int i = 0, j = 0; i <= max; i++)  
	for (; bucket[i] > 0; (bucket[i])--)
		array[j++] = i;    
}  

int main(void) 
{
    int array[100], i, num;

    printf("Enter the size of the array: ");
    scanf("%d", &num); 
    printf("Enter the %d elements to be sorted:\n",num); 
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]); 
    printf("\nThe array of elements before sorting: \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);  
    printf("\nThe array of elements after sorting: \n"); 
 
    // Calling the Bucket Sort function
    BucketSort(array, num); 
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);   
    printf("\n");     

	return 0;
}
