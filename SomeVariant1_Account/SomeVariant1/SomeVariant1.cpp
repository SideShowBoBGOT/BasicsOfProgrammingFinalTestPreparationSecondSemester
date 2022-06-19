#include <iostream>
#include<vector>
using namespace std;
class Account {
private:
    string fname;
    double balance;
public:
    Account() {}
    Account(string fname){
        this->fname = fname;
    }
    Account(string fname, double balance) :Account(fname) {
        this->balance = balance;
    }
    Account& operator -(double pay) {
        if (balance < pay)
            throw invalid_argument("Not enough to pay");
        balance -= pay;
        return *this;
    }
    void operator +=(double& sum) {
        sum += balance;
    }
    void print() {
        cout << "Name: " << fname << endl
            << "Balance: " << balance << endl;
    }
};

int main()
{
    Account accs[10];
    for (int i = 0; i < 10; i++)
    {
        string fname = "";
        fname += (char)(i + 60);
        double balance = (rand() % 100);
        accs[i] = Account(fname, balance);
        accs[i].print();
    }
    double sum = 0;
    for (int i = 0; i < 10; i++)
    {
        accs[i] += sum;
    }
    cout << "Sum: " << sum << endl;

}

