#ifndef INTAKE_HPP
#define INTAKE_HPP
namespace intake{
enum class Controllers{INTAKING,OUTTAKING,SPINNINGLEFT,SPINNINGRIGHT,DEINIT,NONE};
  void intake(void);
  namespace auton{
    void intakeOn(double targetVelocity);
    void intakeOff(void);

  }
}


#endif /* end of include guard: INTAKE_HPP */
