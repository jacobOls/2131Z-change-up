#ifndef PID_HPP
#define PID_HPP
namespace auton {
void unityStrafe(int distance, bool waity = false);
// void unityLeft(int distance, bool waity = false);
void unity2(void *param);
void unityStraight(int distance, bool waity);
void unityBack(int distance, bool waity);
void unityTurn(int degrees, bool waity = false);
void unityStop();

} // namespace auton

#endif /* end of include guard: PID_HPP */
