#include "main.h"
#include "custom/auton/selection.hpp"
#include "display/lvgl.h"
#include "custom/auton/routines.hpp"
#include <stdio.h>
#include <algorithm>
#include <string>

namespace selection{
  void clearBtns(lv_obj_t*);

  const int BUTTON_COUNT = 20;
  bool inAuton = false;
//
//   std::string btns[5][4] ={
//    {"LR ","SR ","LB ","SB "},
//   {"LR ","SR ","LB ","SB "},
//   {"LR ","SR ","LB" ,"SB "},
//   {"LR ","SR ","LB" ,"SB "},
//   {"LR ","SR ","LB" ,"SB "}
// };
lv_style_t relStyle; //relesed style
lv_style_t preStyle; //pressed style

lv_obj_t ** allButtons;

int selectedAuton = -1;

void autonOne() {
  std::cout <<  "running auton one" << std::endl;
}

void autonTwo() {
  std::cout <<  "running auton two" << std::endl;
}

void autonThree(){
  std::cout << "3" << std::endl;
}
std::string buttonLabels[BUTTON_COUNT] = {
  "LR",  // large red
  "LR",
  "LR ",
  "LR",

  "SR  5",  // small red
  "SR",
  "SR ",
  "SR",

  "LB",  // large blue
  "LB",
  "LB ",
  "LB",

  "SB  5",  // small blue
  "SB",
  "SB ",
  "SB",

  "nothhing",
  "deploy only ",
  "1 point",
  "skills",
};

// auton function returns void and takes no args
typedef  void (*autonFnPtr)(void);


// std::string autonBtnState[BUTTON_COUNT] = {
//   "FRONT_RED",  // 1
//   "FRONT_BLUE", // 2
//
// };

autonFnPtr autonHandlers[BUTTON_COUNT] = {
  autonOne, //large red
  autonTwo,
  autonThree,
 autonOne,

auton:: redSmall, //small red
auton:: redSmall,
auton:: redSmall,
auton:: redSmall,

auton:: redSmall, //large blue
auton:: redSmall,
auton:: redSmall,
auton:: redSmall,

auton::blueSmall, //small blue
auton:: blueSmall,
auton:: blueSmall,
auton:: blueSmall

};



static lv_res_t btn_click_action(lv_obj_t * btn)
{
  clearBtns(btn);
  lv_btn_set_state(btn, LV_BTN_STATE_PR);
  uint32_t indexPos = lv_obj_get_free_num(btn);

  selectedAuton = indexPos;

  std::cout << "Toggled button with free_num of [" << indexPos << "] yo" <<  std::endl;
  // std::cout << "Auton selected is " << autonBtnState[id] << std::endl;

std::cout << "button action" << std::endl;
// setCase();
// clearBtns();
return LV_RES_OK;
}


void btnConfig(lv_obj_t*btn,  int row, int col, int id){
  lv_obj_t *label;
  int x = 465 / 4 * col;
  int y = 240 / 5 * row;
  lv_obj_set_pos(btn, x,y );
  lv_obj_set_size(btn, 465 / 4, 240 / 5);
  lv_btn_set_toggle(btn, true);
  label = lv_label_create(btn, NULL);
  lv_label_set_text(label, buttonLabels[id].c_str());
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL, &preStyle); //set the relesed style
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &preStyle); //set the pressed style
  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &relStyle); //set the relesed style
  lv_btn_set_style(btn, LV_BTN_STYLE_PR, &preStyle); //set the pressed style
  lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, btn_click_action);
  lv_obj_set_free_num(btn, id); //set button is to 0
  // lv_btn_set_state(btn, LV_BTN_STATE_TGL_REL);
  // std::cout << "creating button " << btns[row][col].c_str() << std::endl;
}

void btnToggled(lv_obj_t * btn, bool toggled)
{
  if(toggled != (lv_btn_get_state(btn) )) lv_btn_toggle(btn);
}




void btnCreate(){

  allButtons = new lv_obj_t*[BUTTON_COUNT];

  lv_style_copy(&relStyle, &lv_style_plain);
  relStyle.body.main_color = LV_COLOR_MAKE(0, 0, 255);
  relStyle.body.radius = 3;
  relStyle.text.color = LV_COLOR_MAKE(150, 5,125);




  lv_style_copy(&preStyle, &lv_style_plain);
  preStyle.body.main_color = LV_COLOR_MAKE(0, 255, 0);
  preStyle.body.radius = 3;
  preStyle.text.color = LV_COLOR_MAKE(0, 164, 255);

int ndx = 0;
for (int row = 0; row < 5; row++) {
  for (int col = 0; col < 4; col++) {
    allButtons[ndx] =  lv_btn_create(lv_scr_act(), NULL);
    btnConfig(allButtons[ndx], row, col, ndx);
     std::cout << "Created button at pos " << ndx << std::endl;
     ndx++;
  }
}


}

void clearBtns(lv_obj_t * toggledButton = NULL){
  std::cout << "clearing  buttonts" << std::endl;
  for (int i = 0; i < BUTTON_COUNT; i++) {
     lv_obj_t * btn = allButtons[i];
     if (btn != toggledButton) {
       lv_btn_set_state(btn, LV_BTN_STATE_REL);
     }

  }
    std::cout << "buttons cleared" << std::endl;
}


void execute(){
autonFnPtr defaultAuton =auton:: redSmall;

 if (selectedAuton == -1) {
   defaultAuton();
   return;
 }

 autonFnPtr autonToRun = autonHandlers[selectedAuton];
 if (autonToRun != NULL) {
   autonToRun();
   return;
 } else {
   defaultAuton();
 }

}

//
void guiTask(void *param) {
  while(inAuton == true) {
    std::uint32_t start = pros::millis();
    pros::Task::delay_until(&start, 10);
    execute();
    // std::cout << "loop iteration" << std::endl;
    // clearBtns();
  }
}

void init(){
  // btnChecker();
  btnCreate();
  std::cout << "starting task" << std::endl;

  pros::Task gui_task_class(guiTask, (void*)"some param", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task name");

  pros::Task *gui_task_ptr;
  gui_task_ptr = &gui_task_class;

  gui_task_class.suspend();
}

}
