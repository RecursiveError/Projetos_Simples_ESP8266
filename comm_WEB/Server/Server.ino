/*
Programa: Servidor Simples ESP32
Autor: RecursiveError
Versão: 1.0.0
Data: 17/11/2020
Objetivo: Testar aprendizado
*/
#include <WiFi.h>

const char* SENHA = "*******"; // senha da rede
const char* NOME = "*********";// nome da rede
WiFiServer server(80);//idefine a porta do servidor
int botao; 
int stb = 1; // estado anterior do botao

void setup() {
    //Serial.begin(115200); modo para debug
    pinMode(23, INPUT); //pino do botao
    
    WiFi.begin(NOME, SENHA);
    while(WiFi.status() != WL_CONNECTED){}//loop infinito ate se conectar com a rede 
    //Serial.println(WiFi.localIP()); ip do dispositivo

    server.begin();//inicia o servidor
}

void loop() {
  
    WiFiClient client = server.available();// verifica se a dispositivos conectados
    if (client) {
        while(client.connected()){
            //executa o bloco caso o cliente esteva conctado 
            botao = digitalRead(23);
            //detecta alteraçao no estado do botao enviando apenas 1 pacote a cada alteraçao 
            //(usado para evitar pacotes inuteis caso o botao fique presionado por muito tempo) 
            if(botao && stb == 1){
              client.println("l\r\n");
              //Serial.println("ligando");
              stb = 0; // muda o estado anterior do botao para desligado
              }
          if(!botao && stb == 0){
              client.println("d\r\n");
              //Serial.println("desligar");
              stb = 1;// muda o estado anterior do botao para ligado 
        }   
      }
    }
  }
