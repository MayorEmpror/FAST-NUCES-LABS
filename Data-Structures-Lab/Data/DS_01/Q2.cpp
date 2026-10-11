#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    float score;

public:
    // Constructor
    Exam(const char* name, const char* date, float marks) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = marks;
    }

    // Destructor
    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    // Method to display exam details
    void displayDetails() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }

    // Method to modify student name (to show effect of shallow copy)
    void changeName(const char* newName) {
        strcpy(studentName, newName);
    }
};

int main() {
    // Create original exam object
    Exam exam1("Hashir", "01-08-88", 52.084);
    cout << "Original exam1 details:" << endl;
    exam1.displayDetails();

    // Shallow copy (copy constructor not defined → default shallow copy used)
    Exam exam2 = exam1;  // SHALLOW COPY

    cout << "\nCopied exam2 details before change:" << endl;
    exam2.displayDetails();

    // Change name in exam2
    exam2.changeName("Tamseel");

    cout << "\nAfter changing name in exam2:" << endl;
    cout << "exam1 details:" << endl;
    exam1.displayDetails();
    cout << "exam2 details:" << endl;
    exam2.displayDetails();

    //issue:
    //a.out(86222,0x1e8304f80) malloc: Double free of object 0x1536060b0
    //a.out(86222,0x1e8304f80) malloc: *** set a breakpoint in malloc_error_break to debug
    //zsh: abort      ./a.out
    //both objects try to delete the same memory results in an undefined behavior
    return 0;
}
