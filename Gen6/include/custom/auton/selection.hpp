#ifndef SELECTION_HPP
#define SELECTION_HPP

namespace auton{
enum class Positons{
  FRONTRED,
  BACKRED,
  BACKBLUE,
  FRONTBLUE,
  NONE
};
enum class Stacks{
  LEFT,
  RIGHT,
  NONE
};

enum class Options{
  SKILLS,
  NOTSKILLS,
  NONE
};

void screenInit();
void execute();
void set_auton(bool b);
void Task(void *why);
} // namespace auton
#endif /* end of include guard: SELECTION_HPP */
