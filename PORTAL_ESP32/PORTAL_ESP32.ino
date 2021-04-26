/*
 Autor: RecursiveError
 Data: 28/11/2020
 Objetivo: criar um simples captive portal com Webserver
 */

#include <WiFi.h>
#include<DNSServer.h>
#include<WebServer.h>

//paginass
void principal();
void inicio();
void hello();

const byte DNS_PORT = 53;// porta do servidor DNS
DNSServer Dserver;// objeto DNS
IPAddress apIP(123,230,10,1);//IP do servidor Web
WebServer Wserver(80);//porta do servidor Web

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255,255,255,0));
  WiFi.softAP("Portal TESTE");//nome da rede

  Dserver.start(DNS_PORT, "*", apIP);//inicio do servidor DNS(Porta, nome, IP do servidor)
  //Nome da pagina requsitada na porta DNS sera redirecionado para algum IP(no caso "*" qualquer pagina vai para nosso Webserver) 
  delay(100);
//Paginas Web
//Veja o ESP8266WebServer para ver exemplos
  Wserver.on("/", principal);
  Wserver.on("/hello", hello);
  Wserver.onNotFound(inicio);
  Wserver.begin();
  delay(10);
  
}

void loop() {
  Dserver.processNextRequest();
  Wserver.handleClient();

}
