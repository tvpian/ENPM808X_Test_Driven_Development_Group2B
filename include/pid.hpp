#pragma once

#include <iostream>
#include <ctime.h>
#include <time.h>

using namespace std;


class pid {
    double kp, ki, kd;
    double current_time, previous_time;
    double error;
    double lastError;
    double input, output, setPoint;
    double cumError, rateError;

 public:
    pid(double kp_n, double ki_n, double kd_n) {
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

    double calcPID(double input, double setPoint) {
        current_time = clock();
        double elapsedTime = (current_time - previous_time)/ CLOCKS_PER_SEC;
        cout << "The current time is " << current_time << endl
        << "The elapsed time is " << elapsedTime << endl;
        error = setPoint - input;
        cout << "The error is " << error << endl;
        cumError += error * elapsedTime;
        cout << "The Cumilative error is " << cumError << endl;
        rateError = (error-lastError)/elapsedTime;
        cout << "The rate error is " << rateError << endl;
        output = kp*error + ki*cumError + kd*rateError;
        // cout << "The PID output is " <<  output;
        lastError = error;
        previous_time = current_time;
        return output;
    }
};
