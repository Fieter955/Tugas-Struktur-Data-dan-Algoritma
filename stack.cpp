#include <iostream>
using namespace std;

int maksimal=5;
string array[5];
int top=0; 


bool isFull()
{
	if(top==maksimal)
	{
		return true;
	}else
	{
		return false;
	}
}

bool isEmpty()
{
	if(top==0)
	{
		return true;
	}else{
		return false;
	}
}


void push(string data){
	if(isFull()){
		cout << "Data Penuh" << endl;
	}else {
		array[top] = data;
		top++;
	}
}

void peekArray(int posisi)
{
	if(isEmpty())
	{
		cout << "data kosong" << endl;
	}else 
	{
		int index = top;
		for(int i = 0; i< posisi;i++)
		{
			index--;
		}
		cout << "data posisi ke-"<< posisi << " ;"<< array[index] << endl;
	}
	}

	int countArray()
	{
		if(isEmpty())
	{
		return 0;
	}else
	{
		return top;
	}
	}

void changeArray(string data, int posisi)
{
	if(isEmpty())
{
	cout << "data kosong" << endl;
}else
{
	int index = top;
	for(int i = 0; i<posisi;i++)
	{
		index--;
	}
	array[index]=data;
}
}

void distroy(){
		if(isEmpty())
	{
		cout << "data kosong" << endl;
	}else
	{	
		int sisa = top;
		for(int i = 0; i < sisa; i++)
		{
			array[top-1]="";
			top--;
		}
	}
}

void display(){
	if(isEmpty())
	{
		cout << "data kosong" << endl;
	}else{

		cout << "data stack array: " << endl;
		for(int i = maksimal-1; i>=0;i--){
			if(array[i] != ""){
				cout << "data : " << array[i] << endl;
		} 
	}
		cout << "\n" << endl;
}
}


void pop(){
	if(isEmpty())
{
	cout << "data kosong" << endl;
}else
{
	array[top-1]="";
	top--;
}

}



int main(){

	push("web programing");
	push("web a");
	push("web a");
	push("web a");
	push("web a");
	push("web a");
	display();
	pop();
	display();
	peekArray(4);

	cout << "banyak data:"  << countArray() << endl;

	changeArray("database",2);
	display();

	distroy();

	display();


}


