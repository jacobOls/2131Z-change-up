#ifndef SELECTION_HPP
#define SELECTION_HPP

namespace auton {
  namespace selection {
    enum class Positons { FR,
                          BR,
                          BB,
                          FB,
                          NONE };
    enum class Shoots { FAR,
                        MID,
                        NONE };
    enum class Flags { BOTH,
                       TOP,
                       MID,
                       HOLD,
                       NONE };
    enum class Options { PARK,
                         NPARK,
                         NONE };

    void screenInit();
    void execute();
  } // namespace selection
} // namespace auton

#endif /* end of include guard: SELECTION_HPP */
