#include "main.h"
#include "selection.hpp"
namespace selection{
void btnConfig(lv_obj_t*btn,  int row, int col);


lv_style_t relStyle; //relesed style
lv_style_t preStyle; //pressed style
int i = 0;
std::string btns[5][4] ={ {"LR ","SR ","LB ","SB "},
{"LR ","SR ","LB ","SB "},
{"LR ","SR ","LB" ,"SB "},
{"LR ","SR ","LB" ,"SB "},
{"LR ","SR ","LB" ,"SB "}
};

static lv_res_t btn_click_action(lv_obj_t * btn)
{
  std::cout << "button action" << std::endl;

    return LV_RES_OK;
}

void btnCreate(){
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 4; col++ ) {
          lv_obj_t* btn = lv_btn_create(lv_scr_act(), NULL);
          lv_obj_set_free_num(btn, i); //set button is to 0
          i++;
          btnConfig(btn,row,col);
    }

  }
}

void btnConfig(lv_obj_t*btn,  int row, int col){
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
  // lv_btn_set_state(btn, LV_BTN_STATE_TGL_REL);
  // std::cout << "creating button " << btns[row][col].c_str() << std::endl;
}


void btnInit(){
  btnCreate();
}
}
