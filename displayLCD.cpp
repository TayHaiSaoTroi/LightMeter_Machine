#include "displayCLD.h"
#include <U8g2lib.h>
#include "displayresources.h"
#include "define.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "sensor.h"
// #include "update_firmware.h"
#include "Bluetooth.h"
#define Forte_Green 0x25F8
#define VIOLET 0xA81F
String measure_value = "";


bool butt = 1;  // 0: blue, 1: green


displayCLD::displayCLD(/* args */) {
  this->bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
  this->display = new Arduino_ILI9341(this->bus, TFT_RESET);
}

displayCLD::~displayCLD() {
}

void displayCLD::begin() {
  this->display->begin();
  this->display->fillScreen(BLACK);
  this->display->setRotation(1);
  this->display->setUTF8Print(true);
}

void displayCLD::logoFortebiotech() {
  this->display->fillScreen(BLACK);
  this->display->fillTriangle(80, 60, 132, 30, 132, 90, this->display->color565(16, 55, 50));
  this->display->fillTriangle(130, 100, 78, 70, 78, 130, this->display->color565(16, 55, 50));
  this->display->fillTriangle(88, 140, 132, 110, 132, 170, this->display->color565(16, 45, 20));
  this->display->fillTriangle(142, 30, 252, 10, 142, 68, this->display->color565(10, 30, 35));
  this->display->fillTriangle(142, 140, 142, 170, 192, 130, this->display->color565(16, 65, 30));
  this->display->setFont(u8g2_font_unifont_t_vietnamese1);
  this->display->setTextSize(2);
  this->display->setTextColor(this->display->color565(16, 55, 70));
  this->display->setCursor(150, 90);
  this->display->print("FORTE");
  this->display->setCursor(150, 120);
  this->display->print("BIOTECH");
  this->display->setFont(u8g2_font_helvB08_tf);
  this->display->setTextColor(Forte_Green);
  this->display->setTextSize(1);
  this->display->setCursor(80, 190);
  this->display->print("TEST   PRAWNS   WITH   RAPID");
  this->display->setCursor(100, 220);
  this->display->print("PROFIT   NO   LIMIT");
  this->display->setCursor(15, 230);
  this->display->print(FirmwareVer);
  this->display->setFont(u8g2_font_unifont_t_vietnamese1);
  delay(3000);
  dbg_display("logo thanh cong");
  Serial.println("ForteBiotech");
}

