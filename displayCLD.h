#ifndef _DISPLAY_LCD_H
#define _DISPLAY_LCD_H
#include "Arduino.h"
#include "U8g2lib.h"
#include "Arduino_GFX_Library.h"
typedef enum {
  VietNamese,
  English,
  Null
} language_pointer;

typedef enum {
  escreenStart,
  ewaitingReadsensor,
  echoosetube,
  eprepare,
  escreenResult,
  escreenAverageResult,
  ecalibSensor,
  e_setting,
  e_connect_bluetooth,
  e_language,
  logdata
} e_statuslcd;

class displayCLD {
private:
  /* data */
  Arduino_ESP32SPI *bus;
  Arduino_GFX *display;  //   1


public:
  displayCLD(/* args */);
  ~displayCLD();
  void begin();
  void logoFortebiotech();
  void screen_Start();
  void Choose_tube();
  void screen_Complete();
  void screen_Result();
  void screen_Average_Result();
  void waiting_Readsensor();
  void prepare();
  void screen_Calib();
  void waiting_Calib();
  void screen_Calib_Complete();
  void log_data();
  void set_language();
  void setting();
  void set_connect_bluetooth();
  void loop();
  //  e_statuslcd type_infor = escreenStart;
  e_statuslcd type_infor = e_language;
  int couter = 0;
  int instantStatus[2]; 
  bool changeScreen = true;
  language_pointer language_state = Null;  // 0: Vietnamese 1: English
  uint8_t language = 0;                    // 0:VietNamese 1: English
  uint8_t step = 1;
};
extern displayCLD _displayCLD;
#endif


