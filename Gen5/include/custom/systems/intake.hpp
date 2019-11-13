#ifndef INTAKE_HPP
#define INTAKE_HPP
namespace intake{

  enum class Controllers
{
  IN,
  OUT,
  SPINR,
  SPINL,
  DEINIT,
  MACRO,
  NONE
};
void init(void);
void execute(void);
}

#endif /* end of include guard: INTAKE_HPP */
