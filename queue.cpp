#include <iostream>
using namespace std;


int maksimalAntrian = 5, front = 0, back = 0;
string antrianAtm[5];

bool isEmpty()
{
	if(front == 0)
	{
		return true;
	}else
	{
		return false;
	}
}

bool isFull()
{
	if(back == maksimalAntrian)
	{
		return true;
	}else
	{
		return false;
	}
}


void equeueArray(string data)
{

	if(isFull())
	{
		cout << "data penuh" << endl;
	}else 
	{
		if(isEmpty())
		{

		antrianAtm[0]=data;
		front ++;
		back++;
		}else
		{
		antrianAtm[back]=data;
		back++;
		}

}
}



void dequeue(){

	if(isEmpty())
	{
		cout << "data kosong" << endl;
	}else{
	for(int i=0; i<back-1;i++)
	{
		antrianAtm[i]=antrianAtm[i+1];
	}
	back--;
	antrianAtm[back] = "";

		}


}

void display(){
	cout << "data antrian atm: " << endl;
	if(isEmpty())
	{
		cout << "data kosong" << endl;
	}else
	{
			for(int i = 0; i<maksimalAntrian; i++)
	{

		if(antrianAtm[i] != "")
		{
			cout << i+1 << ". " << antrianAtm[i]<<endl;
		}else{
			cout << i+1 << "data kosong" << endl;
		}


	}
		cout << "\n" << endl;		

}
}

int count()
{
	cout << "banyaknya array: "<< back << endl;


}

void destroy()
{
	if(isEmpty()){
		cout << "data kosong"<< endl;
	}else{

	for(int i = 0; i<back; i++)
	{
		antrianAtm[i]="";
	}
	back=0;
	front=0;
		}
}

int main()
{
	equeueArray("a");
	equeueArray("b");
	equeueArray("c");
	equeueArray("d");
	equeueArray("e");
	display();

	dequeue();
	display();

count();

	destroy();
	display();

}



