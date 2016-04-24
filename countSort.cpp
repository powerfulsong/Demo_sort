#include<iostream>
using namespace std;

void print_arr(int *a, int num){
	if(num < 0)
		return ;
	cout<<a[0];
	for(int i = 1; i < num; i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
}

void countSort(int *a, int num){
	int b[6] = {0};	
	int c[7] = {0};
	int i , j;
	//统计每个元素的数目
	for(i = 0; i < num; i++){
		b[a[i]]++;
	}
	for(j = 1; j < 6; j++){
		b[j] = b[j-1] + b[j];
	}

	for(i = 0; i < num; i++){
		c[b[a[i]]-1] = a[i];
		b[a[i]] --;
	}

	copy(c, c+7, a);
}

int main(){
	int a[7] = {5, 4, 1, 1, 5, 2, 3};
	print_arr(a, 7);
	countSort(a, 7);
	print_arr(a, 7);	
	return 0;
}
