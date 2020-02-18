#ifndef LIFT_HPP
#define LIFT_HPP
namespace lift{

  enum class Controllers{
    UP,
    DOWN,
    DEINIT,
    NONE
  };
  void init(void);
  void execute(void);
  void init(void);
  void pulse(void);
  namespace auton{
    void lift(int pos, int velocity,int startTime, double stopTime);
    void liftNoTime(int pos, int velocity);
  }
}


#endif /* end of include guard: LIFT_HPP */
