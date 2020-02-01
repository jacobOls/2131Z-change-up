#include "main.h"
#include "custom/selection.hpp"
#include "display/lvgl.h"
#include <stdio.h>
#include <algorithm>
#include <string>

namespace selection{
  Autons auton = Autons::NONE;
  void clickBtn();
  bool active = true;

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


  std::string btns[5][4] ={ {"LR ","SR ","LB ","SB "},
  {"LR ","SR ","LB ","SB "},
  {"LR ","SR ","LB" ,"SB "},
  {"LR ","SR ","LB" ,"SB "},
  {"LR ","SR ","LB" ,"SB "}
};
lv_style_t relStyle; //relesed style
lv_style_t preStyle; //pressed style



void setCase(){
  auton = Autons::ONE;
  std::cout<<"caseset"<<std::endl;
}

static lv_res_t btn_click_action(lv_obj_t * btn)
{
  uint8_t id = lv_obj_get_free_num(btn);
  active = false;
  if(id == 1){
    if(auton == Autons::ONE){
      auton = Autons::NONE;
    }
    else{
      auton = Autons::ONE;
    }
    id = 0;
  }
  else if (id ==2){
    if(auton == Autons::TWO){
      auton = Autons::NONE;
    }
    else{
      auton = Autons::TWO;
    }      id = 0;
  }
  if(id == 3){
    if(auton == Autons::THREE){
      auton = Autons::NONE;
    }
    else{
      auton = Autons::THREE;
    }
    id = 0;
  }
  else if (id ==4){
    if(auton == Autons::FOUR){
      auton = Autons::NONE;
    }
    else{
      auton = Autons::FOUR;
    }      id = 0;
  }
  else if (id ==5){
    if(auton == Autons::FIVE){
      auton = Autons::NONE;
    }
    else{
      auton = Autons::FIVE;
    }      id = 0;
  }
  std::cout << "button action" << std::endl;
  // setCase();
  // clickBtn();
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
  lv_label_set_text(label, btns[row][col].c_str());
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
  // for (int row = 0; row < 5; row++) {
  //   for (int col = 0; col < 4; col++ ) {
  //         lv_obj_t* btn = lv_btn_create(lv_scr_act(), NULL);
  //         btnConfig(btn ,row, col);
  //
  //   }
  //
  // }
  lv_style_copy(&relStyle, &lv_style_plain);
  relStyle.body.main_color = LV_COLOR_MAKE(0, 0, 255);
  relStyle.body.radius = 3;
  relStyle.text.color = LV_COLOR_MAKE(150, 5,125);




  lv_style_copy(&preStyle, &lv_style_plain);
  preStyle.body.main_color = LV_COLOR_MAKE(0, 255, 0);
  preStyle.body.radius = 3;
  preStyle.text.color = LV_COLOR_MAKE(0, 164, 255);


  btnConfig(btn1,0,0,1); //collumn 1
  btnConfig(btn2,1,0,2);
  btnConfig(btn3,2,0,3);
  btnConfig(btn4,3,0,4);
  btnConfig(btn5,4,0,5);

  btnConfig(btn6,0,1,6); //collumn 2
  btnConfig(btn7,1,1,7);
  btnConfig(btn8,2,1,8);
  btnConfig(btn9,3,1,9);
  btnConfig(btn10,4,1,10);

  btnConfig(btn11,0,2,11); //collumn 3
  btnConfig(btn12,1,2,12);
  btnConfig(btn13,2,2,13);
  btnConfig(btn14,3,2,14);
  btnConfig(btn15,4,2,15);

  btnConfig(btn16,0,3,16); //collumn 4
  btnConfig(btn17,1,3,17);
  btnConfig(btn18,2,3,18);
  btnConfig(btn19,3,3,19);
  btnConfig(btn20,4,3,20);

}


void btnChecker(){
  // btnToggled(btn1, true);
  // btnToggled(btn2, true);
  // btnToggled(btn3, true);
  // btnToggled(btn4, false);
  // btnToggled(btn5, false);
  // std::cout << "yeet" << std::endl;
}


void clickBtn(){
  lv_btn_set_toggle(btn1,false);
  lv_btn_set_toggle(btn2,false);
  lv_btn_set_toggle(btn3,false);
  lv_btn_set_toggle(btn4,false);
  lv_btn_set_toggle(btn5,false);

  lv_btn_set_toggle(btn6,false);
  lv_btn_set_toggle(btn7,false);
  lv_btn_set_toggle(btn8,false);
  lv_btn_set_toggle(btn9,false);
  lv_btn_set_toggle(btn10,false);

  lv_btn_set_toggle(btn11,false);
  lv_btn_set_toggle(btn12,false);
  lv_btn_set_toggle(btn13,false);
  lv_btn_set_toggle(btn14,false);
  lv_btn_set_toggle(btn15,false);

  lv_btn_set_toggle(btn16,false);
  lv_btn_set_toggle(btn17,false);
  lv_btn_set_toggle(btn18,false);
  lv_btn_set_toggle(btn19,false);
  lv_btn_set_toggle(btn20,false);

}


void execute(){
  switch(auton){

    case Autons::ONE:

    break;

    case  Autons::TWO:


    break;

    case Autons::THREE:
    break;

    case  Autons::FOUR:

    break;

    case Autons::FIVE:


    break;

    case  Autons::NONE:
    break;
  }

}

//
void guiTask(void *param) {
  while(true) {
    std::uint32_t start = pros::millis();
    pros::Task::delay_until(&start, 10);
    execute();
    // std::cout << "loop iteration" << std::endl;
    // clickBtn();
  }
}

void init(){
  // btnChecker();
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
