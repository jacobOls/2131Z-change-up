#include "main.h"

lv_obj_t * myButton;
lv_obj_t * myButtonLabel;
lv_obj_t * myLabel;

lv_style_t myButtonStyleREL; //relesed style
lv_style_t myButtonStylePR; //pressed style

static lv_res_t btn_click_action(lv_obj_t * btn)
{
    uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0)
    {
        char buffer[100];
		sprintf(buffer, "button was clicked %i milliseconds from start", pros::millis());
		lv_label_set_text(myLabel, buffer);
    }

    return LV_RES_OK;
}


void btnInit(){
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

	myButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
	lv_obj_set_free_num(myButton, 0); //set button is to 0
	lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
	lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
	lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
	lv_obj_set_size(myButton, 200, 50); //set the button size
	lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid

	myButtonLabel = lv_label_create(myButton, NULL); //create label and puts it inside of the button
	lv_label_set_text(myButtonLabel, "Click the Button"); //sets label text

	myLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
	lv_label_set_text(myLabel, "Button has not been clicked yet"); //sets label text
	lv_obj_align(myLabel, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0); //set the position to center
	std::cout<<"text"<<std::endl;
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
  // btnChecker();
	btnInit();
  std::cout << "starting task" << std::endl;
  pros::Task gui_task(guiTask, (void*)"some param", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "task name");

  gui_task.resume();
}


void initialize()
{
btnInit();
}

void disabled() {}

void competition_initialize() {}

void opcontrol(){
	while(1){

	}
}
