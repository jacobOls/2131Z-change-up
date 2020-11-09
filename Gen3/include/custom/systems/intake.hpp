#ifndef INTAKE_HPP
#define INTAKE_HPP

namespace intake {
enum class State { IN, OUT, DEINIT, MANUAL, NONE };
void init(void);
} // namespace intake
namespace auton {
void runIntake(int velocity);
}
#endif /* end of include guard: INTAKE_HPP */
