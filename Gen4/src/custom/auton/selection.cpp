#include "custom/auton/selection.hpp"
#include "display/lvgl.h"
#include "custom/setup/controller.hpp"
#include "custom/auton/routines.hpp"
#include "custom/systems/lift.hpp"
#include "custom/systems/intake.hpp"
#include "custom/systems/tilter.hpp"
#include "custom/systems/drive.hpp"
#include "custom/setup/motors.hpp"
#include <algorithm>
#include <string>
namespace auton
{
  /*forward defs*/
  void StyleInit();
  void BtnInit(lv_obj_t *btn, lv_style_t *sty, int row, int col);
  void BtnShow();

  std::string RoutsToString(int one, int two);
  void ControllerScreen();
  void testBtnPos(_lv_obj_t *pressedBtn, _lv_obj_t *Btn, Positons Positon);
  void testBtnSta(_lv_obj_t *pressedBtn, _lv_obj_t *Btn, Stacks Stack);
  void testBtnOpt(_lv_obj_t *pressedBtn, _lv_obj_t *Btn, Options Option);

  static lv_res_t OnClickPos(_lv_obj_t *pressedBtn);
  static lv_res_t OnClickSta(_lv_obj_t *pressedBtn);
  static lv_res_t OnClickOpt(_lv_obj_t *pressedBtn);

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
  lv_style_t style_config;
  // lv_style_t style_btn;

  Positons positon = Positons::FRONTRED;
  Stacks stack = Stacks::NONE;
  Options option = Options::NONE;

  std::string screenText[4][3] = {
    {"Front Red", "!", "!"},
    {"Back Red", "!", "!"},
    {"Back Blue", "!", "!"},
    {"Front Blue", "!", "!"},
  };
  void execute()
  {
    switch (positon)
    {
      case Positons::FRONTRED:
      red5();
      break;

      case Positons::BACKRED:
      red2();
      break;

      case Positons::BACKBLUE:
      blue2();
      break;

      case Positons::FRONTBLUE:
      blue5();
      break;

      case Positons::NONE:
      break;
    }
  }
  void screenInit()
  {
    StyleInit();

    BtnInit(Btn0_0, &style_red, 0, 0);
    BtnInit(Btn1_0, &style_red, 1, 0);
    BtnInit(Btn2_0, &style_blue, 2, 0);
    BtnInit(Btn3_0, &style_blue, 3, 0);
    lv_btn_set_action(Btn0_0, LV_BTN_ACTION_CLICK, OnClickPos);
    lv_btn_set_action(Btn1_0, LV_BTN_ACTION_CLICK, OnClickPos);
    lv_btn_set_action(Btn2_0, LV_BTN_ACTION_CLICK, OnClickPos);
    lv_btn_set_action(Btn3_0, LV_BTN_ACTION_CLICK, OnClickPos);

    BtnInit(Btn0_1, &style_config, 0, 1);
    BtnInit(Btn0_2, &style_config, 0, 2);
    lv_btn_set_action(Btn0_1, LV_BTN_ACTION_CLICK, OnClickSta);
    lv_btn_set_action(Btn0_2, LV_BTN_ACTION_CLICK, OnClickSta);

    BtnInit(Btn1_1, &style_config, 1, 1);
    BtnInit(Btn2_1, &style_config, 2, 1);

    BtnInit(Btn3_1, &style_config, 3, 1);
    lv_btn_set_action(Btn3_1, LV_BTN_ACTION_CLICK, OnClickOpt);

    BtnInit(Btn1_2, &style_config, 1, 2);
    BtnInit(Btn2_2, &style_config, 2, 2);
    BtnInit(Btn3_2, &style_config, 3, 2);

    BtnShow();
    std::cout << "pos: " << static_cast<int>(positon) << " sta: " << static_cast<int>(stack) << " fla: "
    << " opt: " << static_cast<int>(option) << std::endl;
  }
  void StyleInit()
  {
    lv_style_copy(&style_red, &lv_style_plain);
    style_red.text.color = LV_COLOR_HEX(0xFF0000);

    lv_style_copy(&style_blue, &lv_style_plain);
    style_blue.text.color = LV_COLOR_HEX(0x0000FF);

    lv_style_copy(&style_config, &lv_style_plain);
    style_config.text.color = LV_COLOR_HEX(0x00FF00);

    // lv_style_copy(&style_btn, &lv_style_plain);
  }
  void BtnInit(lv_obj_t *btn, lv_style_t *sty, int row, int col)
  {
    lv_obj_t *label;
    int x = 465 / 3 * col;
    int y = 240 / 4 * row;
    lv_btn_set_toggle(btn, true);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_size(btn, 465 / 3, 240 / 4);
    // lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, click());

    label = lv_label_create(btn, NULL);
    lv_obj_set_style(label, sty);
    lv_label_set_text(label, screenText[row][col].c_str());

    std::cout << "Btn on row " << row << " and col " << col << " Inited";
    if (sty == &style_red)
    std::cout << "red" << std::endl;
    else
    std::cout << "blue" << std::endl;
  }
  std::string RoutsToString(int one, int two)
  {
    return screenText[one][two];
  }

