#ifndef INTAKE_HPP
#define INTAKE_HPP
namespace intake{
enum class Controllers{INTAKING,OUTTAKING,SPINNINGLEFT,SPINNINGRIGHT,MACRO,DEINIT,NONE};
  void intake(void);
  void stackReverse();
  void execute();
  namespace auton{
    void intakeOn(double targetVelocity);
    void intakeOff(void);

  }
}


#endif /* end of include guard: INTAKE_HPP */
