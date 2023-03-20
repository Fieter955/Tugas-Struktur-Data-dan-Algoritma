#include <stdio.h>


int array[7];



int main(){
	
array[0]=1;
array[1]=2;
array[2]=5;
array[3]=7;
array[4]=8;


int key = 2;
int kiri=0;
int kanan=4;
int median;




for(int a; array[median]!=key; a+0) {
	median=(kiri+kanan)/2;
	if(array[median]==key){
		printf("hasil ditemukan pada index array ke %i", median);
	}
	
	else if(median<key){
		kiri=median+1;
	}
	else{
		kanan=median-1;
	}
};





	
	
	
	return 0;
}
