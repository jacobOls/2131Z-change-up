#include "main.h"
#include "custom/auton/selection.hpp"
#include "pros/apix.h"
namespace auton{
  lv_obj_t *Btn0_0 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn1_0 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn2_0 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn3_0 = lv_btn_create(lv_scr_act(), NULL);

  lv_obj_t *Btn0_1 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn1_1 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn2_1 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn3_1 = lv_btn_create(lv_scr_act(), NULL);

  lv_obj_t *Btn0_2 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn1_2 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn2_2 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_t *Btn3_2 = lv_btn_create(lv_scr_act(), NULL);

  lv_style_t style_red;
  lv_style_t style_blue;
  lv_style_t style_green;
  lv_style_t style_config;




  std::string screenText[4][4] = {
          {"Left Red", "Mid Red", "Right Red"},
          {"Left Blue", "Mid Blue", " Right Blue"},
          {"Skills 1", "Skills 2", "Skills 3"},
          {"", "", ""},
      };






  void selection(){

  }




}
