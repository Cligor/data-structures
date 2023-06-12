#include <iostream>
#include <list>

using namespace std;

class HashTable {
    private:
        int* table;
        int length;

        int getHash(string key) {
            int hash = 0;
            for (char c : key) {
                hash += int(c%264);
            }
            return hash%this->length;
        }

    public:
        HashTable() {
            this->length = 10000;
            this->table = new int[this->length];
        }

        bool insert(string key, int value) {
            int hash = getHash(key);
            table[hash] = value;

            return true;
        }

        int getValue(string key) {
            int hash = getHash(key);

            return table[hash];
        }

        bool remove(string key) {
            int hash = getHash(key);
            table[hash] = 0;

            return true;
        }
};

int main() {
    HashTable* dict = new HashTable();\
    cout << dict->getValue("engily") << endl;
    dict->insert("engily", 20);
    cout << dict->getValue("engily") << endl;
    dict->remove("engily");
    cout << dict->getValue("engily") << endl;
    return 0;
}

    