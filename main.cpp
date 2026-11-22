#include <iostream>
using namespace std;

const int MONTHS = 12;

double totalUsage(const double usage[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += usage[i];
    }
    return total;
}

double averageUsage(const double usage[], int size) {
    return totalUsage(usage, size) / size;
}

int maxMonth(const double usage[], int size) {
    int best = 0;
    for (int i = 1; i < size; i++) {
        if (usage[i] > usage[best]) {
            best = i;
        }
    }
    return best;
}

int minMonth(const double usage[], int size) {
    int best = 0;
    for (int i = 1; i < size; i++) {
        if (usage[i] < usage[best]) {
            best = i;
        }
    }
    return best;
}

int main() {
    double usage[MONTHS] = {320, 290, 410, 380, 450, 510, 530, 500, 420, 360, 310, 300};
    int choice;

    do {
        cout << "\n===== Electricity Tracker =====" << endl;
        cout << "1) Total consumption" << endl;
        cout << "2) Average consumption" << endl;
        cout << "3) Highest month" << endl;
        cout << "4) Lowest month" << endl;
        cout << "0) Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Total: " << totalUsage(usage, MONTHS) << " kWh" << endl;
                break;
            case 2:
                cout << "Average: " << averageUsage(usage, MONTHS) << " kWh" << endl;
                break;
            case 3:
                cout << "Highest month: " << maxMonth(usage, MONTHS) + 1 << endl;
                break;
            case 4:
                cout << "Lowest month: " << minMonth(usage, MONTHS) + 1 << endl;
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 0);

    return 0;
}


