#include <iostream>
#include <stdlib.h>
using namespace std;

void printArray(int arry[], int len) {
  for (int i = 0; i < len; i++)
    cout << arry[i] << " ";
  cout << endl;
}
int MergeArray(int arry[], int start, int mid, int end,
               int temp[]) //数组的归并操作
{
  // int leftLen=mid-start+1;//arry[start...mid]左半段长度
  // int rightLlen=end-mid;//arry[mid+1...end]右半段长度

  int i = mid;
  int j = end;
  int k = 0; //临时数组末尾坐标
  int count = 0;
  //设定两个指针ij分别指向两段有序数组的头元素，将小的那一个放入到临时数组中去。
  while (i >= start && j > mid) {
    if (arry[i] > arry[j]) {
      temp[k++] = arry[i--]; //从临时数组的最后一个位置开始排序
      count +=
          j -
          mid; //因为arry[mid+1...j...end]是有序的，如果arry[i]>arry[j]，那么也大于arry[j]之前的元素，从a[mid+1...j]一共有j-(mid+1)+1=j-mid

    } else {
      temp[k++] = arry[j--];
    }
  }
  cout << "调用MergeArray时的count："<<count<<e         
           n d while (i >= start) //表示前半段数组中还有元素未放入临时数组
  {
    temp[k++] = arry[i--];
  }

  while (j > mid) {
    temp[k++] = arry[j--];
  }

  //将临时数组中的元素写回到原数组当中去。
  for (i = 0; i < k; i++)
    arry[end - i] = temp[i];

  printArray(arry, 8); //输出进过一次归并以后的数组，用于理解整体过程
  return count;
}

int InversePairsCore(int arry[], int start, int end, int temp[]) {
  int inversions = 0;
  if (start < end) {
    int mid = (start + end) / 2;
    inversions +=
        InversePairsCore(arry, start, mid, temp); //找左半段的逆序对数目
    inversions +=
        InversePairsCore(arry, mid + 1, end, temp); //找右半段的逆序对数目
    inversions += MergeArray(
        arry, start, mid, end,
        temp); //在找完左右半段逆序对以后两段数组有序，然后找两段之间的逆序对。最小的逆序段只有一个元素。
  }
  return inversions;
}

int InversePairs(int arry[], int len) {
  int *temp = new int[len];
  int count = InversePairsCore(arry, 0, len - 1, temp);
  delete[] temp;
  return count;
}

void main() {
  int arry[] = {7, 5, 6, 4};
  int len = sizeof(arry) / sizeof(int);
  printArray(arry, len);
  int count = InversePairs(arry, len);
  printArray(arry, len);
  cout << count << endl;
}