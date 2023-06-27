#include <iostream>
#include <string>
#include <vector>

// Fungsi hashing sederhana menggunakan metode penjumlahan karakter ASCII
int hashFunction(const std::string& key, int tableSize) {
    int hashValue = 0;
    for (int i = 0; i < key.length(); i++) {
        hashValue += key[i];
    }
    return hashValue % tableSize;
}

int main() {
    int tableSize = 10; // Ukuran tabel hash
    std::vector<std::string> keys = {"apple", "banana", "cat", "dog", "elephant"};

    // Membuat tabel hash dengan menggunakan vector
    std::vector<std::vector<std::string>> hashTable(tableSize);

    // Menambahkan kata-kata ke dalam tabel hash
    for (int i = 0; i < keys.size(); i++) {
        const std::string& key = keys[i];
        int index = hashFunction(key, tableSize);
        hashTable[index].push_back(key);
    }

    // Menampilkan isi tabel hash
    for (int i = 0; i < tableSize; i++) {
        std::cout << "Index " << i << ": ";
        for (const std::string& key : hashTable[i]) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
