#include "main.h"
#include "custom/selection.hpp"
#include "display/lvgl.h"
#include <stdio.h>
#include <algorithm>
#include <string>

namespace selection{
  std::string btns[5][4] ={ {"LR ","SR ","LB ","SB "},
  {"LR ","SR ","LB ","SB "},
  {"LR ","SR ","LB" ,"SB "},
  {"LR ","SR ","LB" ,"SB "},
  {"LR ","SR ","LB" ,"SB "}
};
lv_style_t relStyle; //relesed style
lv_style_t preStyle; //pressed style


void isPressed(_lv_obj_t *pressedBtn, _lv_obj_t *Btn){
  if (pressedBtn == Btn)
  {

  }
  else{
    lv_btn_set_state(Btn, LV_BTN_STATE_REL);
  }
}



static lv_res_t btn_click_action(lv_obj_t * btn)
{
    uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0)
    {
        // char buffer[100];

	 std::cout << "loop iteration" << std::endl;
    }

    return LV_RES_OK;
}


void btnConfig(lv_obj_t*btn,  int row, int col){
  lv_obj_t *label;
  int x = 465 / 4 * col;
  int y = 240 / 5 * row;
  lv_obj_set_pos(btn, x,y );
  lv_obj_set_size(btn, 465 / 4, 240 / 5);
  // lv_btn_set_toggle(btn, true);
  label = lv_label_create(btn, NULL);
  lv_label_set_text(label, btns[row][col].c_str());
lv_btn_set_style(btn, LV_BTN_STYLE_REL, &relStyle); //set the relesed style
lv_btn_set_style(btn, LV_BTN_STYLE_PR, &preStyle);
lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  // lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, checkPress);
  // lv_btn_set_state(btn, LV_BTN_STATE_REL);
  std::cout << "creating button " << btns[row][col].c_str() << std::endl;
}

void btnToggled(lv_obj_t * btn, bool toggled)
{
    if(toggled != (lv_btn_get_state(btn) )) lv_btn_toggle(btn);
}

lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn2 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn3 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn4 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn5 = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *btn6 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn7 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn8 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn9 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn10 = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *btn11 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn12 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn13 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn14 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn15 = lv_btn_create(lv_scr_act(), NULL);

lv_obj_t *btn16 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn17 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn18 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn19 = lv_btn_create(lv_scr_act(), NULL);
lv_obj_t *btn20 = lv_btn_create(lv_scr_act(), NULL);


void btnCreate(){
  // for (int row = 0; row < 5; row++) {
  //   for (int col = 0; col < 4; col++ ) {
  //         lv_obj_t* btn = lv_btn_create(lv_scr_act(), NULL);
  //         btnConfig(btn ,row, col);
  //
  //   }
  //
  // }
  lv_style_copy(&relStyle, &lv_style_plain);
   relStyle.body.main_color = LV_COLOR_MAKE(0, 255, 25);
   relStyle.body.radius = 3;
   relStyle.text.color = LV_COLOR_MAKE(150, 5,125);

   lv_style_copy(&preStyle, &lv_style_plain);
   preStyle.body.main_color = LV_COLOR_MAKE(255, 0, 0);
   preStyle.body.radius = 3;
   preStyle.text.color = LV_COLOR_MAKE(0, 164, 255);


  btnConfig(btn1,0,0);
  btnConfig(btn2,1,0);
  btnConfig(btn3,2,0);
  btnConfig(btn4,3,0);
  btnConfig(btn5,4,0);

  btnConfig(btn6,0,1);
  btnConfig(btn7,1,1);
  btnConfig(btn8,2,1);
  btnConfig(btn9,3,1);
  btnConfig(btn10,4,1);

  btnConfig(btn11,0,2);
  btnConfig(btn12,1,2);
  btnConfig(btn13,2,2);
  btnConfig(btn14,3,2);
  btnConfig(btn15,4,2);

  btnConfig(btn16,0,3);
  btnConfig(btn17,1,3);
  btnConfig(btn18,2,3);
  btnConfig(btn19,3,3);
  btnConfig(btn20,4,3);

}


void btnChecker(){
  // pros::delay(20);
  btnToggled(btn1, true);
  btnToggled(btn2, false);
  btnToggled(btn3, false);
  btnToggled(btn4, false);
  btnToggled(btn5, false);
std::cout << "yeet" << std::endl;
}


void clickBtn(){
// std::cout << "running" << std::endl;

}

void guiTask(void *param) {
  while(true) {
    std::uint32_t start = pros::millis();
    pros::Task::delay_until(&start, 10);
    pros::delay(50);
    // std::cout << "loop iteration" << std::endl;
  }
}

void init(){
  clickBtn();
  btnChecker();
  btnCreate();
  std::cout << "starting task" << std::endl;
  pros::Task gui_task(guiTask, (void*)"some param", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task name");

  gui_task.resume();
}
/*
LV_BTN_STYLE_REL - style of the released state. Default: lv_style_btn_rel.

LV_BTN_STYLE_PR - style of the pressed state. Default: lv_style_btn_pr.

LV_BTN_STYLE_TGL_REL - style of the toggled released state. Default: lv_style_btn_tgl_rel.

LV_BTN_STYLE_TGL_PR - style of the toggled pressed state. Default: lv_style_btn_tgl_pr.

LV_BTN_STYLE_INA - style of the inactive state. Default: lv_style_btn_ina.
*/


}
