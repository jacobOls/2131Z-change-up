#ifndef RAMPING_HPP
#define RAMPING_HPP
//needs to remove gate
class Ramping{
protected:
  double changeVal = 1; //the amout of Val change per execute
  int changeMsec = 5;   //the amount of time inbetween executes

  double valRequested = 0; //used to request value
  double valOutput = 0;    //val output
  double Max = 100;        //maximum value
  double Min = -100;       //minimum value

public:
  bool enabled = false;
  //need to move to prvotected

  Ramping(double CV, double CM, double max, double min);

  double calculate();
  double calculate(double cv);
  void request(int val);
  void instant(int val);

  double output();
  void set_output(double v);

  double get_requested();
  int get_changeMsec();
  double get_changeVal();
  void update_changeVal(double v);

  double get_max();
  double get_min();
};

#endif /* end of include guard: RAMPING_HPP */