  void ControllerScreen()
  {
    master.setText(0, 0, "");
  }

  void testBtnPos(_lv_obj_t *pressedBtn, _lv_obj_t *Btn, Positons Positon)
  {
    if (pressedBtn == Btn)
    {
      positon = Positon;
    }
    else
    {
      lv_btn_set_state(Btn, LV_BTN_STATE_REL);
    }
  }
  void testBtnSta(_lv_obj_t *pressedBtn, _lv_obj_t *Btn, Stacks Stack)
  {
    if (pressedBtn == Btn)
    {
      stack = Stack;
    }
    else
    {
      lv_btn_set_state(Btn, LV_BTN_STATE_REL);
    }
  }

  void testBtnOpt(_lv_obj_t *pressedBtn, _lv_obj_t *Btn, Options Option)
  {
    if (pressedBtn == Btn)
    {
      switch (option)
      {
        case Options::SKILLS:
        option = Options::NOTSKILLS;
        break;
        case Options::NOTSKILLS:
        option = Options::SKILLS;
        break;
        case Options::NONE:
        option = Options::SKILLS;
        break;
      }
    }
    else
    {
      lv_btn_set_state(Btn, LV_BTN_STATE_REL);
    }
  }
  static lv_res_t OnClickPos(_lv_obj_t *pressedBtn)
  {
    testBtnPos(pressedBtn, Btn0_0, Positons::FRONTRED);
    testBtnPos(pressedBtn, Btn1_0, Positons::BACKRED);
    testBtnPos(pressedBtn, Btn2_0, Positons::BACKBLUE);
    testBtnPos(pressedBtn, Btn3_0, Positons::FRONTBLUE);
    ControllerScreen();
    std::cout << "pos: " << static_cast<int>(positon) << " sta: " << static_cast<int>(stack) << " fla: "
    << " opt: " << static_cast<int>(option) << std::endl;
    return LV_RES_OK;
  }
  static lv_res_t OnClickSta(_lv_obj_t *pressedBtn)
  {
    testBtnSta(pressedBtn, Btn0_1, Stacks::LEFT);
    testBtnSta(pressedBtn, Btn0_2, Stacks::RIGHT);
    ControllerScreen();
    std::cout << "pos: " << static_cast<int>(positon) << " sta: " << static_cast<int>(stack) << " fla: "
    << " opt: " << static_cast<int>(option) << std::endl;
    return LV_RES_OK;
  }

  static lv_res_t OnClickOpt(_lv_obj_t *pressedBtn)
  {
    testBtnOpt(pressedBtn, Btn3_1, Options::SKILLS);
    ControllerScreen();
    std::cout << "pos: " << static_cast<int>(positon) << " sta: " << static_cast<int>(stack) << " fla: "
    << " opt: " << static_cast<int>(option) << std::endl;
    return LV_RES_OK;
  }

  void BtnShow()
  {
    switch (positon)
    {
      case Positons::FRONTRED:
      lv_btn_set_state(Btn0_0, LV_BTN_STATE_TGL_PR); //fr
      break;
      case Positons::BACKRED:
      lv_btn_set_state(Btn1_0, LV_BTN_STATE_TGL_PR); //br
      break;
      case Positons::BACKBLUE:
      lv_btn_set_state(Btn2_0, LV_BTN_STATE_TGL_PR); //bb
      break;
      case Positons::FRONTBLUE:
      lv_btn_set_state(Btn3_0, LV_BTN_STATE_TGL_PR); //fb
      break;

      case Positons::NONE:
      break;
    };
    switch (stack)
    {
      case Stacks::LEFT:
      lv_btn_set_state(Btn0_2, LV_BTN_STATE_TGL_PR); //far
      break;
      case Stacks::RIGHT:
      lv_btn_set_state(Btn0_1, LV_BTN_STATE_TGL_PR); //mid
      break;

      case Stacks::NONE:
      break;
    }

    switch (option)
    {
      case Options::SKILLS:
      lv_btn_set_state(Btn3_1, LV_BTN_STATE_TGL_PR); //skills
      break;
      case Options::NOTSKILLS:
      break;

      case Options::NONE:
      break;
    }
  }

  bool inAuton = false;
  void set_auton(bool b)
  {
    inAuton = b;
  }
  void Task(void *why)
  {
    std::uint32_t test = pros::millis(); //init delay
    int beg = pros::millis();
    while (1)
    {
      if (inAuton)
      {
        // drive::auton::ramping();
        intake::execute();
        lift::execute();
        tilter::execute();
      }
      std::cout << "T: "<< (pros::millis()-beg)/5 <<" BLv: " << drive::left_back.get_actual_velocity() << std::endl;
      pros::Task::delay_until(&test, 5); //delay for 5 millis exact
    }
  }

} // namespace auton
