#include <iostream>
using namespace std;

int main() {
    int choice;
    double amount, co2 = 0;

    cout << "===== CO2 CALCULATOR =====" << endl;
    cout << "1. Car" << endl;
    cout << "2. Bus" << endl;
    cout << "3. Train" << endl;
    cout << "4. Flight" << endl;
    cout << "5. Electricity" << endl;
    cout << "6. Book Printing" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice < 1 || choice > 6) {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    if (choice <= 4)
        cout << "Enter distance in km: ";
    else if (choice == 5)
        cout << "Enter electricity in kWh: ";
    else
        cout << "Enter number of pages: ";

    cin >> amount;

    if (!cin || amount < 0) {
        cout << "Invalid amount!" << endl;
        return 1;
    }

    if (choice == 1)
        co2 = amount * 0.20;
    else if (choice == 2)
        co2 = amount * 0.10;
    else if (choice == 3)
        co2 = amount * 0.04;
    else if (choice == 4)
        co2 = amount * 0.25;
    else if (choice == 5)
        co2 = amount * 0.40;
    else if (choice == 6)
        co2 = amount * 0.0007;

    cout << "\nEstimated CO2: "
         << co2 << " kg CO2e" << endl;

    return 0;
}
