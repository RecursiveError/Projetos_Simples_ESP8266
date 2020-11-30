/*
 * Basicamente o mesmo que o feito para NodeMCU com apenas diferenças nos includes  
 */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>


const char* nome = "********";
const char* senha = "********";


WebServer server(80);

void handleRoot();
void LedV();
void LedA();
void LedVer();
void handleNotFound();

void setup(){
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(nome, senha);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/verde", LedV);
  server.on("/vermelho", LedVer);
  server.on("/amarelo", LedA);

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("\n SERVER ligado");
}


void loop(){
  server.handleClient();
}
