#ifndef TILTER_HPP
#define TILTER_HPP
namespace tilter{
  enum class Controllers
  {
    FORWARD,
    BACKWARD,
    RETURN,
    DEINIT,
    TOUP,
    NONE
  };
  void execute(void);
  void init(void);
}


#endif /* end of include guard: TILTER_HPP */
