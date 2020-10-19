#include "custom/auton/selection.hpp"
#include "custom/auton/routines.hpp"
#include "custom/settup/controller.hpp"
#include "display/lvgl.h"
#include "main.h"

namespace selection {
void clearBtns(lv_obj_t *);

const int BUTTON_COUNT = 20;
// volatile bool inAuton = false;

lv_style_t relStyle; // relesed style
lv_style_t preStyle; // pressed style

lv_obj_t **allButtons;

int selectedAuton = -1;

void autonOne() { std::cout << "running auton one" << std::endl; }

void autonTwo() { std::cout << "running auton two" << std::endl; }

void autonThree() { std::cout << "3" << std::endl; }
std::string buttonLabels[BUTTON_COUNT] = {
    "Home Row", // right red, left blue
    "Two Towers",  "One tower ",  "nothing ",

    "Home Row", // left red, right blue
    "Two Towers ", "One Tower  ", "Nothing ",

    "ඞ ", // combo autons
    "ඞ ",          "ඞ ",          "ඞ ",

    "test ", // too many rows
    "ඞ ",          "ඞ  ",         "ඞ ",

    "}(*)", // miscellaneous      "skills ",    "skills",   "also skills",
};
std::string defaultThing = "default";

// auton function returns void and takes no args
typedef void (*autonFnPtr)(void);

autonFnPtr autonHandlers[BUTTON_COUNT] = {auton::redAuton, // tbd
                                          auton::twoTowers,
                                          auton::oneTower,
                                          autonOne,

                                          auton::blueHome, // tbd
                                          autonOne,
                                          autonOne,
                                          autonOne,

                                          autonOne, // tbd
                                          autonOne,
                                          autonOne,
                                          autonOne,

                                          auton::testFunctions, // tbd
                                          autonOne,
                                          autonOne,
                                          autonOne,

                                          auton::skills, // tbd
                                          auton::skills,
                                          auton::skills,
                                          auton::skills};

static lv_res_t btn_click_action(lv_obj_t *btn) {
  clearBtns(btn);
  lv_btn_set_state(btn, LV_BTN_STATE_PR);
  uint32_t indexPos = lv_obj_get_free_num(btn);
  selectedAuton = indexPos;

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
  autonFnPtr defaultAuton = auton::twoTowers;
  defaultThing = "Things work and not";
  // inAuton = true;

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

  // inAuton = false;
}

static int timesCalled = 0;
void init() {
  timesCalled++;
  btnCreate();
  std::cout << "starting task: " << timesCalled << " time" << std::endl;
}

} // namespace selection