void displayCLD::screen_Start() {
  if (language == 0) {
    ip = WiFi.localIP().toString().c_str();  // Taking ip address
    this->display->fillScreen(BLACK);
    this->display->setTextSize(1);
    this->display->fillRect(108, 0, 108, 20, Forte_Green);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setCursor(110, 15);
    this->display->setTextColor(BLACK);
    this->display->println("FORTE BIOTECH");
    this->display->drawBitmap(18, 5, logoFBT, 35, 34, Forte_Green);
    this->display->drawBitmap(275, 200, shrimp, 35, 29, Forte_Green);
    this->display->setTextSize(2);
    this->display->setCursor(80, 100);
    this->display->drawCircle(42, 110, 25, GREEN);
    this->display->fillCircle(42, 110, 20, GREEN);
    this->display->setTextColor(GREEN);
    this->display->println("Nhấn nút xanh");
    this->display->setCursor(100, 140);
    this->display->print("để bắt đầu");
    this->display->setTextSize(1);
    this->display->setCursor(20, 230);
    this->display->print(ip);
    Serial.println("Nguyen Minh Tan");
    Serial.println(ip);
    this->display->setCursor(20, 210);
    this->display->print("ID " + id);
  } else

  {
    ip = WiFi.localIP().toString().c_str();  // Taking ip address
    this->display->fillScreen(BLACK);
    this->display->setTextSize(1);
    this->display->fillRect(108, 0, 108, 20, Forte_Green);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setCursor(110, 15);
    this->display->setTextColor(BLACK);
    this->display->println("FORTE BIOTECH");
    this->display->drawBitmap(18, 10, logoFBT, 35, 34, Forte_Green);
    this->display->drawBitmap(275, 200, shrimp, 35, 29, Forte_Green);
    this->display->setTextSize(2);
    this->display->setCursor(80, 100);
    this->display->drawCircle(42, 110, 25, GREEN);
    this->display->fillCircle(42, 110, 20, GREEN);
    this->display->setTextColor(GREEN);
    this->display->println("Press Green");
    this->display->setCursor(100, 140);
    this->display->print("To Start");
    this->display->setTextSize(1);
    this->display->setCursor(20, 230);
    this->display->print(ip);
    Serial.println("Nguyen Minh Tan");
    Serial.println(ip);
    this->display->setCursor(20, 210);
    this->display->print("ID " + id);
  }
  // dbg_display("Nhan nut do de bat dau");
  //   while (digitalRead(blueButton)) {} //NOTE: sua lai nut nhan
}
void displayCLD::Choose_tube() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    // this->display->drawRect(0, 0, 320, 240, BLUE);
    this->display->setTextColor(WHITE);
    this->display->setCursor(55, 30);
    this->display->print("Chọn ống để đo ");
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(60, 60);
    this->display->print("+Chứng dương ");
    this->display->setCursor(60, 90);
    this->display->print("+Chứng âm");
    this->display->setCursor(60, 120);
    this->display->print("+EHP");
    this->display->setCursor(60, 150);
    this->display->print("+EMS ");
    this->display->setCursor(60, 180);
    this->display->print("+Đốm trắng");

    switch (step) {
      case 1:
        {
          this->display->fillTriangle(47, 50, 18, 40, 18, 60, RED);
          measure_value = "Chứng dương";
          break;
        }
      case 2:
        {
          this->display->fillTriangle(47, 80, 18, 70, 18, 90, RED);
          measure_value = "Chứng âm";
          break;
        }
      case 3:
        {
          this->display->fillTriangle(47, 110, 18, 100, 18, 120, RED);
          measure_value = "EHP";
          break;
        }
      case 4:
        {
          this->display->fillTriangle(47, 140, 18, 130, 18, 150, RED);
          measure_value = "EMS";
          break;
        }
      case 5:
        {
          this->display->fillTriangle(47, 170, 18, 160, 18, 180, RED);
          measure_value = "Đốm trắng";
          break;
        }
      default:
        break;
    }
    this->display->setTextSize(1);
    this->display->setTextColor(RED);
    this->display->setCursor(18, 210);
    this->display->print("Nút đỏ:chọn ống");
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
    } else {
      this->display->setTextColor(GREEN);
    }
    this->display->setCursor(18, 230);
    this->display->print("Nút xanh:tiếp tục");
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextColor(WHITE);
    this->display->setCursor(60, 30);
    this->display->print("Select tube ");
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(60, 60);
    this->display->print("+Positive");
    this->display->setCursor(60, 90);
    this->display->print("+Negative");
    this->display->setCursor(60, 120);
    this->display->print("+EHP");
    this->display->setCursor(60, 150);
    this->display->print("+EMS ");
    this->display->setCursor(60, 180);
    this->display->print("+WSSV");


    switch (step) {
      case 1:
        {
          this->display->fillTriangle(47, 50, 18, 40, 18, 60, RED);
          measure_value = "Positive";
          break;
        }
      case 2:
        {
          this->display->fillTriangle(47, 80, 18, 70, 18, 90, RED);
          measure_value = "Negative";
          break;
        }
      case 3:
        {
          this->display->fillTriangle(47, 110, 18, 100, 18, 120, RED);
          measure_value = "EHP";
          break;
        }
      case 4:
        {
          this->display->fillTriangle(47, 140, 18, 130, 18, 150, RED);
          measure_value = "EMS";
          break;
        }
      case 5:
        {
          this->display->fillTriangle(47, 170, 18, 160, 18, 180, RED);
          measure_value = "WSSV";
          break;
        }
      default:
        break;
    }

    this->display->setTextSize(1);
    this->display->setTextColor(RED);
    this->display->setCursor(18, 210);
    this->display->print("Press red button to select tube");
    this->display->setCursor(18, 230);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
      this->display->print("Press blue button to continue");
    } else {
      this->display->setTextColor(GREEN);
      this->display->print("Press green button to continue");
    }
  }
}


