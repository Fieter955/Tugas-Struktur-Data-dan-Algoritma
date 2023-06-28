#include <iostream>
#include <vector>
using namespace std;

void hashfunctionLinear(const vector<int>& keys, int tablesize){
	vector<vector<int> > hashtable(tablesize);
	int prima = tablesize+1;
	
	for(int i =0; i<keys.size();++i){
		int key = keys[i];
		int index = key % prima;
		
		while(!hashtable[index].empty()){
			index = (index+1) % prima;
		}
		hashtable[index].push_back(key);
	}
	
	for(int i =0;i<hashtable.size();++i){
		for(int j=0;j<hashtable[i].size();++j){
			cout << hashtable[i][j];
		}
		cout << endl;
	}
}



void hashfunctionQuadratic(const vector<int>& keys, int tablesize){
	vector<vector<int> > hashtable(tablesize);
	int prima = tablesize+1;
	
	for(int i =0; i <keys.size();++i){
		int key = keys[i];
		int index = key % prima;
		
		while(!hashtable[index].empty()){
			index = (index+index*index) % prima;
		}
		hashtable[index].push_back(key);
	}
	
	for(int i =0;i<hashtable.size();++i){
		for(int j =0; j<hashtable[i].size();++j){
			cout << hashtable[i][j];
		}
		cout << endl;
	}

	
}

int main(){
	int tablesize = 10;
	cout << "Linear Probing:"<<endl;
	
	vector<int> keys = {32, 53, 22, 92, 17, 34, 24, 37,  56 };
	hashfunctionLinear(keys, tablesize);
	
	cout << "\nQuadratic Probing:"<<endl;
	vector<int> keyss = {0, 15, 16, 20, 30, 25, 26, 36 };
	hashfunctionQuadratic(keyss, tablesize);
	
	return 0;
}