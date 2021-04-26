#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SD.h>

//ESP_util
void wifi_error(void);
void wifi_pass(void);
void sd_error(void);
void file_error(void);

//Func_web
void principal(void);
void send_msg(void);
void server_error(void);

#define TIMEOUT  20
int ping;
const char* ssid = "*******";
const char* senha = "*******";

ESP8266WebServer server(80);
LiquidCrystal_I2C lcd(0x27, 16,2);


void setup() {
    lcd.begin();
    //inicia e chega o SD
    if(!SD.begin(D8)){
        sd_error();
        while(1)  ESP.wdtFeed();
    }
   


    WiFi.begin(ssid, senha);
    lcd.print("conectando");
    while(WiFi.status() != WL_CONNECTED){
        lcd.print(".");
        ping++;
        delay(500);
        if(ping >=  TIMEOUT){
              wifi_error();
              while(1) ESP.wdtFeed();    
        }
   }
    wifi_pass();

    server.on("/", principal);
    server.on("/msg", send_msg);
    server.onNotFound(server_error);
    server.begin();
}

void loop() {
  server.handleClient();

}
