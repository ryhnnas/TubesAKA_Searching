//Sequential Search
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void sequentialSearch(const string& filename, const string& targetWord) {
    ifstream file(filename);
    string word;
    int count = 0;

    // Membaca file dan mencari kata
    if (file.is_open()) {
        while (file >> word) {
            if (word == targetWord) {
                count++;
            }
        }
        file.close();
    } else {
        cout << "Tidak dapat membuka file." << endl;
        return;
    }

    cout << "Kata \"" << targetWord << "\" ditemukan sebanyak " << count << " kali." << endl;
}

int main() {
    string filename = "eBook.txt";
    string targetWord;

    cout << "Masukkan kata yang ingin dicari: ";
    cin >> targetWord;

    sequentialSearch(filename, targetWord);

    return 0;
}
