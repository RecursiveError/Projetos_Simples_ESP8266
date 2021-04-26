/*
Projeto: ESP WebServer
Programa: Simples Web Server para NodeMCU 1.0
Autor: RecursiveError
Versão: 1.0.0
Data: 27/11/2020
Objetivo: Testar aprendizado 
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


const char* nome = "**********";//nome da rede
const char* senha = "**********";//senha da rede


ESP8266WebServer server(80);// objeto server e a porta  

//prototipos das funções 
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
  WiFi.mode(WIFI_STA);//modo do WiFi
  WiFi.begin(nome, senha);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }//aguardando conexão WiFi
  //Respostas do servidor
  //Ex
  //<ip>/ pagina inicial
  //<ip>/verde liga o verde
  //<ip>/vermelho 
  server.on("/", handleRoot);// pagina inicial
  server.on("/verde", LedV);//chama a funçao LedV
  server.on("/vermelho", LedVer);//chama a funçao LedVer
  server.on("/amarelo", LedA);//chama a funçao LedA

  server.onNotFound(handleNotFound);//pagina n encontrada
  server.begin();
  Serial.println("\n SERVER ligado");
}


void loop(){
  server.handleClient();//processo novas conexões
  MDNS.update();//dns para pequenos servidores 
}
