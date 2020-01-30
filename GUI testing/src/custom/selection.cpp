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
lv_style_t myButtonStyleREL; //relesed style
lv_style_t myButtonStylePR; //pressed style


void isPressed(_lv_obj_t *pressedBtn, _lv_obj_t *Btn){
  if (pressedBtn == Btn)
  {

  }
  else{
    lv_btn_set_state(Btn, LV_BTN_STATE_REL);
  }
}



static lv_res_t checkPress(_lv_obj_t *pressedBtn){
  // isPressed(pressedBtn,btn1);
  std::cout << "running checkPress" <<  std::endl;
  lv_btn_set_state(pressedBtn, LV_BTN_STATE_TGL_PR); //fa
  return LV_RES_OK;
}


void btnLocNSize(lv_obj_t*btn,  int row, int col){
  lv_obj_t *label;
  int x = 465 / 4 * col;
  int y = 240 / 5 * row;
  lv_obj_set_pos(btn, x,y );
  lv_obj_set_size(btn, 465 / 4, 240 / 5);
  lv_btn_set_toggle(btn, true);
  label = lv_label_create(btn, NULL);
  lv_label_set_text(label, btns[row][col].c_str());
  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
   lv_btn_set_style(btn, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
  lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, checkPress);
  // lv_btn_set_state(btn, LV_BTN_STATE_REL);
  std::cout << "creating button " << btns[row][col].c_str() << std::endl;
}




void btnCreate(){
  // for (int row = 0; row < 5; row++) {
  //   for (int col = 0; col < 4; col++ ) {
  //         lv_obj_t* btn = lv_btn_create(lv_scr_act(), NULL);
  //         btnLocNSize(btn ,row, col);
  //
  //   }
  //
  // }
  lv_style_copy(&myButtonStyleREL, &lv_style_plain);
   myButtonStyleREL.body.main_color = LV_COLOR_MAKE(150, 0, 0);
   myButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0, 0, 150);
   myButtonStyleREL.body.radius = 0;
   myButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

   lv_style_copy(&myButtonStylePR, &lv_style_plain);
   myButtonStylePR.body.main_color = LV_COLOR_MAKE(255, 0, 0);
   myButtonStylePR.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
   myButtonStylePR.body.radius = 0;
   myButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

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

  btnLocNSize(btn1,0,0);
  btnLocNSize(btn2,1,0);
  btnLocNSize(btn3,2,0);
  btnLocNSize(btn4,3,0);
  btnLocNSize(btn5,4,0);

  btnLocNSize(btn6,0,1);
  btnLocNSize(btn7,1,1);
  btnLocNSize(btn8,2,1);
  btnLocNSize(btn9,3,1);
  btnLocNSize(btn10,4,1);

  btnLocNSize(btn11,0,2);
  btnLocNSize(btn12,1,2);
  btnLocNSize(btn13,2,2);
  btnLocNSize(btn14,3,2);
  btnLocNSize(btn15,4,2);

  btnLocNSize(btn16,0,3);
  btnLocNSize(btn17,1,3);
  btnLocNSize(btn18,2,3);
  btnLocNSize(btn19,3,3);
  btnLocNSize(btn20,4,3);

}




// void guiTask(void *param) {
//   while(true) {
//     // std::uint32_t start = pros::millis();
//     // pros::Task::delay_until(&start, 10);
//     pros::delay(10);
//     // std::cout << "loop iteration" << std::endl;
//   }
// }

void init(){
  btnCreate();
  // std::cout << "starting task" << std::endl;
  // pros::Task gui_task(guiTask, (void*)"some param", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task name");

  // gui_task.resume();
}
/*
LV_BTN_STYLE_REL - style of the released state. Default: lv_style_btn_rel.

LV_BTN_STYLE_PR - style of the pressed state. Default: lv_style_btn_pr.

LV_BTN_STYLE_TGL_REL - style of the toggled released state. Default: lv_style_btn_tgl_rel.

LV_BTN_STYLE_TGL_PR - style of the toggled pressed state. Default: lv_style_btn_tgl_pr.

LV_BTN_STYLE_INA - style of the inactive state. Default: lv_style_btn_ina.
*/


}













// static lv_disp_drv_t disp_dr;
// static lv_color_t buf_1[480 * 10];
//
// lv_obj_t *par = lv_btn_create(lv_scr_act(), NULL);
// static lv_res_t OnClickPos(_lv_obj_t *pressedBtn);
//
// void btnInit(lv_obj_t *btn){
// lv_obj_set_size(btn, 100, 50);	 /*Button size*/
// lv_obj_set_pos(btn, 100,100);
// }
//
// void selectionInit(){
// btnInit(par);
//
//
//
// }