void displayCLD::waiting_Readsensor() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->drawBitmap(275, 7, logoFBT, 35, 34, Forte_Green);
    this->display->setTextSize(3);
    this->display->setTextColor(RED);
    this->display->setCursor(18, 90);
    this->display->print("ĐANG ĐO");
    this->display->setTextSize(2);
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(18, 150);
    this->display->println("Vui lòng chờ trong");
    this->display->setCursor(85, 180);
    this->display->println("giây lát!!!");
    for (int i = 13; i < 296; ++i) {
      this->display->setCursor(i + 5, 210);
      this->display->print(".");
      delay(20);
    }
    _sensor.flagReadSensor = true;
  } else {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->drawBitmap(275, 7, logoFBT, 35, 34, Forte_Green);
    this->display->setTextSize(3);
    this->display->setTextColor(RED);
    this->display->setCursor(18, 90);
    this->display->print("In progress");
    this->display->setTextSize(2);
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(18, 150);
    this->display->println("Waiting...");
    for (int i = 13; i < 296; ++i) {
      this->display->setCursor(i + 5, 210);
      this->display->print(".");
      delay(20);
    }
    _sensor.flagReadSensor = true;
  }
}

void displayCLD::prepare() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(25, 60);
    this->display->println("Đặt ống vào máy");
    this->display->setCursor(25, 90);
    this->display->print("và đậy nắp");
    // this->display->drawRect(0, 0, 320, 240, Forte_Green);
    // this->display->drawRect(185, 0, 135, 35, Forte_Green);
    this->display->drawRect(30, 140, 272, 80, RED);
    this->display->drawRect(29, 139, 274, 82, RED);
    for (int i = 18; i <= 300; i += 10) {
      static int x1 = 0, y1 = 100, x2 = 10, y2 = 110, y3 = 120;
      this->display->drawLine(x1 + i, y1, x2 + i, y2, PINK);
      this->display->drawLine(x1 + i, y3, x2 + i, y2, PINK);
    }
    this->display->drawCircle(55, 180, 22, RED);
    this->display->fillCircle(55, 180, 17, RED);
    this->display->setTextSize(2);
    this->display->setTextColor(RED);
    this->display->setCursor(90, 175);
    this->display->println("Nút đỏ");
    this->display->setCursor(90, 205);
    this->display->print("để đo lần ");
    this->display->print(this->couter);
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(15, 60);
    this->display->print("Put the tube inside");
    this->display->setCursor(15, 90);
    this->display->print("and close the lid");
    this->display->drawRect(30, 140, 272, 80, RED);
    this->display->drawRect(29, 139, 274, 82, RED);
    for (int i = 18; i <= 310; i += 10) {
      static int x1 = 0, y1 = 100, x2 = 10, y2 = 110, y3 = 120;
      this->display->drawLine(x1 + i, y1, x2 + i, y2, PINK);
      this->display->drawLine(x1 + i, y3, x2 + i, y2, PINK);
    }
    this->display->drawCircle(55, 180, 22, RED);
    this->display->fillCircle(55, 180, 17, RED);
    this->display->setTextSize(2);
    this->display->setTextColor(RED);
    this->display->setCursor(90, 175);
    this->display->println("Press red");
    this->display->setCursor(90, 205);
    this->display->print("to measure #");
    this->display->print(this->couter);
  }
}

