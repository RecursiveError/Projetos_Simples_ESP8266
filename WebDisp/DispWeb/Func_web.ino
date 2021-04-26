void principal(void){
    File page = SD.open("page.html", FILE_READ);
    if(!page){
      file_error();
      page.close();
      while(1) ESP.wdtFeed();
    }
    server.streamFile(page, "text/html"); 
    page.close();
}

void send_msg(void){
    String state=server.arg("lmsg");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(state);
    File page = SD.open("page.html", FILE_READ);
    if(!page){
      file_error();
      page.close();
      while(1) ESP.wdtFeed();
    }
    server.streamFile(page, "text/html"); 
    page.close();
}

void server_error(void){
    server.send(404, "text/html", "<h1> tem nada aqui não mete o pé</h1>");
}
