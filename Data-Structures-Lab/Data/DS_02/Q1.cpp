#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** Mat;

public:
    // Parametric constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        Mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            Mat[i] = new int[cols];
        }
        cout << "Enter matrix values (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> Mat[i][j];
            }
        }
    }

    // Default constructor
    Matrix() : rows(0), cols(0), Mat(nullptr) {}

    // Copy constructor
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        Mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            Mat[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                Mat[i][j] = other.Mat[i][j];
            }
        }
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        // Free old memory
        delete_mat();

        // Allocate new
        rows = other.rows;
        cols = other.cols;
        Mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            Mat[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                Mat[i][j] = other.Mat[i][j];
            }
        }
        return *this;
    }

    // Destructor
    ~Matrix() {
        delete_mat();
    }

    // Proper memory cleanup
    void delete_mat() {
        if (Mat) {
            for (int i = 0; i < rows; i++) {
                delete[] Mat[i];
            }
            delete[] Mat;
        }
        Mat = nullptr;
        rows = cols = 0;
    }

    // Resize matrix
    void Resize(int newrows, int newcols, int initVal = 0) {
        int** newMat = new int*[newrows];
        for (int i = 0; i < newrows; i++) {
            newMat[i] = new int[newcols];
            for (int j = 0; j < newcols; j++) {
                if (i < rows && j < cols) {
                    newMat[i][j] = Mat[i][j]; // copy old values
                } else {
                    newMat[i][j] = initVal;   // new values initialized
                }
            }
        }

        // free old matrix
        delete_mat();

        // update
        Mat = newMat;
        rows = newrows;
        cols = newcols;
    }

    // Transpose
    void Transpose() {
        int old_rows = rows;
        int old_cols = cols;
    
        // build transposed matrix
        int** newMat = new int*[old_cols];
        for (int i = 0; i < old_cols; ++i) {
            newMat[i] = new int[old_rows];
            for (int j = 0; j < old_rows; ++j) {
                newMat[i][j] = Mat[j][i];
            }
        }
    
        // free old storage WITHOUT touching rows or cols
        for (int i = 0; i < old_rows; ++i) {
            delete[] Mat[i];
        }
        delete[] Mat;
    
        // install new storage and update sizes
        Mat  = newMat;
        rows = old_cols;
        cols = old_rows;
    }
    

    // Print (with +2 for odd indices)
    void Print() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = Mat[i][j];
                if ((i + j) % 2 == 1) val += 2; // odd index
                cout << val << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Matrix M(2, 3);
    cout << "\nOriginal:\n";
    M.Print();

    cout << "\nResized to 3x4 (fill=9):\n";
    M.Resize(3, 4, 9);
    M.Print();

    cout << "\nTransposed:\n";
    M.Transpose();
    M.Print();

    return 0;
}
