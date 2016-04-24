#include <iostream>
using namespace std;

#define MAXSIZE 10

typedef struct{
	int r[MAXSIZE];
	int length;
}SqList;

void print_arr(SqList *L){
	if(L->length <= 1)
		return ;
	cout<<L->r[1];
	for(int i = 2; i <= L->length; i++){
		cout<<" "<<L->r[i];
	}
	cout<<endl;
}

//简单选择排序
/*
void choiceSort(SqList *L){
	int min_index;
	int i, j;
	for(i = 1; i < L->length; i++){
		min_index = i, L->r[0] = L->r[i];
		for(j = i + 1; j <= L->length; j++){
			if(L->r[0] > L->r[j]){
				L->r[0] = L->r[j];
				min_index = j;
			}
		}
		L->r[min_index] = L->r[i];
		L->r[i] = L->r[0];
	}
}
*/

/*
//直接插入排序
void insertSort(SqList *L){
	int i, j;
	for(i = 2; i <= L->length; i++){
		L->r[0] = L->r[i];
		j = i - 1;
		while(L->r[0] < L->r[j] && j > 0){
			L->r[j+1] = L->r[j];
			j--;
		}
		L->r[j+1] = L->r[0];
	}
}
*/

/*
//冒泡排序
void bubbleSort(SqList *L){
	int i, j;
	bool flag = true;
	for(i = 1; i <= L->length && flag; i++){
		flag = false;
		for(j = L->length; j >= i; j--){
			if(L->r[j] < L->r[j-1]){
				swap(L->r[j], L->r[j-1]);
				flag = true;
			}
		}
	}
}
*/

/*
//希尔排序
void shellSort(SqList *L){
	int size = L->length;
	while(size > 1){
		size = size/3 + 1;
		for(int i = size + 1; i <= L->length; i++){
			if(L->r[i] < L->r[i-size]){
				L->r[0] = L->r[i];
				int j;
				for(j = i - size; j > 0 && L->r[0] < L->r[j]; j-=size){
					L->r[j+size] = L->r[j];
				}
				L->r[j+size] = L->r[0];
			}
		}
	}
}
*/

/*
//归并排序
void merge(int a[], int b[], int p, int t, int q){ //将ａ[p,.t..q],归并到b[p,.t..,q]中
	int i = p, j = t + 1;
	int count = i;
	while(i <= t && j <= q){
		if(a[i] <= a[j]){
			b[count++] = a[i++];
		}
		else{
			b[count++] = a[j++];
		}
	}
	
	while(i <= t){
		b[count++] = a[i++];
	}

	while(j <= q){
		b[count++] = a[j++];
	}
}

void mSort(int a[], int b[], int m, int n){ //将a[m,...,n]归并到b[m,...n]中
	int c[MAXSIZE];
	if(m == n)
		b[m] = a[m];
	else{
		int index = (m + n)/2;
		mSort(a, c, m, index);
		mSort(a, c, index+1, n);
		merge(c, b, m, index, n); 
	}
}

void mergeSort(SqList *L){
	mSort(L->r, L->r, 1, L->length);
}
*/

/*
//堆排序
void HeapAdjust(SqList *L, int m, int n){
	int temp = L->r[m];
	for(int j = 2*m; j <= n; j++){
		if(j < n && L->r[j] < L->r[j+1]){ //比较两个子节点
			++j; //ｊ为关键字大的下标
		}

		if(temp > L->r[j])
			break;
		L->r[m] = L->r[j];
		m = j;
	}
	L->r[m] = temp;
}

void heapSort(SqList *L){
	int i;
	for(i = L->length/2; i > 0; i--){ //构建大顶堆
		HeapAdjust(L, i, L->length);
	}	
	
	for(i = L->length; i > 1; i--){
		swap(L->r[1], L->r[i]); //交换栈顶元素
		HeapAdjust(L, 1, i-1);
	}
}
*/

//快速排序
int  findSeprator(SqList *L, int low, int high){
	L->r[0] = L->r[high];  //将最后一个元素放到ｒ[0]中
	int i = low, j = high;
	while(i < j){
		while(i < j && L->r[i] < L->r[0]){ //当元素小于r[0],i++
			i++;
		}
		L->r[j] = L->r[i]; //当元素大于r[0]，交换元素
		while(i < j && L->r[j] > L->r[0]){ //当元素大于r[0], j--
			j--;
		}
		L->r[i] = L->r[j]; //当元素小于r[0]，交换元素
	}
	L->r[i] = L->r[0]; //把r[0]元素放到最终位置
	return i;
}

void qSort(SqList *L, int low, int high){
	int index;
	if(low < high){
		index = findSeprator(L, low, high);
		qSort(L, low, index-1);
		qSort(L, index+1, high);
	}
}

void quickSort(SqList *L){
	qSort(L, 1, L->length);	
}

int main(){
	int a[9] = {9, 1, 5, 3, 2, 7, 4, 8, 6};
	SqList *L = new SqList();
	copy(a, a+9, &L->r[1]);
	L->length = 9;
	//排序前
	print_arr(L);

	//排序
	//7.快速排序
	quickSort(L);
	//6.堆排序
//	heapSort(L);
	//5.归并排序
//	mergeSort(L);
	//4.希尔排序
//	shellSort(L);
	//3.冒泡排序
//	bubbleSort(L);
	//2.直接插入排序
//	insertSort(L);
	//1.简单选择排序
//	choiceSort(L);


	//排序后
	print_arr(L);
	delete(L);
	return 0;
}
