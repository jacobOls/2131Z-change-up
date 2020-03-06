#ifndef TILTER_HPP
#define TILTER_HPP
namespace tilter {
enum class Controllers { FORWARD, BACKWARD, RETURN, DEINIT, TOUP, NONE };
extern bool trayLock;
void execute(void);
void init(void);
namespace auton {
void tilterTime(int pos, int velocity, int startTime, int stop);
void tilter(int pos, int velocity);
void tilterDown(int pos, int velocity);
} // namespace auton
} // namespace tilter

#endif /* end of include guard: TILTER_HPP */
