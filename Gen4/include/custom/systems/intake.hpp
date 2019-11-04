#ifndef INTAKE_HPP
#define INTAKE_HPP

namespace intake
{

enum class Controllers
{
  IN,
  OUT,
  SPINR,
  SPINL,
  DEINIT,
  NONE
};
void init(void);
namespace auton
{
void stackReverseAuton(double distance, double driveSpeed, double intakeSpeed);
void intakeOn(double targetVelocity);
void intakeOff();
} // namespace auton
} // namespace intake

#endif /* end of include guard: INTAKE_HPP */
