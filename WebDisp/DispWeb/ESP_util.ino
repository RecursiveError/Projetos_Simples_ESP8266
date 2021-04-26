

void wifi_error(void){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Falha na conexao");
    lcd.setCursor(0,1);
    lcd.print("WiFi Timeout");
}


void wifi_pass(void){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Conexao Feita");
    lcd.setCursor(0,1);
    lcd.print("IP:");
    lcd.print(WiFi.localIP());
}

void sd_error(void){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SDcard Error");
}

void file_error(void){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FILE error");
  lcd.setCursor(0,1);
  lcd.print("file not found");
}
