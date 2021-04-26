void handleRoot(){
  digitalWrite(16,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  String pagina =  String("<! DOCTYPE html>") +
  "<html>" +
  "<h1 style='text-align:center;'>ESP SERVER</h1>" +
  "<p style='text-align:center;'>Nenhum led ligado</p>"+
  "<form style='display: inline' action='/verde' method='get'>" +
  "<button>Ligar Verde</button>" +
  "</form>"+
  "<form style='display: inline' action='/amarelo' method='get'>" +
  "<button>Ligar Amarelo</button>" +
  "</form>"+
 "<form style='display: inline' action='/vermelho' method='get'>" +
  "<button>Ligar Vermelho</button>" +
  "</form>"+
  "</html>" +
  "\n\r";
  server.send(200, "text/html", pagina); 
}

void handleNotFound(){
  server.send(404, "text/plain", "pagina não encontrada");
}

void LedV(){
  digitalWrite(16,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
   String pagina =  String("<! DOCTYPE html>") +
  "<html>" +
  "<h1 style='text-align:center;color:green';>LED VERDE ON</h1>" +
  "</html>" +
  "<form style='display: inline' action='/amarelo' method='get'>" +
  "<button>Ligar Amarelo</button>" +
  "</form>"+
  "<form style='display: inline' action='/vermelho' method='get'>" +
  "<button>Ligar Vermelho</button>" +
  "</form>"+
  "<form style='display: inline' action='/' method='get'>" +
  "<button>Pagina Inicial</button>" +
  "</form>"+
  "\n\r";
  server.send(200, "text/html", pagina); 
  
}

void LedVer(){
  digitalWrite(16,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
   String pagina =  String("<! DOCTYPE html>") +
  "<html>" +
  "<h1 style='text-align:center;color:red';>LED VERMELHO ON</h1>" +
  "<form style='display: inline' action='/amarelo' method='get'>" +
  "<button>Ligar Amarelo</button>" +
  "</form>"+
  "<form style='display: inline' action='/verde' method='get'>" +
  "<button>Ligar Verde</button>" +
  "</form>"+
  "<form style='display: inline' action='/' method='get'>" +
  "<button>Pagina Inicial</button>" +
  "</form>"+
  "</html>" +
  "\n\r";
  server.send(200, "text/html", pagina); 
}

void LedA(){
  digitalWrite(16,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
   String pagina =  String("<! DOCTYPE html>") +
  "<html>" +
  "<h1 style='text-align:center;color:yellow';>LED AMARELO ON</h1>" +
  "<form style='display: inline' action='/verde' method='get'>" +
  "<button>Ligar Verde</button>" +
  "</form>"+
  "<form style='display: inline' action='/vermelho' method='get'>" +
  "<button>Ligar Vermelho</button>" +
  "</form>"+
  "<form style='display: inline' action='/' method='get'>" +
  "<button>Pagina Inicial</button>" +
  "</form>"+
  "</html>" +
  "\n\r";
  server.send(200, "text/html", pagina); 
}
