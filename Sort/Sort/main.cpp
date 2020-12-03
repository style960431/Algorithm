//
//  main.cpp
//  Sort
//
//  Created by 王宗祥 on 2020/11/27.
//

#include <iostream>

using namespace std;

/*  Insertion_Sort
    先定義當次迴圈的 i = 1 的數值為 key 暫存，以避免被覆蓋，
    而 key 的數值會一直向左方比較至最左方為止，並將大於的數值向右移動一格
    再將 key 的數值插入至該空缺，
    即可確保每次執行迴圈時，左方已經是排序好的狀態，
*/
void Insertion_Sort(int* arr, const int& size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*  Selection_Sort
    先定義當次迴圈的第一個index為min_index，
    再新增內部迴圈內找出最小值的index，
    再與當次迴圈的第一個位置交換，
    因此每完成一次迴圈後，即會確定最小值在最前方。
*/
void Selection_Sort(int* arr, const int& size) {
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            min_index = arr[min_index] > arr[j] ? j : min_index;
        }
        swap(arr[i], arr[min_index]);
    }
}

void Bubble_Sort(int* arr, const int& size) {
    int num = size;
    while (num > 1) {
        num--;
        for (int i = 0; i < num; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int Partition(int* arr, int& front, int& end) {
    int pivot = arr[end];
    int i = front - 1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}
void Quick_Sort(int* arr, int front, int end) {
    if (front < end) {
        int pivot = Partition(arr, front, end);
        Quick_Sort(arr, front, pivot - 1);
        Quick_Sort(arr, pivot + 1, end);
    }
}

void Merge(int* arr, int front, int mid, int end) {
    int n1 = mid - front + 1;
    int n2 = end - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[front + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = front;
    while (i < n1 && j < n2)
        arr[k++] = L[i] <= R[j] ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}
void Merge_Sort(int* arr, int front, int end) {
    if (front < end) {
        int mid = (front + end) / 2;
        Merge_Sort(arr, front, mid);
        Merge_Sort(arr, mid + 1, end);
        Merge(arr, front, mid, end);
    }
}

void Heapify(int* arr,int root,int length) {
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int largest = root;
    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }
    if (root != largest) {
        swap(arr[root], arr[largest]);
        Heapify(arr,largest,length);
    }
}
void Heap_Sort(int* arr,int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, length);
    }
    for (int i = length - 1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i);
    }
}

void print_sort(int* arr, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr1[] = { 7,5,9,1,3,4,6,10,11 };
    int arr2[] = { 5,18,1,3,55,24,12,14,3,7,88 };
    int arr3[] = { 6,8,1,3,7,5,2,4,9,0 };
    int arr4[] = { 0,9,4,3,8,7,2,5,6,1 };
    int arr5[] = { 61,66,5,1,7,82,49,5,8,75,12 };
    int arr6[] = { 32,4,78,9,65,14,82,31,10,11 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int size6 = sizeof(arr6) / sizeof(arr6[0]);

    Insertion_Sort(arr1, size1);
    print_sort(arr1, size1);
    Selection_Sort(arr2, size2);
    print_sort(arr2, size2);
    Bubble_Sort(arr3, size3);
    print_sort(arr3, size3);
    Quick_Sort(arr4, 0, size4 - 1);
    print_sort(arr4, size4);
    Merge_Sort(arr5, 0, size5 - 1);
    print_sort(arr5, size5);
    Heap_Sort(arr6, size6);
    print_sort(arr6, size6);
    return 0;
}

