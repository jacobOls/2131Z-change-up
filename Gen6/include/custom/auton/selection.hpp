#ifndef SELECTION_HPP
#define SELECTION_HPP
#include "display/lvgl.h"
#include "main.h"
namespace selection{
void init();
extern pros::Task *gui_task;
extern bool inAuton;
}

#endif /* end of include guard: SELECTION_HPP */
