#ifndef INTAKE_HPP
#define INTAKE_HPP
namespace intake{

  void intake(void);
  void outake(void);
  void spin(void);
  void intakecontrol(void);
  void stopIfNothingIsPressed(void);
  namespace auton{
    void intakeOn(double targetVelocity);
    void intakeOff(void);

  }
}


#endif /* end of include guard: INTAKE_HPP */
