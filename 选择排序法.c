#include<stdio.h>
int MAX(int array[],int n){
	int max = array[0];
	int pos = 0;
	int i = 0;
	for(i = 0;i < n;i++){
		if(array[i]> max){
		max = array[i];
		pos = i;	
	}
}
return pos;
} 


void Selection(int array[],int n){
	int j = 0;
	int t = 0,p = 0;
	for(j = n;j > 0;j--){
	t = MAX(array,j);
	p = array[t];
	array[t] = array[j-1];
	array[j-1] = p;
	}
} 






int main(){
	int array[] = {1,7,4,3,55,67,4,3234,888,19};
	Selection(array,10);
	
	int i = 0;
	for(i = 0;i < 10;i++){
		printf("%d\n",array[i]);
	}
	return 0;
}
