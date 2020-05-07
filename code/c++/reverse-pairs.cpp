#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param A: an array
   * @return: total of reverse pairs
   * https://www.lintcode.com/problem/reverse-pairs/description
   * Given an array, return the number of reverse pairs in the array
   */
  long long reversePairs(vector<int> &A) {
    vector<int> temp(A.size(), 0); //归并排序，需要一个额外空间合并2个有序记录
    return mergeSort(A, 0, A.size() - 1, temp);
  }
  long long mergeSort(vector<int> &array, int start, int end,
                      vector<int> &temp) {
    if (start >= end) {
      return 0;
    }
    long long inversions = 0;
    int mid = start + (end - start) / 2;

    inversions += mergeSort(array, start, mid, temp); //找左半段的逆序对数目
    inversions += mergeSort(array, mid + 1, end, temp); ///找右半段的逆序对数目
    inversions += mergeFromBein(
        array, start, mid, end,
        temp); //在找完左右半段逆序对以后两段数组有序，然后找两段之间的逆序对。
    return inversions;
  }

  long long mergeFromBein(vector<int> &array, int start, int mid, int end,
                          vector<int> &temp) {

    // arry[start...mid]左半段长度
    // arry[mid+1...end]右半段长度
    int p1 = start;
    int p2 = mid + 1;
    int k = 0;
    long long sum = 0;
    while (p1 <= mid && p2 <= end) {
      if (array[p1] > array[p2]) { // p2 小
        sum += mid - p1 + 1;       //在这统计逆序对
        temp[k++] = array[p2++];
      } else {
        temp[k++] = array[p1++];
      }
    }

    // 把左边剩余的数移入数组
    while (p1 <= mid) {
      temp[k++] = array[p1++];
    }

    // 把右边边剩余的数移入数组
    while (p2 <= end) {
      temp[k++] = array[p2++];
    }

    // 把新数组中的数覆盖nums数组
    for (int k = 0; k < temp.size(); k++) {
      array[start + k] = temp[k];
    }
  }

  long long mergeFromEnd(vector<int> &array, int start, int mid, int end,
                         vector<int> &temp) {
    // arry[start...mid]左半段长度
    // arry[mid+1...end]右半段长度
    temp.clear();
    int p1 = mid;
    int p2 = end;
    int index = 0;
    long long count = 0;
    while (p1 >= start && p2 > mid) {

      if (array[p1] > array[p2]) {
        temp[index++] = array[p1--];
        count += p2 - mid; //在这统计逆序对
      } else {
        temp[index++] = array[p2--];
      }
    }
    // cout << "mergeArray " << count;
    while (p1 >= start) {
      temp[index++] = array[p1--];
    }

    while (p2 > mid) {
      temp[index++] = array[p2--];
    }

    //将临时数组中的元素写回到原数组当中去。
    for (int i = 0; i < index; i++)
      array[end - i] = temp[i];

    return count;
  }

  void printArray(vector<int> &array) {
    for (int i = 0; i < array.size(); i++)
      cout << array[i] << " ";
    cout << endl;
  }
};

class Solution2 {
public:
  /**
   * @param A: an array
   * @return: total of reverse pairs
   * https://www.lintcode.com/problem/reverse-pairs/description
   * Given an array, return the number of reverse pairs in the array
   */
  long long reversePairs(vector<int> &A) {
    if (A.size() == 0)
      return 0;
    return mergeSort(A, 0, A.size() - 1);
  }
  long long mergeSort(vector<int> &array, int start, int end) {
    if (start >= end) {
      return 0;
    }
    long long sum = 0;
    int mid = start + (end - start) / 2;

    sum += mergeSort(array, start, mid);   //找左半段的逆序对数目
    sum += mergeSort(array, mid + 1, end); ///找右半段的逆序对数目
    sum += mergeArray1(
        array, start, mid,
        end); //在找完左右半段逆序对以后两段数组有序，然后找两段之间的逆序对。
    return sum;
  }

  //按照从小到大合并 2个有序数组
  long long mergeArray1(vector<int> &num, int low, int mid, int high) {
    vector<int> temp(high - low + 1, 0);
    int i = low;     // 左指针
    int j = mid + 1; // 右指针
    int k = 0;
    long long inversions = 0;
    // 把较小的数先移到新数组中
    while (i <= mid && j <= high) {
      if (num[i] <= num[j]) {
        temp[k++] = num[i++];

      } else {
        //[ 7 8 9  ]/ [1， 2 ，3 ]
        //只要一个大于 前面都大于大
        temp[k++] = num[j++];
        inversions += (mid - i + 1);
      }
    }
    // 把左边剩余的数移入数组
    while (i <= mid) {
      temp[k++] = num[i++];
    }

    // 把右边边剩余的数移入数组
    while (j <= high) {
      temp[k++] = num[j++];
    }

    // 把新数组中的数覆盖nums数组
    for (int k2 = 0; k2 < temp.size(); k2++) {
      num[k2 + low] = temp[k2];
    }

    return inversions;
  }
};
int main(int argc, char *argv[]) {

  int arry[4] = {7, 5, 6, 4};
  vector<int> input(arry, arry + 4);
  Solution test;
  cout << test.reversePairs(input);
  test.printArray(input);
}
