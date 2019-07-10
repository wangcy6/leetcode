#include<iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
 //https://www.youtube.com/watch?v=o9zuaEW38Fk
void quickSort3Way(int arr[], int l, int r) {
 
	if (l >= r)
		return;
 //随机选择要做比较的值
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	int v = arr[l];
	int i = l + 1,
  lt=l,
  rt = r+1;
 
	while (i<rt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt+1]);
			lt++;
			i++;
		}
		
		if (arr[i] == v) {
			i++;
		}
		if (arr[i] > v) {
			swap(arr[i], arr[rt]);
			rt--;
			
		}
 
	}
 
	swap(arr[l], arr[lt]);
 
	quickSort3Way(arr, l, lt-1 );
	quickSort3Way(arr, rt+1, r);
  for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
 
}

int partition(int* arr, int low, int high, int* lp); 
  
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void DualPivotQuickSort(int* arr, int low, int high) 
{ 
    if (low < high) { 
        // lp means left pivot, and rp means right pivot. 
        int lp, rp;  
        rp = partition(arr, low, high, &lp); 
        DualPivotQuickSort(arr, low, lp - 1); 
        DualPivotQuickSort(arr, lp + 1, rp - 1); 
        DualPivotQuickSort(arr, rp + 1, high); 
    } 
} 
  
int partition(int* arr, int low, int high, int* lp) 
{ 
    if (arr[low] > arr[high]) 
        swap(&arr[low], &arr[high]); 
    // p is the left pivot, and q is the right pivot. 
    int j = low + 1; 
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high]; 
    while (k <= g) { 
  
        // if elements are less than the left pivot 
        if (arr[k] < p) { 
            swap(&arr[k], &arr[j]); 
            j++; 
        } 
  
        // if elements are greater than or equal  
        // to the right pivot 
        else if (arr[k] >= q) { 
            while (arr[g] > q && k < g) 
                g--; 
            swap(&arr[k], &arr[g]); 
            g--; 
            if (arr[k] < p) { 
                swap(&arr[k], &arr[j]); 
                j++; 
            } 
        } 
        k++; 
    } 
    j--; 
    g++; 
  
    // bring pivots to their appropriate positions. 
    swap(&arr[low], &arr[j]); 
    swap(&arr[high], &arr[g]); 
  
    // returning the indeces of the pivots. 
    *lp = j; // because we cannot return two elements  
             // from a function. 
  
    return g; 
} 
 //https://blog.csdn.net/u012104219/article/details/80873484
 //http://hg.openjdk.java.net/jdk8u/jdk8u/jdk/file/e2117e30fb39/src/share/classes/java/util/DualPivotQuicksort.java
int main() {
 
	int arr[8] = { 4,4,4,8,2,1,4,5 };
	quickSort3Way(arr,0,7);
	 
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}