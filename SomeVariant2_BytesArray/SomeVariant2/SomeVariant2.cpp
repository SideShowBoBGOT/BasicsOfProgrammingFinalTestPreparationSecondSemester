#include <iostream>
#include<list>
#include<string>
#include<cmath>
#define BITS 8
using namespace std;
class Bytes {
private:
    char* arr;
    int sizeBytes;
public:
    Bytes() {}
    Bytes(int sizeBytes) {
        if (sizeBytes == 1 || sizeBytes == 2 || sizeBytes == 4) {
            this->sizeBytes = sizeBytes;
            this->arr = new char[sizeBytes * BITS + 1];
            for (int i = 0; i < sizeBytes*BITS; i++)
            {
                arr[i] = '0';
            }
            arr[sizeBytes * BITS] = '\0';
        }
        else {
            throw invalid_argument("Out of size");
        }
    }
    void setNumber(int number) {
        if (number > pow(2, sizeBytes*BITS) - 1)
            throw invalid_argument("number is too large");
        list<int>mods;
        if (number != 0) {
            
            while (number != 1) {
                mods.push_back(number % 2);
                number = number / 2; 
            }
            mods.push_back(1);
            mods.reverse();
        }
        int index = sizeBytes*BITS - mods.size();
        for (auto i = begin(mods); i != end(mods); i++, index++)
        {
            arr[index] = to_string(*i)[0];
        }
    }
    Bytes& operator |(const Bytes& other) {
        list<char>bits1;
        list<char>bits2;
        for (int i = 0; i < this->sizeBytes*BITS; i++)
        {
            bits1.push_back(this->arr[i]);
        }
        for (int i = 0; i < other.sizeBytes*BITS; i++)
        {
            bits2.push_back(other.arr[i]);
        }
        
        bits1.reverse();
        bits2.reverse();
        auto i = begin(bits1);
        auto j = begin(bits2);
        if (bits1.size() <= bits2.size()) {
            for (;i != end(bits1); i++, j++)
            {
                int a = (*i == '0') ? 0 : 1;
                int b = (*j == '0') ? 0 : 1;
                *i = to_string(a | b)[0];
            }
        }
        else {
            for (;j != end(bits2); i++, j++)
            {
                int a = (*i == '0') ? 0 : 1;
                int b = (*j == '0') ? 0 : 1;
                *i = to_string(a | b)[0];
            }
        }
        bits1.reverse();
        bits2.reverse();
        
        auto it = begin(bits1);
        for (int i = 0; i < this->sizeBytes*BITS; i++, it++)
        {
            arr[i] = *it;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Bytes& obj);
};
ostream& operator<<(ostream& out, const Bytes& obj) {
    out << obj.arr;
    return out;
}

int main()
{
    Bytes b1 = Bytes(1);
    Bytes b2 = Bytes(2);
    b1.setNumber(29);
    b2.setNumber(11);
    cout << b1 << endl;
    cout << b2 << endl;
    b1 = b1 | b2;
    cout << b1 << endl;
}
