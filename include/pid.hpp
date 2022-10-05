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
#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_
#include <iostream>
#include <ctime.h>
#include <time.h>
/**
 * @brief PID controller used to control a robot, taking starting at a specific velocity and eventually reaching the final velocity
 * 
 */
class PID {
    double kp, ki, kd;
    double current_time, previous_time;
    double error;
    double lastError;
    double input, output, setPoint;
    double cumError, rateError;

 public:
    /**
     * @brief Construct a new PID object
     * 
     * @param kp_n 
     * @param ki_n 
     * @param kd_n 
     */
    PID(double kp_n, double ki_n, double kd_n) {
        kp = kp_n;
        ki = ki_n;
        kd = kd_n;
        current_time = 0;
        previous_time = 0;
        error = 0;
        lastError = 0;
        cumError = 0;
        rateError = 0;
    }

    /**
     * @brief PID Calculator using the given PID parameters, starting and final velocity  
     * 
     * @param input
     * @param setPoint 
     * @return output 
     */
    double calcPID(double input, double setPoint) {
        // Internal clock
        current_time = clock();
        // Computes time span
        double elapsedTime = (current_time - previous_time)/ CLOCKS_PER_SEC;
        std::cout << "The current time is " << current_time << std::endl
        << "The elapsed time is " << elapsedTime << std::endl;
        // Calculates error
        error = setPoint - input;
        std::cout << "The error is " << error << std::endl;
        // Sums up cumilative error
        cumError += error * elapsedTime;
        std::cout << "The Cumilative error is " << cumError << std::endl;
        // Calculates error rate
        rateError = (error-lastError)/elapsedTime;
        std::cout << "The rate error is " << rateError << std::endl;
        // Adds up all errors into output
        output = kp*error + ki*cumError + kd*rateError;
        lastError = error;
        previous_time = current_time;
        return output;
    }
    /**
     * @brief Used in tests, to check the kp,ki and kd value
     * 
     * @param param 
     * @return double 
     */
    double getParam(char* param) {
        if (param == "ki") {
            return ki;
        } else if (param == "kp") {
            return kp;
        } else if (param == "kd") {
            return kd;
        } else {
            return 0;
        }
    }
};
#endif  // INCLUDE_PID_HPP_