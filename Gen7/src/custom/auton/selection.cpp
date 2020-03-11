#include "custom/auton/selection.hpp"
#include "custom/auton/routines.hpp"
#include "custom/setup/controller.hpp"
#include "display/lvgl.h"
#include "main.h"
#include <algorithm>
#include <stdio.h>
#include <string>

namespace selection {
void clearBtns(lv_obj_t *);

const int BUTTON_COUNT = 20;
volatile bool inAuton = false;

lv_style_t relStyle; // relesed style
lv_style_t preStyle; // pressed style

lv_obj_t **allButtons;

int selectedAuton = -1;

void autonOne() { std::cout << "running auton one" << std::endl; }

void autonTwo() { std::cout << "running auton two" << std::endl; }

void autonThree() { std::cout << "3" << std::endl; }
std::string defaultThing = "foo";
std::string buttonLabels[BUTTON_COUNT] = {
    "LR 7 WIP", // large red
    "blank",    "blank",  "blank",

    "SR 5 WIP", // small red
    "blank",    "blank ", "blank",

    "LB 7 WIP", // large blue
    "blank",    "blank",  "blank",

    "SB 5 WIP", // small blue
    "blank",    "blank ", "blank",

    "('>){",    "blank ", "blank", "blank",
};

// auton function returns void and takes no args
typedef void (*autonFnPtr)(void);

autonFnPtr autonHandlers[BUTTON_COUNT] = {redLargeSeven, // large red
                                          autonOne,       autonOne, autonOne,

                                          redSmallFive, // small red
                                          autonOne,       autonOne, autonOne,

                                          blueSmallFive, // small blue
                                          autonOne,       autonOne, autonOne,

                                          blueLargeSeven, // large blue
                                          autonOne,       autonOne, autonOne,

                                          autonOne, // random
                                          autonOne,       autonOne, autonOne};

static lv_res_t btn_click_action(lv_obj_t *btn) {
  clearBtns(btn);
  lv_btn_set_state(btn, LV_BTN_STATE_PR);
  uint32_t indexPos = lv_obj_get_free_num(btn);
  master.clear();
  master.setText(0, 0, "test");
  selectedAuton = indexPos;
  master.setText(0, 0, buttonLabels[selectedAuton]);

  std::cout << "Toggled button with free_num of [" << indexPos << "] yo"
            << std::endl;
  // std::cout << "Auton selected is " << autonBtnState[id] << std::endl;

  std::cout << "button action" << std::endl;
  // setCase();
  // clearBtns();
  return LV_RES_OK;
}

void btnConfig(lv_obj_t *btn, int row, int col, int id) {
  lv_obj_t *label;
  int x = 465 / 4 * col;
  int y = 240 / 5 * row;
  lv_obj_set_pos(btn, x, y);
  lv_obj_set_size(btn, 465 / 4, 240 / 5);
  lv_btn_set_toggle(btn, true);
  label = lv_label_create(btn, NULL);
  lv_label_set_text(label, buttonLabels[id].c_str());
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_REL,
                   &preStyle); // set the relesed style
  lv_btn_set_style(btn, LV_BTN_STYLE_TGL_PR, &preStyle); // set the pressed
                                                         // style
  lv_btn_set_style(btn, LV_BTN_STYLE_REL, &relStyle); // set the relesed style
  lv_btn_set_style(btn, LV_BTN_STYLE_PR, &preStyle);  // set the pressed style
  lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, btn_click_action);
  lv_obj_set_free_num(btn, id); // set button is to an incrementing amount
}

void btnCreate() {

  allButtons = new lv_obj_t *[BUTTON_COUNT];

  lv_style_copy(&relStyle, &lv_style_plain);
  relStyle.body.main_color = LV_COLOR_MAKE(0, 0, 255);
  relStyle.body.radius = 3;
  relStyle.text.color = LV_COLOR_MAKE(150, 5, 125);

  lv_style_copy(&preStyle, &lv_style_plain);
  preStyle.body.main_color = LV_COLOR_MAKE(0, 255, 0);
  preStyle.body.radius = 3;
  preStyle.text.color = LV_COLOR_MAKE(0, 164, 255);

  int ndx = 0;
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 4; col++) {
      allButtons[ndx] = lv_btn_create(lv_scr_act(), NULL);
      btnConfig(allButtons[ndx], row, col, ndx);
      std::cout << "Created button at pos " << ndx << std::endl;
      ndx++;
    }
  }
}

void clearBtns(lv_obj_t *toggledButton = NULL) {
  std::cout << "clearing  buttonts" << std::endl;
  for (int i = 0; i < BUTTON_COUNT; i++) {
    lv_obj_t *btn = allButtons[i];
    if (btn != toggledButton) {
      lv_btn_set_state(btn, LV_BTN_STATE_REL);
    }
  }
  std::cout << "buttons cleared" << std::endl;
}

void execute() {
  std::cout << "executing" << std::endl;
  autonFnPtr defaultAuton = autonOne;
  defaultThing = "LR 4 Works";
  inAuton = true;

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

  inAuton = false;
}

static int timesCalled = 0;
void init() {
  timesCalled++;
  master.setText(0, 0, defaultThing);
  btnCreate();
  std::cout << "starting task: " << timesCalled << " time" << std::endl;
}

} // namespace selection
