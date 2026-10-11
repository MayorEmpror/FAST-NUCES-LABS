#include <iostream>
#include <string>
using namespace std;

class student {
private:
    string name;
    float* marks;
public:
    student() : marks(nullptr) {}

    student(string name, float marksArr[]) : name(name) {
        marks = new float[5];
        for (int i = 0; i < 5; i++) {
            marks[i] = marksArr[i];
        }
    }

    student(const student& other) : name(other.name) {
        marks = new float[5];
        for (int i = 0; i < 5; i++) {
            marks[i] = other.marks[i];
        }
    }

    student& operator=(const student& other) {
        if (this != &other) {
            name = other.name;
            if (marks) delete[] marks;
            marks = new float[5];
            for (int i = 0; i < 5; i++) {
                marks[i] = other.marks[i];
            }
        }
        return *this;
    }

    float calcavg() const {
        float sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum / 5.0f;
    }

    ~student() {
        delete[] marks;
    }
};


class department {
private:
    string name;
    int num_std;
    student* stds;
public:
    department() : num_std(0), stds(nullptr) {}

    department(string name, int num_std, student stdsArr[]) : name(name), num_std(num_std) {
        stds = new student[num_std];
        for (int i = 0; i < num_std; i++) {
            stds[i] = stdsArr[i];  // uses student assignment operator
        }
    }

    department(const department& other) : name(other.name), num_std(other.num_std) {
        stds = new student[num_std];
        for (int i = 0; i < num_std; i++) {
            stds[i] = other.stds[i];
        }
    }

    department& operator=(const department& other) {
        if (this != &other) {
            name = other.name;
            if (stds) delete[] stds;
            num_std = other.num_std;
            stds = new student[num_std];
            for (int i = 0; i < num_std; i++) {
                stds[i] = other.stds[i];
            }
        }
        return *this;
    }

    string getname() const {
        return name;
    }

    float highestmarks() const {
        if (num_std == 0) return 0.0f;
        float highest = stds[0].calcavg();
        for (int i = 1; i < num_std; i++) {
            float avg = stds[i].calcavg();
            if (avg > highest)
                highest = avg;
        }
        return highest;
    }

    float lowestmarks() const {
        if (num_std == 0) return 0.0f;
        float lowest = stds[0].calcavg();
        for (int i = 1; i < num_std; i++) {
            float avg = stds[i].calcavg();
            if (avg < lowest)
                lowest = avg;
        }
        return lowest;
    }

    float avgmarks() const {
        if (num_std == 0) return 0.0f;
        float sum = 0;
        for (int i = 0; i < num_std; i++) {
            sum += stds[i].calcavg();
        }
        return sum / num_std;
    }

    ~department() {
        delete[] stds;
    }
};


class university {
private:
    string name;
    int num_dept;
    department* depts;
public:
    university() : num_dept(0), depts(nullptr) {}

    university(string name, department deptsArr[], int num_dept) : name(name), num_dept(num_dept) {
        depts = new department[num_dept];
        for (int i = 0; i < num_dept; i++) {
            depts[i] = deptsArr[i];
        }
    }

    university(const university& other) : name(other.name), num_dept(other.num_dept) {
        depts = new department[num_dept];
        for (int i = 0; i < num_dept; i++) {
            depts[i] = other.depts[i];
        }
    }

    university& operator=(const university& other) {
        if (this != &other) {
            name = other.name;
            if (depts) delete[] depts;
            num_dept = other.num_dept;
            depts = new department[num_dept];
            for (int i = 0; i < num_dept; i++) {
                depts[i] = other.depts[i];
            }
        }
        return *this;
    }

    void calchighest_perdepts() const {
        cout << "Highest marks from each department:" << endl;
        for (int i = 0; i < num_dept; i++) {
            cout << depts[i].getname() << " : " << depts[i].highestmarks() << endl;
        }
    }

    void callowest_perdepts() const {
        cout << "Lowest marks from each department:" << endl;
        for (int i = 0; i < num_dept; i++) {
            cout << depts[i].getname() << " : " << depts[i].lowestmarks() << endl;
        }
    }

    void calcavg_perdepts() const {
        cout << "Average marks from each department:" << endl;
        for (int i = 0; i < num_dept; i++) {
            cout << depts[i].getname() << " : " << depts[i].avgmarks() << endl;
        }
    }

    ~university() {
        delete[] depts;
    }
};


int main() {
    float marks1[5] = {90, 80, 70, 60, 50};
    float marks2[5] = {85, 75, 65, 55, 45};
    student s1("Alice", marks1);
    student s2("Bob", marks2);

    student cs_students[] = { s1, s2 };
    department cs("Computer Science", 2, cs_students);

    float marks3[5] = {70, 60, 80, 90, 100};
    student s3("Charlie", marks3);
    student mech_students[] = { s3 };
    department mech("Mechanical", 1, mech_students);

    department depts[] = { cs, mech };
    university uni("My University", depts, 2);

    uni.calchighest_perdepts();
    uni.callowest_perdepts();
    uni.calcavg_perdepts();

    return 0;
}
 