#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int n, a[10000], b[10000];
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
void display();

int main(){
clock_t start, end;
printf("Enter the size of the array to be sorted: ");
scanf("%d",&n);
printf("\nEnter the array elements: ");
srand(time(NULL));
for(int i = 0 ; i < n ; i++){
a[i] = rand() % 1000;
}
start = clock();
merge_sort(a, 0, n-1);
end = clock();
display();
double time_taken = ((double) (end-start) )/CLOCKS_PER_SEC;
printf("\nTime taken to sort: %lf",time_taken);
return 0;
}
void merge_sort(int a[], int low, int high){
if(low < high)
{
int mid = (low + high) / 2;
merge_sort(a, low, mid);
merge_sort(a, mid+1, high);
merge(a, low, mid, high);
}
}
void merge(int a[], int low, int mid, int high){
int i = low;
int j = mid+1;
int k = low;
while( i <= mid && j<=high ){
if( a[i] > a[j]){
b[k] = a[j];
k++;
j++;
}
else{
b[k] = a[i];
k++;
i++;
}
}
while(i <= mid){
b[k] = a[i];
k++;
i++;
}
while(j <= high){
b[k] = a[j];
k++;
j++;
}
for (i = low; i <= high; i++) {
a[i] = b[i];
}
}
void display(){
printf("\nSorted elements are: ");
for(int i = 0 ; i < n ; i++){
printf("%d ",a[i]);
}
}
