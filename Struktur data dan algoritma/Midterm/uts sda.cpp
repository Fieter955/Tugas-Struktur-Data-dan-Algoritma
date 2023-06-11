#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool periksaTandaKurung(string inputStr) {
    stack<char> delimiterStack; // buat sebuah stack bernama delimiterStack
    
    /* operasi yang dapat digunakan pada delimiterStack: 
	 * void delimiterStack.push(c); 	// push elemen c ke stack
	 * void delimiterStack.pop();		// pop elemen dari stack
	 * char delimiterStack.top();		// ambil elemen paling atas dari stack
	 * bool delimiterStack.empty();		// cek apakah stack berisi atau kosong, true=berisi, false=kosong
	 */

	// 1. ambil setiap karakter dari string inputStr ke variable c, lakukan perulangan sampai semua karakter diproses
    for (int i=0; i<inputStr.length(); i++) {
    	char c = inputStr[i];
    	
		//2. jika c adalah karakter '(' , '[', atau '{', maka masukan c ke delimiterStack
        if (c=='(' || c== '[' || c == '{')
        {
            delimiterStack.push(c);
        }
        
		//3. jika c adalah karakter ')' , ']', atau '}', maka lakukan tahapan pengecekan berikut:
		if (c == ')' || c == ']' || c== '}')
        {
            // 3a. Jika delimiterStack kosong, maka tanda kurung buka tidak ada di stack, sehingga pasangan tanda kurung salah (return false)
			if (delimiterStack.empty())
            {
                return false;
            }
            
			
			// 3b. Ambil elemen teratas dari delimiterStack
            char diatas = delimiterStack.top();
			
			
			// 3c. Jika elemen teratas sesuai dengan pasangan karakter c, maka pop delimiterStack
            if ((diatas == '(' && c == ')') || (diatas == '[' && c == ']') || (diatas == '{' && c == '}') )
            {
                delimiterStack.pop();
            }
    			
			// 3d. Jika elemen teratas tidak sesuai dengan pasangan karakter c, maka tanda kurung buka dan tutup tidak sesuai (return false)
            else{
                return false;
            }
        }
        
		
		
		
						
			
    }
    
    //4. setelah semua karakter inputStr diproses, periksa apakah masih ada elemen di delimiterStack.
    //   4a. jika masih ada elemen dalam delimiterStack, maka masih ada tanda kurung buka atau tutup yang tidak ada pasangannya (return false)
    if (delimiterStack.empty())
    {
        return true;
    }
    
    //   4b. jika tidak ada elemen dalam delimiterStack, maka semua tanda ada pasangannya (return true)
    else{
        return false;
    }
    
    
}


int main() {
    string inputStr;
    cout << "Masukkan ekspresi dengan tanda kurung: ";
    cin >> inputStr;

    bool sesuai = periksaTandaKurung(inputStr);
    if (sesuai) {
        cout << "Tanda kurung buka dan tutup sesuai." << endl;
    } else {
        cout << "Tanda kurung buka dan tutup tidak sesuai." << endl;
    }

    return 0;
}

