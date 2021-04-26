void principal(){
  String  pagina = ""
  "<!DOCTYPE html>"
  "<html><head><title>PORTAL TEST</title></head>"
  "<body><h1> OOOPA IA VEI BLZ?</h1></body></html>";
  Wserver.send(200, "text/html", pagina);
}

void inicio(){
  String  pagina = ""
  "<!DOCTYPE html>"
  "<html><head><title>Bem vindo</title></head>"
  "<body><h1>Ex de captive portal</h1></body></html>";
  Wserver.send(200, "text/html", pagina);
}

void hello(){
  String  pagina = ""
  "<!DOCTYPE html>"
  "<html><head><title>HELLO</title></head>"
  "<body><h1> OLA MUNDO</h1></body></html>";
  Wserver.send(200, "text/html", pagina);
}
