#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

const int MONTHS = 12;

// ---------- دوال الحساب ----------

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

// ---------- دوال التحقق من المدخلات ----------

// يقرأ رقم موجب (0 أو أكبر) ويكرر السؤال إذا كان المدخل غلط
double readPositive(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            return value;
        }
        cout << "Invalid input. Enter a number that is 0 or more.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// يقرأ اختيار القائمة كرقم صحيح
int readChoice() {
    int choice;
    while (true) {
        cout << "Choose: ";
        if (cin >> choice) {
            return choice;
        }
        cout << "Invalid input. Enter a number from the menu.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// يقرأ قراءات كل الشهور من المستخدم
void enterReadings(double usage[], int size) {
    for (int i = 0; i < size; i++) {
        string prompt = "Month " + to_string(i + 1) + " usage (kWh): ";
        usage[i] = readPositive(prompt);
    }
    cout << "Readings saved." << endl;
}

// ---------- دالة حفظ التقرير ----------

// تكتب القراءات والنتائج في ملف report.txt
void saveReport(const double usage[], int size) {
    ofstream out("report.txt");
    if (!out) {                                   // نتأكد إن الملف انفتح
        cout << "Error: could not create report file." << endl;
        return;
    }

    out << "Electricity Usage Report" << endl;
    out << "-------------------------" << endl;
    for (int i = 0; i < size; i++) {
        out << "Month " << i + 1 << ": " << usage[i] << " kWh" << endl;
    }
    out << "-------------------------" << endl;
    out << "Total: " << totalUsage(usage, size) << " kWh" << endl;
    out << "Average: " << averageUsage(usage, size) << " kWh" << endl;
    out << "Highest month: " << maxMonth(usage, size) + 1 << endl;
    out << "Lowest month: " << minMonth(usage, size) + 1 << endl;

    out.close();
    cout << "Report saved to report.txt" << endl;
}

// ---------- البرنامج الرئيسي ----------

int main() {
    double usage[MONTHS] = {320, 290, 410, 380, 450, 510, 530, 500, 420, 360, 310, 300};
    int choice;

    do {
        cout << "\n===== Electricity Tracker =====" << endl;
        cout << "1) Total consumption" << endl;
        cout << "2) Average consumption" << endl;
        cout << "3) Highest month" << endl;
        cout << "4) Lowest month" << endl;
        cout << "5) Enter new readings" << endl;
        cout << "6) Save report to file" << endl;
        cout << "0) Exit" << endl;
        choice = readChoice();

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
            case 5:
                enterReadings(usage, MONTHS);
                break;
            case 6:
                saveReport(usage, MONTHS);
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
