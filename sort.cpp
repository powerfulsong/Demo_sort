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

int main(){
	int a[9] = {9, 1, 5, 3, 2, 7, 4, 8, 6};
	SqList *L = new SqList();
	copy(a, a+9, &L->r[1]);
	L->length = 9;
	//排序前
	print_arr(L);

	//排序
	//2.直接插入排序
	insertSort(L);
	//1.简单选择排序
//	choiceSort(L);


	//排序后
	print_arr(L);
	delete(L);
	return 0;
}
