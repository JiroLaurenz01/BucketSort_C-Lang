#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int MaxElement(int array[], int size) 
{  
	//O(n)
    int max = 0;  
    for (int i = 0; i < size; i++)
        max = fmax(array[i], max);
			
    return max; 
}

void BucketSort(int array[], int size) 
{  
    int max = MaxElement(array, size);
    int bucket[max + 1];

	//O(n)
    for (int i = 0; i <= max; i++)  
    	bucket[i] = 0;  
 
	//O(n)
	//COUNTING STAGE
    for (int i = 0; i < size; i++)
    	bucket[array[i]]++;

	//O(n^2)
	//SORTING STAGE
    for (int i = 0, j = 0; i <= max; i++)  
		for (; bucket[i] > 0; (bucket[i])--)
			array[j++] = i;    
}  

int main(void) 
{
	int array[100], i, num; 

	printf("Enter the size of array: ");   
    scanf("%d", &num);   
    printf("Enter the %d elements to be sorted:\n",num); 
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]); 
    printf("\nThe array of elements before sorting: \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);  
    printf("\nThe array of elements after sorting: \n"); 
 
    // Calling bucket sort function 
    BucketSort(array, num); 
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);   
    printf("\n");     

	return 0;
}
