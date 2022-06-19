#include <iostream>
using namespace std;
class SetInt {
private:
    int index;
    int size;
    int* arr;
public:
    SetInt() {
        this->index = 0;
        this->size = 0;
        this->arr = nullptr;
    }
    int operator[](int i)const {
        return arr[i];
    }
    SetInt(int size) {
        this->index = 0;
        this->size = size;
        this->arr = new int[size];
    }
    SetInt(const SetInt& other) {
        this->size = other.size;
        this->index = other.index;
        this->arr = new int[size];
        memcpy(arr, other.arr, size * sizeof(int));
    }
    bool includes(int data)const {
        for (int i = 0; i < index; i++)
        {
            if (arr[i] == data)
                return true;
        }
        return false;
    }
    void update(int data) {
        if (data < 0 || data>255)
            throw invalid_argument("Invalid data");
        if (this->includes(data))
            throw invalid_argument("Data is already in the set");
        if (index == size)
            throw "Not enough space";
        arr[index] = data;
        index++;
    }
    void remove(int data) {
        if (!this->includes(data))
            throw "Invalid value";
        int* newArr = new int[size];
        for (int i = 0; i < index; i++)
        {
            if (data == arr[i]) {
                int k = i;
                for (int j = 0; j < index - 1; j++)
                {
                    if (j == k)
                        k++;
                    if (k < index)
                        newArr[j] = arr[k];
                }
                delete[] arr;
                arr = newArr;
                index--;
                break;
            }
        }
    }
    SetInt operator ++(int data) {
        if (data < 0 || data>255)
            throw invalid_argument("Invalid data");
        if(this->includes(data))
            throw invalid_argument("Data is already in the set");
        if (index == size)
            throw "Not enough space";
        arr[index] = data;
        index++;
        return *this;
    }
    friend SetInt operator -(SetInt s, const SetInt& other);
    friend ostream& operator <<(ostream& out , const SetInt& s);
};
SetInt operator - (SetInt s, const SetInt& other) {
    bool isIn = false;
    int j = 0;
    do {
        isIn = false;
        for (int i = 0; i < s.index&& !isIn; i++)
        {
            if (other.includes(s.arr[i])) {
                isIn = true;
                j = i;
                s.remove(s.arr[i]);
            }
        }
    } while (isIn);
    return s;
}
ostream& operator <<(ostream& out, const SetInt& s) {
    for (int i = 0; i < s.index; i++)
    {
        out << s.arr[i] << endl;
    }
    
    return out;
}

int main()
{
    SetInt s1 = SetInt(10);
    SetInt s2 = SetInt(10);
    s1.operator++(10);
    s1.operator++(11);
    s1.operator++(12);
    s1.operator++(13);
    s1.operator++(14);
    s2.operator++(10);
    s2.operator++(11);
    s2.operator++(15);
    s2.operator++(17);
    cout << "S1: " << endl << s1 << endl;
    cout << "S2: " << endl << s2 << endl;
    cout << "S3: " << endl << s2 - s1<< endl;
}