void displayCLD::screen_Result() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextColor(YELLOW);
    this->display->setCursor(18, 35);
    this->display->printf("Lần đo %d:", this->couter);
    this->display->setTextSize(7);
    this->display->setTextColor(RED);

    if (_sensor.result_Sensor[0][this->couter - 1] < 10)
      this->display->setCursor(135, 140);
    else if (_sensor.result_Sensor[0][this->couter - 1] < 100)
      this->display->setCursor(110, 140);
    else if (_sensor.result_Sensor[0][this->couter - 1] < 1000)
      this->display->setCursor(85, 140);
    else
      this->display->setCursor(50, 140);

    this->display->println(_sensor.result_Sensor[0][this->couter - 1]);

    this->display->setTextSize(1);
    this->display->setCursor(18, 190);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
    } else {
      this->display->setTextColor(GREEN);
    }
    this->display->println("Nút Xanh: Đo lại");
    this->display->setCursor(18, 210);
    this->display->setTextColor(RED);
    this->display->println("Nút Đỏ: Tiếp tục");
    this->display->setCursor(18, 230);
    this->display->setTextColor(WHITE);
    this->display->println("Nút Trắng: Xem lại kết quả trước");
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setTextColor(YELLOW);
    this->display->setCursor(18, 35);
    this->display->printf("# %d:", this->couter);
    this->display->setTextSize(7);
    this->display->setTextColor(RED);

    if (_sensor.result_Sensor[0][this->couter - 1] < 10)
      this->display->setCursor(135, 140);
    else if (_sensor.result_Sensor[0][this->couter - 1] < 100)
      this->display->setCursor(110, 140);
    else if (_sensor.result_Sensor[0][this->couter - 1] < 1000)
      this->display->setCursor(85, 140);
    else
      this->display->setCursor(50, 140);

    this->display->println(_sensor.result_Sensor[0][this->couter - 1]);

    this->display->setTextSize(1);
    this->display->setCursor(18, 190);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
      this->display->println("Blue: Redo");
    } else {
      this->display->setTextColor(GREEN);
      this->display->println("Green: Redo");
    }
    this->display->setCursor(18, 210);
    this->display->setTextColor(RED);
    this->display->println("Red: Continue");
    this->display->setCursor(18, 230);
    this->display->setTextColor(WHITE);
    this->display->println("White: Check the previous result");
  }
}
String encMeasureValue(const String& str) {
  if (str == "Chứng dương") {
    return "Chung%20duong";
  } else if (str == "Chứng âm") {
    return "Chung%20am";
  } else if (str == "Đốm trắng") {
    return "Dom%20trang";
  } else return str;
}

void displayCLD::log_data() {

  // Google script ID and required credentials
  String GOOGLE_SCRIPT_ID = "1I85TPdAJ1Ghwmz8kIqZ1A6yFHOjA5X95kymyt6jaN_g/edit#gid=0";  // change Gscript ID
  String encodedMeasureValue = encMeasureValue(measure_value);
  String lan_1 = String(_sensor.result_Sensor[0][0]);
  String lan_2 = String(_sensor.result_Sensor[0][1]);
  String lan_3 = String(_sensor.result_Sensor[0][2]);
  String trung_binh = String(_sensor.AverageResult[0]);
  String ID = id;
  //String urlFinal = "https://script.google.com/macros/s/AKfycbymqZg24T27Y9TKGP5zZMGKup7B0EBYgC42xWBCJEKOw06VFG8l1S8Zt0EBr9QzNOJ6Tw/exec?date=2023&lan_1=100&lan_2=200&lan_3=300&trung_binh=250";
  String urlFinal = "https://script.google.com/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + "&lan_1=" + lan_1
                    + "&lan_2=" + lan_2 + "&lan_3=" + lan_3 + "&trung_binh=" + trung_binh + "&measure_value=" + encodedMeasureValue + "&ID=" + ID;
  HTTPClient http;
  http.begin(urlFinal.c_str());
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  int httpCode = http.GET();
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setCursor(20, 120);
    this->display->setTextColor(GREEN);
    this->display->print("Gửi kq thành công!");
    delay(5000);
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setCursor(20, 120);
    this->display->setTextColor(GREEN);
    this->display->print("Completed!");
    delay(5000);
  }
}

