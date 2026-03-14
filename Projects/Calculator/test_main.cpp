#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double multiply(double a, double b) { return a * b; }

double divide(double a, double b) {
    if (b == 0.0) throw invalid_argument("division by zero");
    return a / b;
}

int main() {
    int fails = 0;

    auto expect_eq = [&](double got, double want, const char* name) {
        if (!(fabs(got - want) < 1e-9)) {
            cerr << "FAIL " << name << ": got " << got << " want " << want << '\n';
            ++fails;
        } else {
            cout << "PASS " << name << '\n';
        }
    };

    // Multiplication tests
    expect_eq(multiply(2, 3), 6, "mul 2*3");
    expect_eq(multiply(-2, 3), -6, "mul -2*3");
    expect_eq(multiply(0, 5), 0, "mul 0*5");
    expect_eq(multiply(1.5, 2.0), 3.0, "mul 1.5*2.0");

    // Division tests
    try {
        expect_eq(divide(6, 3), 2, "div 6/3");
    } catch (...) {
        cerr << "FAIL div 6/3: threw exception\n";
        ++fails;
    }

    try {
        divide(1, 0);
        cerr << "FAIL div 1/0: expected exception but none thrown\n";
        ++fails;
    } catch (const invalid_argument&) {
        cout << "PASS div 1/0 throws\n";
    } catch (...) {
        cerr << "FAIL div 1/0: wrong exception type\n";
        ++fails;
    }

    // Some additional edge cases
    expect_eq(multiply(INFINITY, 0), NAN, "mul inf*0 => NaN (platform-dependent)");

    if (fails == 0) {
        cout << "ALL TESTS PASSED\n";
        return 0;
    } else {
        cout << fails << " TEST(S) FAILED\n";
        return 1;
    }
}
