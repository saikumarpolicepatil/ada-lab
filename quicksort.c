#include <stdio.h>
#include<time.h>
#include<stdlib.h>


void swap(int *a, int *b)
{
  int t;
   t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high)
{

  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
            i++;

      swap(&array[i], &array[j]);
    }
  }


  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    int pi;
  if (low < high)
  {
        pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
  }
}


void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main()
{
  int size;
  int data[2000];
  clock_t start,end;

  printf("Enter the number of elements:");
  scanf("%d",&size);

  
  for(int i=0; i< size; i++)
  {
    data[i] = rand();
  }




  printf("Unsorted Array\n");
  printArray(data, size);

  start = clock();

  quickSort(data, 0, size - 1);
  
  end = clock();

  printf("Sorted array in ascending order: \n");
  printArray(data,size);

  printf("The time taken for quick sorting is %f",(double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}
