#include <iostream>
#include <lib.hpp>
#include <pid.hpp>


int main() {
    double input = 0.1;
    double result = input;
    double setPoint = 1.0;
    double kp = 1.1;
    double kd = 0.4;
    double ki = 0.0;
    pid controller(kp, ki, kd);
    while (result != setPoint) {
        result = controller.calcPID(input, setPoint);
        std::cout << "The result is " << result << endl;
    }
    // dummy();
    return 0;
}

