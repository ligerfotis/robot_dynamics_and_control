#include <stdio.h>
#include <math.h>

// Excercise 5
static double prev_theta_dot = 0;
static int count = 0;
double PD_control(theta, theta_dot, theta_ref, theta_dot_ref)
double theta, theta_dot, theta_ref, theta_dot_ref;
{
double I = 0.036; 
double B = 0.1;
double mgl = 1.1760;
double theta_double_dot = (theta_dot - prev_theta_dot)*500;
double tau_prime, tau;

double K_p = 32;
double K_v = 2 * sqrt(K_p);
double error = (theta - theta_ref); 

tau = -K_p * error - K_v *theta_dot;
tau_prime = I * tau - B * theta_dot + mgl * cos(theta);
//printf("error: %.5lf\n", error);
prev_theta_dot = theta_dot;
  return(tau_prime);
}

// This is for excercise 4
/*
static double prev_theta_dot = 0;
static int count = 0;
double PD_control(theta, theta_dot, theta_ref, theta_dot_ref)
double theta, theta_dot, theta_ref, theta_dot_ref;
{
double I = 0.1; 
double B = 0;
double G = 0;
double theta_double_dot = (theta_dot - prev_theta_dot)*500;
double tau_prime, tau;
double mgl = 1.1760;
B = - 0.1;
I = 0.036;
tau = 0;
//tau_prime = tau;
//tau_prime = tau + (mgl * cos(theta));
//tau_prime = tau + (B * theta_dot) + (mgl * cos(theta));
tau_prime = tau + I * theta_double_dot + B * theta_dot + mgl * cos(theta);

//mgl = tau_prime / cos(theta);
//B = tau/theta_dot;
//I = tau / theta_double_dot;
//printf("mgl: %0.5lf for tau_prime: %0.5lf theta %0.5lf \n", mgl, tau_prime, theta);
//printf("B: %0.5lf for tau_prime: %0.5lf theta_dot %0.5lf \n", B, tau_prime, theta_dot);

if (count < 10){
printf("I: %0.5lf for tau_prime: %0.5lf theta_double_dot %0.5lf \n", I, tau_prime, theta_double_dot);
count++;
}

prev_theta_dot = theta_dot;
  return(tau_prime);
}
*/
