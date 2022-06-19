#include <iostream>
using namespace std;
class Slot {
public:
    int key;
    string data;
    bool isUsed;
    Slot() {
        isUsed = false;
    }
};
class HashClose {
private:
    int size;
    Slot* table;
    int hash(int key) {
        return key % 13;
    }
    void increaseTable() {
        Slot* newTable = new Slot[(int)(size * 1.5)];
        for (int i = 0; i < size; i++)
        {
            newTable[i] = table[i];
        }
        delete[] table;
        size *= 1.5;
        table = newTable;
        return;
    }
    void decreaseTable() {
        Slot* newTable = new Slot[(int)(size * 0.66666666)];
        for (int i = 0; i < (int)(size * 0.666666666); i++)
        {
            newTable[i] = table[i];
        }
        delete[] table;
        size *= 0.666666666;
        table = newTable;
        return;
    }
public:
    HashClose(int size) {
        this->size = size;
        this->table = new Slot[size];
    }

    void update(int key, string data) {
        int hkey = hash(key);
        while (hkey < size && table[hkey].key != key && table[hkey].isUsed == true) {
            hkey += 3;
            if (hkey > (int)(size / 2))
                increaseTable();
        }
        table[hkey].data = data;
        table[hkey].key = key;
        table[hkey].isUsed = true;
        return;
    }
    void print() {
        for (int i = 0; i < size; i++)
        {
            if (table[i].isUsed) {
                cout << "[HASH]" << "\t" << hash(table[i].key) << "\t"
                    << "[KEY]" << "\t" << table[i].key << "\t"
                    << "[DATA]" << "\t" << table[i].data << "\t" << endl;
            }
        }
        cout << "[SIZE]" << "{" << size << "}" << endl;
    }
    void remove(int key) {
        int hkey = hash(key);
        while (hkey < size && table[hkey].key != key) {
            hkey += 3;
        }
        if (hkey >= size)
            throw invalid_argument("received non-existing key");
        table[hkey].isUsed = false;
        int lastUsedSlotIndex;
        for (int i = size; i >= 0; i--)
        {
            if (table[i].isUsed == true) {
                lastUsedSlotIndex = i;
                break;
            }

        }
        if (lastUsedSlotIndex < (int)(size * 0.25))
            decreaseTable();
        return;
    }
};

int main()
{
    HashClose ht = HashClose(30);

    for (int i = 0; i < 60; i++)
    {
        string symb = "";
        int key = rand() % 60 + 33;
        symb += (char)(key);
        ht.update(i, symb);
    }
    ht.print();
    
}
