#include <iostream>
using namespace std;

int main(){
	int first, mid, last;
	first = 0;
	last = 8 - 1;
	int array[8] = {8, 2, 1, 9, 23, 0, 0, 0};

	for (int i = 0; i < 8; i++){
		cout << array[i] << " ";
	}

	int find;
	cout << "\nInput number: ";
	cin >> find;

	while (first < last){
		mid = (first + last) / 2;
		if (array[mid] == find) {
            cout << "\nNumber found at index " << mid << endl;
            return 0;
        } 
		if (array[mid] < find) {
            first = mid + 1;
        } 
		else {
            last = mid - 1;
        }
    }
    
    cout << "Data not found in the list";

    return 0;
}
