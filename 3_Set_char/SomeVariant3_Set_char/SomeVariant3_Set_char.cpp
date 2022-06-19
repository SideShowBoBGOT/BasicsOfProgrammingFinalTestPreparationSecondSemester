#include <iostream>
using namespace std;
class SetChar {
private:
    int size;
    char* arr;
    int index;
public:
    SetChar() {
        this->index = 0;
        this->size = 0;
        this->arr = nullptr;
    }
    SetChar(int size) {
        this->index = 0;
        this->size = size;
        this->arr = new char[size];
    }
    SetChar(const SetChar& other) {
        this->index = other.index;
        this->size = other.size;
        this->arr = new char[other.size];
        for (int i = 0; i < index; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    void update(char data) {
        for (int i = 0; i < index; i++)
        {
            if (arr[i] == data)
                throw invalid_argument("Element is already in the set");
        }
        arr[index] = data;
        index++;
    }
    bool in(char data) const{
        for (int i = 0; i < index; i++)
        {
            if (arr[i] == data)
                return true;
        }
        return false;
    }

    void remove(char data) {
        bool isIn = false;
        for (int i = 0; i < index; i++)
        {
            if (arr[i] == data) {
                isIn = true;
                char* newArr = new char[size];
                for (int j = 0, k = 0; k < index; j++, k++) {
                    if (k == i)
                        k++;
                    if(k<index)
                        newArr[j] = arr[k];   
                }
                delete[] arr;
                arr = newArr;
                index--;
                break;
            }
        }
        if (!isIn)
            throw invalid_argument("Elemnt is not in the set");

    }
    friend SetChar operator -(SetChar s, const SetChar& other);
    friend ostream& operator <<(ostream& out, const SetChar& s);
};
SetChar operator -(SetChar s, const SetChar& other) {
    bool isIn = false;
    int j = 0;
    do {
        isIn = false;
        for (int i = 0; i < s.index && !isIn; i++)
        {
            if (other.in(s.arr[i]))
            {
                j = i;
                isIn = true;
            }

        }
        if (isIn) {
            s.remove(s.arr[j]);
        }
    } while (isIn);
    return s;
}
ostream& operator <<(ostream& out, const SetChar& s) {
    for (int i = 0; i < s.index; i++)
    {
        out << s.arr[i] << endl;
    } 
    return out;
}
int main()
{
    SetChar s1 = SetChar(10);
    SetChar s2 = SetChar(10);
    s1.update('a');
    s1.update('b');
    s1.update('c');
    s1.update('d');
    s1.update('e');
    s2.update('x');
    s2.update('y');
    s2.update('b');
    s2.update('a');
    cout << "S1: " << endl << s1 << endl;
    cout << "S2: " << endl << s2 << endl;
    cout << "Diff: "<<endl<< s1 - s2 << endl;
}
