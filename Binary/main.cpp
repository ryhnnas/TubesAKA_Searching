// Binary Seacrh
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int BinarySearch(string* data, int left, int right, const string& key) {
    if (left > right) {
        return -1; // Kata tidak ditemukan
    }

    int mid = left + (right - left) / 2;

    if (data[mid] == key) {
        return mid; // Kata ditemukan
    } else if (data[mid] > key) {
        return BinarySearch(data, left, mid - 1, key);
    } else {
        return BinarySearch(data, mid + 1, right, key);
    }
}

// Fungsi untuk menghitung jumlah kemunculan kata
int CountWord(string* data, int size, const string& key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == key) {
            count++;
        }
    }
    return count;
}

void SearchInFile(const string& filename, const string& targetWord) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Gagal membuka file." << endl;
        return;
    }

    const int MAX_WORDS = 1000; // Maksimum jumlah kata yang dapat ditampung
    string words[MAX_WORDS];
    string word;
    int count = 0;

    while (file >> word && count < MAX_WORDS) {
        words[count++] = word;
    }

    file.close();

    sort(words, words + count);

    int foundIndex = BinarySearch(words, 0, count - 1, targetWord);

    int Count = CountWord(words, count, targetWord);

    // Menampilkan hasil
    cout << "Kata \"" << targetWord << "\" ditemukan sebanyak " << Count << " kali." << endl;
}

int main() {
    string filename = "eBook.txt";
    string targetWord;

    cout << "Masukkan kata yang ingin dicari: ";
    cin >> targetWord;

    SearchInFile(filename, targetWord);
    return 0;
}
