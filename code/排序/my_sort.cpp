#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void show_arrary(const vector<int>& arrary) {
    for (int i = 0; i < arrary.size(); i++) {
        cout << arrary[i] << " ";
    }
    cout << endl;
}

void my_swap(vector<int>& arrary, int i, int j) {
    int temp = arrary[i];
    arrary[i] = arrary[j];
    arrary[j] = temp;
}
void BubbleSort(vector<int>);            //冒泡排序
void BubbleSort2(vector<int>);           //改进的冒泡排序
void SelectSort(vector<int>);            //简单选择排序
void InsertSort(vector<int>);            //插入排序
void ShellSort(vector<int>);             //希尔排序
void MergeSort(vector<int>&, int, int);  // 归并排序(递归)
void Merge(vector<int>&, int, int, int);
void mergeSort2(vector<int>);            // 归并排序(循环)
void quickSort(int, int, vector<int>&);  //快速排序
int main() {
    vector<int> arrary1{3, 1, 5, 8, 9, 7, 4, 6, 2};
    cout << "原始数组： ";
    show_arrary(arrary1);
    // cout << "冒泡排序后的数组： ";
    // BubbleSort(arrary1);
    // cout << "改进的冒泡排序后的数组： ";
    // BubbleSort2(arrary1);
    // cout << "简单选择排序后的数组： ";
    // SelectSort(arrary1);
    // cout << "插入排序后的数组： ";
    // InsertSort(arrary1);
    // cout << "希尔排序后的数组： ";
    // ShellSort(arrary1);
    // cout << "归并排序后的数组： ";
    // MergeSort(arrary1,0,arrary1.size()-1);
    // mergeSort2(arrary1);
    cout << "快速排序后的数组： ";
    quickSort(0, arrary1.size() - 1, arrary1);
}

/*
冒泡排序：
从后向前，依次遍历比较交换，使得小的数字不断向前
*/
void BubbleSort(vector<int> arrary) {
    for (int i = 1; i <= arrary.size(); i++) {
        for (int j = arrary.size() - 1; j >= i; j--) {
            if (arrary[j] < arrary[j - 1]) {
                my_swap(arrary, j, j - 1);
            }
        }
    }

    show_arrary(arrary);
}

/*
改进的冒泡排序：
如果已经有序，则不用继续遍历循环，设置标志位，使之提前结束
*/
void BubbleSort2(vector<int> arrary) {
    bool flag = true;
    // flag为false时，未发生交换，结束循环
    for (int i = 1; i <= arrary.size() && flag; i++) {
        flag = false;
        for (int j = arrary.size() - 1; j >= i; j--) {
            if (arrary[j] < arrary[j - 1]) {
                my_swap(arrary, j, j - 1);
                flag = true;
            }
        }
    }

    show_arrary(arrary);
}

/*
循环遍历，每次找到最小值，然后交换
*/
void SelectSort(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        int min = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (i != min) my_swap(array, i, min);
    }
    show_arrary(array);
}

/*
依次将数插入到前面有序的数组中
*/
void InsertSort(vector<int> array) {
    for (int i = 1; i < array.size(); i++) {
        int temp = array[i];
        for (int j = i - 1; j >= 0; j--) {
            if (temp < array[j]) {
                array[j + 1] = array[j];
                if (j == 0) array[0] = temp;
            }

            else {
                array[j + 1] = temp;
                break;
            }
        }
        show_arrary(array);
    }
    show_arrary(array);
}

void ShellSort(vector<int> arrary) {
    int i = 0, j = 0, k = 0;
    int interval = arrary.size();
    do {
        interval = interval / 3 + 1;    //确定分组的增量
        for (i = 0; i < interval; i++)  //分组
        {
            //分组后根据分组的增量来排序
            for (j = i + interval; j < arrary.size(); j += interval) {
                //当前元素与根据分组的增量前元素比较
                if (arrary[j] < arrary[j - interval]) {
                    int temp = arrary[j];
                    //往当前元素的前面对比,直到比当前元素小
                    for (k = j - interval; k >= 0 && temp < arrary[k];
                         k -= interval) {
                        arrary[k + interval] = arrary[k];  //满足条件则后移
                    }
                    //(不满足条件)在比当前元素小的元素的下一个位置插入F
                    arrary[k + interval] = temp;
                }
            }
        }
        cout << interval << endl;
        show_arrary(arrary);
    } while (interval > 1);
    show_arrary(arrary);
}

void Merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> b(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (j <= high) {
        b[k] = arr[j];
        k++;
        j++;
    }
    while (i <= mid) {
        b[k] = arr[i];
        k++;
        i++;
    }
    for (i = 0; i < high - low + 1; i++) {
        arr[low + i] = b[i];
    }
}
void MergeSort(vector<int>& arr, int low, int high) {
    if (high - low == 1) {
        if (arr[low] > arr[high]) my_swap(arr, low, high);
        return;
    } else if (low >= high) {
        return;
    }  // 终止递归的条件，子序列长度为1
    int mid = low + (high - low) / 2;  // 取得序列中间的元素
    MergeSort(arr, low, mid);          // 对左半边递归
    MergeSort(arr, mid + 1, high);     // 对右半边递归
    Merge(arr, low, mid, high);        // 合并
    show_arrary(arr);
}

void mergeSort2(vector<int> arr) {
    int n = arr.size();
    int curr_size;   // 当前子数组的大小，子数组大小： 1 到 n/2
    int left_start;  // 左子数组的开始下标

    // 自底向上归并.  首先归并大小为1的数组形成大小为2的有序子数组,
    // 接着归并大小为2的数组，形成大小为4的有序子数组
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // 根据子数组大小调整左子数组起始下标
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // min函数是为了防止下标越界
            // 找出左子数组结尾下标
            int mid = min(left_start + curr_size - 1, n - 1);
            // 找出右子数组结尾下标
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // 归并子数组 arr【left_start...mid】 & arr【mid+1...right_end】
            // ，和递归的相同
            Merge(arr, left_start, mid, right_end);
        }
    }
    show_arrary(arr);
}

//快速排序（从小到大）
void quickSort(int left, int right, vector<int>& arr) {
    if (left >= right) return;
    int i, j, base, temp;
    i = left, j = right;
    base = arr[left];  //取最左边的数为基准数
    while (i < j) {
        while (arr[j] >= base && i < j) j--;
        while (arr[i] <= base && i < j) i++;
        if (i < j) my_swap(arr, i, j);
    }
    //基准数归位
    arr[left] = arr[i];
    arr[i] = base;
    quickSort(left, i - 1, arr);   //递归左边
    quickSort(i + 1, right, arr);  //递归右边
    show_arrary(arr);
}