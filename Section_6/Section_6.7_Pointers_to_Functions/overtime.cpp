#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void Pay(double rate, double hours);

int main()
{   
    Pay(10, 41);
    return 0;
}

void Pay(double rate, double hours)
{
    double pay;

    if (hours > 40) {
        float overtimeHours = hours - 40;
        pay = (40 * rate) + (overtimeHours * (rate * 1.5));
    } else {
        pay = (hours * rate);
    }
    cout << "Total Paycheck for this period: $" << pay <<endl;
}