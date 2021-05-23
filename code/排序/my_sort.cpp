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
void BubbleSort(vector<int>);            //ð������
void BubbleSort2(vector<int>);           //�Ľ���ð������
void SelectSort(vector<int>);            //��ѡ������
void InsertSort(vector<int>);            //��������
void ShellSort(vector<int>);             //ϣ������
void MergeSort(vector<int>&, int, int);  // �鲢����(�ݹ�)
void Merge(vector<int>&, int, int, int);
void mergeSort2(vector<int>);            // �鲢����(ѭ��)
void quickSort(int, int, vector<int>&);  //��������
int main() {
    vector<int> arrary1{3, 1, 5, 8, 9, 7, 4, 6, 2};
    cout << "ԭʼ���飺 ";
    show_arrary(arrary1);
    // cout << "ð�����������飺 ";
    // BubbleSort(arrary1);
    // cout << "�Ľ���ð�����������飺 ";
    // BubbleSort2(arrary1);
    // cout << "��ѡ�����������飺 ";
    // SelectSort(arrary1);
    // cout << "�������������飺 ";
    // InsertSort(arrary1);
    // cout << "ϣ�����������飺 ";
    // ShellSort(arrary1);
    // cout << "�鲢���������飺 ";
    // MergeSort(arrary1,0,arrary1.size()-1);
    // mergeSort2(arrary1);
    cout << "�������������飺 ";
    quickSort(0, arrary1.size() - 1, arrary1);
}

/*
ð������
�Ӻ���ǰ�����α����ȽϽ�����ʹ��С�����ֲ�����ǰ
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
�Ľ���ð������
����Ѿ��������ü�������ѭ�������ñ�־λ��ʹ֮��ǰ����
*/
void BubbleSort2(vector<int> arrary) {
    bool flag = true;
    // flagΪfalseʱ��δ��������������ѭ��
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
ѭ��������ÿ���ҵ���Сֵ��Ȼ�󽻻�
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
���ν������뵽ǰ�������������
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
        interval = interval / 3 + 1;    //ȷ�����������
        for (i = 0; i < interval; i++)  //����
        {
            //�������ݷ��������������
            for (j = i + interval; j < arrary.size(); j += interval) {
                //��ǰԪ������ݷ��������ǰԪ�رȽ�
                if (arrary[j] < arrary[j - interval]) {
                    int temp = arrary[j];
                    //����ǰԪ�ص�ǰ��Ա�,ֱ���ȵ�ǰԪ��С
                    for (k = j - interval; k >= 0 && temp < arrary[k];
                         k -= interval) {
                        arrary[k + interval] = arrary[k];  //�������������
                    }
                    //(����������)�ڱȵ�ǰԪ��С��Ԫ�ص���һ��λ�ò���F
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
    }  // ��ֹ�ݹ�������������г���Ϊ1
    int mid = low + (high - low) / 2;  // ȡ�������м��Ԫ��
    MergeSort(arr, low, mid);          // �����ߵݹ�
    MergeSort(arr, mid + 1, high);     // ���Ұ�ߵݹ�
    Merge(arr, low, mid, high);        // �ϲ�
    show_arrary(arr);
}

void mergeSort2(vector<int> arr) {
    int n = arr.size();
    int curr_size;   // ��ǰ������Ĵ�С���������С�� 1 �� n/2
    int left_start;  // ��������Ŀ�ʼ�±�

    // �Ե����Ϲ鲢.  ���ȹ鲢��СΪ1�������γɴ�СΪ2������������,
    // ���Ź鲢��СΪ2�����飬�γɴ�СΪ4������������
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // �����������С��������������ʼ�±�
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // min������Ϊ�˷�ֹ�±�Խ��
            // �ҳ����������β�±�
            int mid = min(left_start + curr_size - 1, n - 1);
            // �ҳ����������β�±�
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // �鲢������ arr��left_start...mid�� & arr��mid+1...right_end��
            // ���͵ݹ����ͬ
            Merge(arr, left_start, mid, right_end);
        }
    }
    show_arrary(arr);
}

//�������򣨴�С����
void quickSort(int left, int right, vector<int>& arr) {
    if (left >= right) return;
    int i, j, base, temp;
    i = left, j = right;
    base = arr[left];  //ȡ����ߵ���Ϊ��׼��
    while (i < j) {
        while (arr[j] >= base && i < j) j--;
        while (arr[i] <= base && i < j) i++;
        if (i < j) my_swap(arr, i, j);
    }
    //��׼����λ
    arr[left] = arr[i];
    arr[i] = base;
    quickSort(left, i - 1, arr);   //�ݹ����
    quickSort(i + 1, right, arr);  //�ݹ��ұ�
    show_arrary(arr);
}