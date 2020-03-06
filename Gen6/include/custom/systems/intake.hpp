#ifndef INTAKE_HPP
#define INTAKE_HPP
namespace intake {

enum class Controllers { IN, OUT, SPINR, SPINL, DEINIT, MACRO, SLOWOUT, NONE };
void init(void);
void execute(void);
namespace auton {
void isIt8or9(int time1, int time2);
void stackReverseAuton(double distance, double driveSpeed, double intakeSpeed);
void intakeOn(double targetVelocity);
void intakeOff();
} // namespace auton
} // namespace intake

#endif /* end of include guard: INTAKE_HPP */
