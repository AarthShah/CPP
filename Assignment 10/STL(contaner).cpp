#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;


double calculateAverage(const vector<int>& marks) {
    return accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
}

int main() {
    map<string, vector<int>>studentRecords;
    char choice;

    do {
        cout << "1. Add Student Record\n2. Display All Records\n3. Display Topper\n4. Exit\n";
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        switch (option) {
            case 1: { 
                string name;
                vector<int> marks(3);

                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter marks for 3 subjects: ";
                for (int& mark : marks) {
                    cin >> mark;
                }

                studentRecords[name] = marks;
                cout << "Record added successfully!\n";
                break;
            }
            case 2: { 
                cout << "\nStudent Records:\n";
                for (const auto& [name, marks] : studentRecords) {
                    double average = calculateAverage(marks);
                    cout << "Student: " << name << ", Marks: ";
                    for (int mark : marks) {
                        cout << mark << " ";
                    }
                    cout << ", Average: " << average << endl;
                }
                break;
            }
            case 3: { 
                if (studentRecords.empty()) {
                    cout << "No records available.\n";
                } else {
                    auto topper = max_element(studentRecords.begin(), studentRecords.end(),
                        [](const auto& a, const auto& b) {
                            return calculateAverage(a.second) < calculateAverage(b.second);
                        });

                    double topAverage = calculateAverage(topper->second);
                    cout << "Topper: " << topper->first << " with average " << topAverage << endl;
                }
                break;
            }
            case 4: { 
                cout << "Exiting program...\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

