#include "PID.h"
#include <iostream>
using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double K1, double K2, double K3) {
    // initialize coefficients and errors
    Kp = K1;
    Kd = K2;
    Ki = K3;

    // initialize errors
    d_error = 0.;
    p_error = 0.;
    i_error = 0.;
    best_err = 0.;
    // iteration count
    it = 0; 
}

void PID::UpdateError(double cte) {
   d_error = cte - p_error;
   p_error = cte;
   i_error += cte;
   it += 1;
}

double PID::TotalError() {
    // calculates the output of the PID
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}

void PID::Twiddle(){
    // twiddle algorithm - not used currently.
    double dp[] = {1., 1., 1.};
    double p[] = {0., 0., 0.};
    double arrsum = 3.;
    double tol = 0.001;
    double cur_err = 0.;
    best_err = this->TotalError();
    cur_err = 0.;
    while (arrsum > tol){
        for (int i=0; i < 3;i++){
            p[i] += dp[i];
            this->UpdateCoefs(p);
            cur_err = this->TotalError();

            if (cur_err < best_err){
                best_err = cur_err;
                dp[i] *= 1.1;
            }else{
                p[i] -= 2. * dp[i];
                this->UpdateCoefs(p);
                cur_err = this->TotalError();

                if (cur_err < best_err){
                    best_err = cur_err;
                    dp[i] *= 1.1;
                }else{
                    p[i] += dp[i];
                    dp[i] *= 0.9;
                    this->UpdateCoefs(p);
                }

            }
        }
        arrsum = 0.;
        for (int i = 0; i < 3; i++){
            arrsum += dp[i];
        }
    }

}

void PID::UpdateCoefs(double updates[]){
    // update coefficients for pid - not currently used
    Kp = updates[0];
    Kd = updates[1];
    Ki = updates[2];
}