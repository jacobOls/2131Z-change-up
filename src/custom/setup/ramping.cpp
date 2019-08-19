#include "main.h"
#include "custom/setup/ramping.hpp"
#include <cmath>
Ramping::Ramping(double CV, double CM, double max, double min) {
  changeVal = CV;
  changeMsec = CM;
  Max = max;
  Min = min;
}

double Ramping::calculate() {
  if (valRequested == valOutput) return valOutput;
  if (valRequested > valOutput)
    valOutput += changeVal;
  else if (valRequested < valOutput)
    valOutput -= changeVal;
  //limit Val
  if (valOutput > Max) valOutput = Max;
  if (valOutput < Min) valOutput = Min;
  if (std::abs(valRequested - valOutput) < changeVal) valOutput = valRequested; //if error is within changeVal then set to it exactly; stabilizes the output durring the last loop

  return valOutput;
}
double Ramping::calculate(double cv) {
  changeVal = cv;
  return calculate();
}

void Ramping::request(int val) {
  valRequested = val;
}
void Ramping::instant(int val) {
  request(val);
  valOutput = val;
}

double Ramping::output() {
  return valOutput;
}
void Ramping::set_output(double v){
valOutput = v;
  
}
double Ramping::get_requested() {
  return valRequested;
}
int Ramping::get_changeMsec() {
  return changeMsec;
}

double Ramping::get_changeVal() {
  return changeVal;
}
void Ramping::update_changeVal(double v) {
  changeVal = v;
}
double Ramping::get_max() {
  return Max;
}
double Ramping::get_min() {
  return Min;
}
