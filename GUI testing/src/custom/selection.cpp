#include "main.h"
#include "custom/selection.hpp"
#include "display/lvgl.h"
#include <algorithm>
#include <string>
bool inited = false;
static lv_disp_drv_t disp_dr;
static lv_color_t buf_1[480 * 10];

lv_obj_t *par = lv_btn_create(lv_scr_act(), NULL);
static lv_res_t OnClickPos(_lv_obj_t *pressedBtn);

void btnInit(lv_obj_t *btn){
lv_obj_set_size(btn, 100, 50);	 /*Button size*/
lv_obj_set_pos(btn, 100,100);
}

void selectionInit(){
btnInit(par);



}
