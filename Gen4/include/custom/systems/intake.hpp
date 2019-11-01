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

} // namespace intake

#endif /* end of include guard: INTAKE_HPP */