void displayCLD::screen_Average_Result() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(WHITE);
    this->display->setCursor(18, 30);
    this->display->print("Ống đo:");
    this->display->setCursor(125, 30);
    this->display->print(measure_value);
    this->display->drawLine(15, 45, 302, 45, Forte_Green);
    this->display->setCursor(80, 80);
    this->display->print("Kết quả đo");
    this->display->setTextColor(RED);  // ong 1
    this->display->setCursor(18, 110);
    this->display->printf("Lần 1:  %d \n\r", _sensor.result_Sensor[0][0]);
    this->display->setCursor(18, 140);
    this->display->printf("Lần 2:  %d \n\r", _sensor.result_Sensor[0][1]);
    this->display->setCursor(18, 170);
    this->display->printf("Lần 3:  %d \n\r", _sensor.result_Sensor[0][2]);
    this->display->setCursor(18, 200);
    this->display->setTextColor(YELLOW);  // ong 1
    this->display->printf("Trung Bình: %d", _sensor.AverageResult[0]);
    this->display->setTextSize(1);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
    } else {
      this->display->setTextColor(GREEN);
    }
    this->display->setCursor(18, 230);
    this->display->print("Nút xanh:Bắt đầu lại ");
    // this->display->setCursor(200, 230);
    // this->display->setTextColor(WHITE);
    // this->display->print("Nút trắng:Gửi");
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setCursor(18, 30);
    this->display->setTextColor(WHITE);
    this->display->print("Tube:");
    this->display->setCursor(125, 30);
    this->display->print(measure_value);
    this->display->drawLine(18, 45, 296, 45, BLUE);
    this->display->setCursor(115, 80);
    this->display->print("Result");
    this->display->setTextColor(RED);  // ong 1
    this->display->setCursor(18, 110);
    this->display->printf("1st:  %d \n\r", _sensor.result_Sensor[0][0]);
    this->display->setCursor(18, 140);
    this->display->printf("2nd:  %d \n\r", _sensor.result_Sensor[0][1]);
    this->display->setCursor(18, 170);
    this->display->printf("3rd:  %d \n\r", _sensor.result_Sensor[0][2]);
    this->display->setCursor(18, 200);
    this->display->setTextColor(YELLOW);  // ong 1
    this->display->printf("Average: %d", _sensor.AverageResult[0]);
    this->display->setTextSize(1);
    this->display->setCursor(18, 230);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);  // ong 1
      this->display->print("Blue: Startover ");
    } else {
      this->display->setTextColor(GREEN);  // ong 1
      this->display->print("Green: Startover ");
    }
  }
}

