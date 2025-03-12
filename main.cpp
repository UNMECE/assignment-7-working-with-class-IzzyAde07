#include <iostream>
#include <cmath>
using namespace std;

class Electric_Field {
private:
    double *E;
public:
    // Default constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }

    // Parametrized constructor
    Electric_Field(double Ex, double Ey, double Ez) {
        E = new double[3]{Ex, Ey, Ez};
    }

    // Destructor
    ~Electric_Field() {
        delete[] E;
    }

    // Setter functions
    void setComponents(double Ex, double Ey, double Ez) {
        E[0] = Ex;
        E[1] = Ey;
        E[2] = Ez;
    }

    // Getter functions
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Calculate magnitude
    double calculateMagnitude() const {
        return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
    }

    // Calculate inner product
    double calculateInnerProduct() const {
        return E[0]*E[0] + E[1]*E[1] + E[2]*E[2];
    }
};

class Magnetic_Field {
private:
    double *M;
public:
    // Default constructor
    Magnetic_Field() {
        M = new double[3]{0.0, 0.0, 0.0};
    }

    // Constructor with components
    Magnetic_Field(double Mx, double My, double Mz) {
        M = new double[3]{Mx, My, Mz};
    }

    // Destructor
    ~Magnetic_Field() {
        delete[] M;
    }

    // Setter functions
    void setComponents(double Mx, double My, double Mz) {
        M[0] = Mx;
        M[1] = My;
        M[2] = Mz;
    }

    // Getter functions
    double getX() const { return M[0]; }
    double getY() const { return M[1]; }
    double getZ() const { return M[2]; }

    // Calculate magnitude
    double calculateMagnitude() const {
        return sqrt(M[0]*M[0] + M[1]*M[1] + M[2]*M[2]);
    }

    // Calculate unit vector
    void calculateUnitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude != 0) {
            cout << "Unit Vector: (" << M[0] / magnitude << ", " << M[1] / magnitude << ", " << M[2] / magnitude << ")" << endl;
        } else {
            cout << "Unit Vector: (0, 0, 0)" << endl;
        }
    }
};

int main() {
    // Electric Field objects
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);

    E_default.setComponents(3.0, 4.0, 5.0);

    cout << "Electric Field Magnitude (default): " << E_default.calculateMagnitude() << endl;
    cout << "Electric Field Inner Product: " << E_default.calculateInnerProduct() << endl;

    cout << "Electric Field Magnitude (components): " << E_components.calculateMagnitude() << endl;
    cout << "Electric Field Inner Product: " << E_components.calculateInnerProduct() << endl;

    // Magnetic Field objects
    Magnetic_Field M_default;
    Magnetic_Field M_components(5.0, 12.0, 0.0);

    M_default.setComponents(1.0, 2.0, 2.0);

    cout << "Magnetic Field Magnitude (default): " << M_default.calculateMagnitude() << endl;
    M_default.calculateUnitVector();

    cout << "Magnetic Field Magnitude (components): " << M_components.calculateMagnitude() << endl;
    M_components.calculateUnitVector();

    return 0;
}
