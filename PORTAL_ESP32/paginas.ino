void principal(){
  String  pagina = ""
  "<!DOCTYPE html>"
  "<html><head><title>PORTAL TEST</title></head>"
  "<body><h1> OOOPA IA VEI BLZ?</h1></body></html>";
  Wserver.send(200, "text/html", pagina);
}

void erro(){
  String  pagina = ""
  "<!DOCTYPE html>"
  "<html><head><title>DEU RUIM</title></head>"
  "<body><h1> P U T Z</h1></body></html>";
  Wserver.send(200, "text/html", pagina);
}

void hello(){
  String  pagina = ""
  "<!DOCTYPE html>"
  "<html><head><title>HELLO</title></head>"
  "<body><h1> OLA MUNDO</h1></body></html>";
  Wserver.send(200, "text/html", pagina);
}
