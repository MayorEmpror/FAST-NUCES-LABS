#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Perform Gauss-Jordan elimination
bool gaussJordan(vector<vector<double>> A, vector<double> b, vector<double>& x) {
    int n = A.size();
    // Form augmented matrix
    for (int i = 0; i < n; i++)
        A[i].push_back(b[i]);

    // Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Find pivot
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (abs(A[j][i]) > abs(A[pivot][i]))
                pivot = j;
        if (A[pivot][i] == 0) return false; // Singular

        // Swap rows
        swap(A[i], A[pivot]);

        // Normalize pivot row
        double div = A[i][i];
        for (int j = 0; j <= n; j++)
            A[i][j] /= div;

        // Eliminate other rows
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            double factor = A[j][i];
            for (int k = 0; k <= n; k++)
                A[j][k] -= factor * A[i][k];
        }
    }

    // Extract solution
    x.resize(n);
    for (int i = 0; i < n; i++)
        x[i] = A[i][n];
    return true;
}

// Multiply two matrices
vector<vector<double>> multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    vector<vector<double>> C(n, vector<double>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Compute inverse using Gauss-Jordan
bool invertMatrix(vector<vector<double>> A, vector<vector<double>>& Ainv) {
    int n = A.size();
    Ainv.assign(n, vector<double>(n, 0));

    // Augment with identity
    for (int i = 0; i < n; i++) {
        A[i].resize(2 * n);
        for (int j = 0; j < n; j++)
            A[i][j + n] = (i == j);
    }

    // Gauss-Jordan
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (abs(A[j][i]) > abs(A[pivot][i]))
                pivot = j;
        if (A[pivot][i] == 0) return false; // Singular
        swap(A[i], A[pivot]);

        double div = A[i][i];
        for (int j = 0; j < 2 * n; j++)
            A[i][j] /= div;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            double factor = A[j][i];
            for (int k = 0; k < 2 * n; k++)
                A[j][k] -= factor * A[i][k];
        }
    }

    // Extract inverse
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Ainv[i][j] = A[i][j + n];

    return true;
}

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter coefficient matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter constants vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << fixed << setprecision(4);

    // Method 1: Gauss-Jordan
    vector<double> x;
    if (gaussJordan(A, b, x)) {
        cout << "\nSolution by Gauss-Jordan:\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << x[i] << "\n";
    } else {
        cout << "\nSystem has no unique solution (Gauss-Jordan failed).\n";
    }

    // Method 2: Inverse
    vector<vector<double>> Ainv;
    if (invertMatrix(A, Ainv)) {
        cout << "\nInverse of A:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(10) << Ainv[i][j];
            cout << "\n";
        }

        vector<vector<double>> bmat(n, vector<double>(1));
        for (int i = 0; i < n; i++) bmat[i][0] = b[i];
        vector<vector<double>> sol = multiply(Ainv, bmat);

        cout << "\nSolution by Inverse Method:\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << sol[i][0] << "\n";
    } else {
        cout << "\nMatrix is singular, inverse does not exist.\n";
    }

    return 0;
}
