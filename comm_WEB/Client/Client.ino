/*
Programa: Cliente simples NodeMCU(ESP-12E)
Autor: RecursiveError
Versão: 1.2.0(Update 24/11/2020)
Data: 17/11/2020
Objetivo: Testar aprendizado
*/
#include <ESP8266WiFi.h>
#define TIMEOUT 10 //Tempo em seg para tentar se conectar a rede

void Error(int porta);

const char* SENHA = "********"; //Senha da Rede
const char* NOME = "*********";//Nome da Rede
IPAddress ip = {192,168,0,22};//ip do servidor (Programa: Servidor Simples ESP32)

int ping = 0;//Tempo em seg da tentativa de conexão

WiFiClient client;


void setup() {
    //Serial.begin(115200);
    pinMode(16, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4,OUTPUT);
    //Desliga todas as portas 
    digitalWrite( 16, LOW);
    digitalWrite( 5, LOW);
    digitalWrite( 4, LOW);
    delay(10);
    //Conectar ao WiFi
    //caso o ping atinga o timeout ativa a funçao Error() e Reinicia o ESP(veja essa funçao no final do codigo)
    WiFi.begin(NOME, SENHA);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(1000);
      ping++;
      if(ping >= TIMEOUT){
        Error(4);
        break;
       }
     }

//Caso não seja possivel se conectar ao servidor Chama a funçao Erro e Reinicia o ESP
//Em caso de erro verifique se o servidor esta ativo ou se o IP esta correto    
    if (client.connect(ip, 80)) {
      }else{
          Error(5);
      }
  }

  

void loop() {
 // caso o Servidor envie algo executa esse bloco
    if(client.available()){
        String rps = client.readStringUntil('\r');
        //Serial.println(rps);
        
        if((rps.indexOf("l")) >= 0){
          digitalWrite(16, HIGH);
          //Serial.println("ligar");
        }
        if(rps.indexOf("d") >= 0){
          digitalWrite(16,LOW);
          //Serial.println("desligar");
      }
   }
}

//Recebe o valor de uma porta digital, Liga e depois do delay reinicia o ESP
void Error(int porta){
     digitalWrite(porta, HIGH);
     delay(6500);
     ESP.restart();
}
  
