/**
 * @file pid.hpp
 * @author Tharun V. Puthanveettil (tvpian@umd.edu) and Jay Prajapati (jayp@umd.edu)
 * @brief 
 * @version 0.2
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <pid.hpp>

/**
 * @brief  Setting a starting and a desired ending velocity for a PID controller, 
 * a new velocity is calculated until the object reaches the desired value 
 * 
 */
int main() {
    double input, setPoint, kp, ki, kd, result;
    // User sets PID parameters,final and initial velocity
    std::cout<< "Enter KP" <<std::endl;
    std::cin>> kp;
    std::cout<< "Enter KI" <<std::endl;
    std::cin>> ki;
    std::cout<< "Enter KD" <<std::endl;
    std::cin>> kd;
    std::cout<< "Enter the initial velocity of the moving robot" <<std::endl;
    std::cin>> input;
    std::cout<<
        "Enter the (end) desired velocity of the moving robot" <<std::endl;
    std::cin>> setPoint;
    result = input;
    // pid constructor
    PID controller(kp, ki, kd);
    // loop used to run until robot meets specific velocity
    while (result != setPoint) {
        result = controller.calcPID(input, setPoint);
        std::cout << "The result is " << result << std::endl;
    }
    return 0;
}