void displayCLD::screen_Calib() {
  // dbg_display("nhan do calib, nhan xanh ket thuc, nhan trang de format");
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextColor(WHITE);
    this->display->setCursor(30, 35);
    this->display->println("CHẾ ĐỘ CÂN CHỈNH");
    this->display->setCursor(35, 80);
    this->display->print("Mẫu đo ");
    this->display->setTextColor(ORANGE);
    if (_sensor.typecalib == 0) {
      this->display->print("cao nhất");
    } else {
      this->display->print("thấp nhất");
    }
    this->display->setCursor(18, 190);
    this->display->setTextSize(1);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
    } else {
      this->display->setTextColor(GREEN);
    }
    this->display->println("Nút xanh: thoát");
    this->display->setCursor(18, 210);
    this->display->setTextColor(RED);
    this->display->println("Nút Đỏ: cân chỉnh");
    this->display->setCursor(18, 230);
    this->display->setTextColor(WHITE);
    this->display->println("Nút trắng: xoá cân chỉnh");
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setTextColor(WHITE);
    this->display->setCursor(40, 35);
    this->display->println("Calibration mode");
    this->display->setCursor(40, 80);
    this->display->print("Tube type:");
    this->display->setTextColor(ORANGE);
    if (_sensor.typecalib == 0)
      this->display->print("Highest");
    else
      this->display->print("Lowest");

    this->display->setCursor(18, 190);
    this->display->setTextSize(1);
    if (butt == 0) {
      this->display->setTextColor(Forte_Green);
      this->display->println("Blue: Exit");
    } else {
      this->display->setTextColor(GREEN);
      this->display->println("Green: Exit");
    }
    this->display->setCursor(18, 210);
    this->display->setTextColor(RED);
    this->display->println("Red: Calibrate");
    this->display->setCursor(18, 230);
    this->display->setTextColor(WHITE);
    this->display->println("White: Delete calibration");
  }
}
void displayCLD::waiting_Calib() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->drawBitmap(275, 7, logoFBT, 35, 34, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(RED);
    this->display->setCursor(18, 90);
    this->display->print("ĐANG CÂN CHỈNH");
    this->display->setTextSize(2);
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(18, 150);
    this->display->println("Vui lòng chờ trong");
    this->display->setCursor(85, 180);
    this->display->println("giây lát!!!");
  } else {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->drawBitmap(275, 7, logoFBT, 35, 34, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(RED);
    this->display->setCursor(18, 90);
    this->display->print("Calibrating");
    this->display->setTextSize(2);
    this->display->setTextColor(Forte_Green);
    this->display->setCursor(18, 150);
    this->display->println("Waiting...");
  }
}
void displayCLD::screen_Calib_Complete() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextColor(ORANGE);
    this->display->setCursor(35, 35);
    this->display->println("Chế độ cân chỉnh");
    this->display->setTextSize(3);
    this->display->setCursor(45, 130);
    this->display->setTextColor(Forte_Green);
    this->display->println("Thành Công");
    delay(3000);
  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setTextColor(ORANGE);
    this->display->setCursor(35, 35);
    this->display->println("Calibration mode");
    this->display->setTextSize(3);
    this->display->setCursor(45, 130);
    this->display->setTextColor(Forte_Green);
    this->display->println("Successful!");
    delay(3000);
  }
}
void displayCLD::setting() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setCursor(100, 40);
    this->display->setTextColor(YELLOW);
    this->display->print("Cài đặt");
    this->display->drawRect(18, 60, 296, 50, GREEN);
    this->display->setCursor(40, 90);
    this->display->setTextColor(GREEN);
    this->display->print("Cài đặt WIFI");
    this->display->drawRect(18, 120, 296, 50, RED);
    this->display->setCursor(40, 150);
    this->display->setTextColor(RED);
    this->display->print("Ngôn ngữ");
  } else {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setCursor(100, 40);
    this->display->setTextColor(YELLOW);
    this->display->print("Set up");
    this->display->drawRect(18, 60, 296, 50, GREEN);
    this->display->setCursor(40, 90);
    this->display->setTextColor(GREEN);
    this->display->print("WIFI Setup");
    this->display->drawRect(18, 120, 296, 50, RED);
    this->display->setCursor(40, 150);
    this->display->setTextColor(RED);
    this->display->print("Language");
  }
}
void displayCLD::set_language() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(1);
    this->display->fillRect(108, 0, 108, 20, Forte_Green);
    this->display->setCursor(110, 15);
    this->display->setTextColor(BLACK);
    this->display->println("FORTE BIOTECH");
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->drawBitmap(275, 200, shrimp, 35, 29, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(YELLOW);
    this->display->setCursor(30, 50);
    this->display->print("Ngôn ngữ/Language");
    if (language_state == Null) {
      this->display->drawRect(18, 70, 296, 50, GREEN);
      this->display->setCursor(90, 110);
      this->display->setTextColor(GREEN);
      this->display->print("Tiếng Việt");
      this->display->drawRect(18, 130, 296, 50, RED);
      this->display->setTextColor(RED);
      this->display->setCursor(110, 170);
      this->display->print("English");

    } else if (language_state == VietNamese) {
      this->display->drawRect(18, 70, 296, 50, GREEN);
      this->display->setTextColor(GREEN);
      this->display->fillTriangle(30, 75, 30, 115, 70, 95, GREEN);
      this->display->fillTriangle(302, 75, 302, 115, 262, 95, GREEN);
      this->display->setCursor(90, 110);
      this->display->print("Tiếng Việt");
      this->display->drawRect(18, 130, 296, 50, RED);
      this->display->setTextColor(RED);
      this->display->setCursor(110, 170);
      this->display->print("English");
    } else {  // English
      this->display->drawRect(18, 70, 296, 50, GREEN);
      this->display->fillTriangle(30, 135, 30, 175, 70, 1555, RED);
      this->display->fillTriangle(302, 135, 302, 175, 262, 155, RED);
      this->display->setCursor(90, 110);
      this->display->setTextColor(GREEN);
      this->display->print("Tiếng Việt");
      this->display->drawRect(18, 130, 296, 50, RED);
      this->display->setTextColor(RED);
      this->display->setCursor(110, 170);
      this->display->print("English");
    }
    this->display->setTextColor(WHITE);
    this->display->setTextSize(1);
    this->display->setCursor(18, 230);
    this->display->print("Nút trắng:bắt đầu");
    //Write_language_ToEEPROM();
    // Read_language_fromEEPROM();

  } else {
    this->display->fillScreen(BLACK);
    this->display->setTextSize(1);
    this->display->fillRect(108, 0, 108, 20, Forte_Green);
    this->display->setCursor(110, 15);
    this->display->setTextColor(BLACK);
    this->display->println("FORTE BIOTECH");
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->drawBitmap(275, 200, shrimp, 35, 29, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(YELLOW);
    this->display->setCursor(30, 50);
    this->display->print("Language/Ngôn ngữ");
    if (language_state == Null) {
      this->display->drawRect(18, 70, 296, 50, GREEN);
      this->display->setCursor(90, 110);
      this->display->setTextColor(GREEN);
      this->display->print("Tiếng Việt");
      this->display->drawRect(18, 130, 296, 50, RED);
      this->display->setTextColor(RED);
      this->display->setCursor(110, 170);
      this->display->print("English");
    } else if (language_state == VietNamese) {
      this->display->drawRect(18, 70, 296, 50, GREEN);
      this->display->fillTriangle(30, 75, 30, 115, 70, 95, GREEN);
      this->display->fillTriangle(302, 75, 302, 115, 262, 95, GREEN);
      this->display->setCursor(90, 110);
      this->display->setTextColor(BLACK);
      this->display->print("Tiếng Việt");
      this->display->drawRect(18, 130, 296, 50, RED);
      this->display->setTextColor(RED);
      this->display->setCursor(110, 170);
      this->display->print("English");
    } else {
      this->display->drawRect(18, 70, 296, 50, GREEN);
      this->display->fillTriangle(30, 135, 30, 175, 70, 155, RED);
      this->display->fillTriangle(302, 135, 302, 175, 262, 155, RED);
      this->display->setCursor(90, 110);
      this->display->setTextColor(GREEN);
      this->display->print("Tiếng Việt");
      this->display->drawRect(18, 130, 296, 50, RED);
      this->display->setTextColor(RED);
      this->display->setCursor(110, 170);
      this->display->print("English");
    }
    this->display->setTextColor(WHITE);
    this->display->setTextSize(1);
    this->display->setCursor(18, 230);
    this->display->print("White:start");
    //Write_language_ToEEPROM();
    // Read_language_fromEEPROM();
  }
}
void displayCLD::set_connect_bluetooth() {
  if (language == 0) {
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(ORANGE);
    this->display->setCursor(70, 30);
    this->display->print("Cài đặt WIFI");
    this->display->drawRect(18, 50, 296, 50, WHITE);
    this->display->setTextColor(WHITE);
    this->display->setTextSize(1);
    this->display->setCursor(25, 90);
    this->display->print("WiFi ID: " + ssid);
    this->display->drawRect(18, 110, 296, 50, WHITE);
    this->display->setCursor(25, 150);
    this->display->print("Password: " + password);
    this->display->drawRect(18, 170, 296, 50, WHITE);
    this->display->setCursor(25, 210);
    this->display->print("ID: " + id);
    connectWIFI();              // Obtain Wifi ID and password from user via bluetooth
    saveCredentialsToEEPROM();  // save Wifi ID and password in EEPROM
    loadCredentialsFromEEPROM();
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setCursor(25, 120);
    this->display->setTextColor(GREEN);
    this->display->print("Cài đặt thành công!");
    delay(2000);
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(ORANGE);
    this->display->setCursor(70, 30);
    this->display->print("Cài đặt  WIFI");
    this->display->drawRect(18, 50, 296, 50, WHITE);
    this->display->setTextColor(WHITE);
    this->display->setTextSize(1);
    this->display->setCursor(25, 90);
    this->display->print("WiFi ID: " + ssid);
    this->display->drawRect(18, 110, 296, 50, WHITE);
    this->display->setCursor(25, 150);
    this->display->print("Password: " + password);
    this->display->drawRect(18, 170, 296, 50, WHITE);
    this->display->setCursor(25, 200);
    this->display->print("ID: " + id);
    delay(2000);
    ESP.restart();

  } else {
    this->display->fillScreen(BLACK);
    //this->display->drawRect(0,0,320,240,BLUE);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(ORANGE);
    this->display->setCursor(70, 30);
    this->display->print("WIFI Set up");
    this->display->drawRect(18, 50, 296, 50, WHITE);
    this->display->setTextColor(WHITE);
    this->display->setTextSize(1);
    this->display->setCursor(25, 90);
    this->display->print("WiFi ID: " + ssid);
    this->display->drawRect(18, 110, 296, 50, WHITE);
    this->display->setCursor(25, 150);
    this->display->print("Password: " + password);
    this->display->drawRect(18, 170, 296, 50, WHITE);
    this->display->setCursor(25, 210);
    this->display->print("ID: " + id);
    connectWIFI();              // Obtain Wifi ID and password from user via bluetooth
    saveCredentialsToEEPROM();  // save Wifi ID and password in EEPROM
    loadCredentialsFromEEPROM();
    //Update newScreen
    this->display->fillScreen(BLACK);
    this->display->setTextSize(2);
    this->display->setCursor(25, 120);
    this->display->setTextColor(GREEN);
    this->display->print("Succesfull!");
    delay(2000);
    this->display->fillScreen(BLACK);
    this->display->drawRoundRect(15, 0, 302, 240, 10, Forte_Green);
    this->display->setTextSize(2);
    this->display->setTextColor(ORANGE);
    this->display->setCursor(70, 30);
    this->display->print("WIFI Set up");
    this->display->drawRect(18, 50, 296, 50, WHITE);
    this->display->setTextColor(WHITE);
    this->display->setTextSize(1);
    this->display->setCursor(25, 90);
    this->display->print("WiFi ID: " + ssid);
    this->display->drawRect(18, 110, 296, 50, WHITE);
    this->display->setCursor(25, 150);
    this->display->print("Password: " + password);
    this->display->drawRect(18, 170, 296, 50, WHITE);
    this->display->setCursor(25, 200);
    this->display->print("ID: " + id);
    delay(2000);
    ESP.restart();
  }
}
void displayCLD::loop() {
  if (this->changeScreen) {
    switch (this->type_infor) {
      case escreenStart:
        {
          dbg_display("escreenStart");
          this->screen_Start();
          _sensor.clear();
          break;
        }
      case ewaitingReadsensor:
        {
          dbg_display("ewaitingReadsensor");
          waiting_Readsensor();
          break;
        }
      case eprepare:
        {
          dbg_display("eprepare");
          this->prepare();
          break;
        }

      case escreenResult:
        {
          dbg_display("escreenResult lan %d", this->couter);
          this->screen_Result();
          break;
        }

      case escreenAverageResult:
        {
          dbg_display("escreenAverageResult");
          _sensor.Average_Result();
          this->screen_Average_Result();
          break;
        }

      case ecalibSensor:
        {
          dbg_display("ecalibSensor");
          this->screen_Calib();
          break;
        }
      case echoosetube:
        {
          this->Choose_tube();
          break;
        }

      case e_setting:
        {

          this->setting();
          break;
        }
      case e_connect_bluetooth:
        {
          this->set_connect_bluetooth();
          break;
        }
      case e_language:
        {
          this->set_language();
          break;
        }

      // case logdata:
      //   {
      //     this->log_data();
      //     this->screen_Average_Result();
      //     _displayCLD.type_infor = escreenAverageResult;
      //     break;
      //   }
      default:
        break;
    }
    this->changeScreen = false;
  }
}

displayCLD _displayCLD;
