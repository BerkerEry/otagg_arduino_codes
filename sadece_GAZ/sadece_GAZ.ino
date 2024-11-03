const int relayPin = 8;  // Röle modülünün IN4 pininin bağlandığı dijital pin
 

void setup() {
  pinMode(relayPin, OUTPUT);  // Röle pinini çıkış olarak ayarla
  digitalWrite(relayPin, HIGH);  // Başlangıçta röleyi kapalı tut (motor çalışmaz)
}

void loop() {
  
  
  loopbldc();
  // Aktüatörü tamamen kapat
 
  // Aktüatörü yarı aç
  // Sonsuz döngüde bekleyin, böylece loop() bir daha çalışmaz
  while (true) {
    // Do nothing, infinite loop to stop further execution
  }
}

void loopbldc() {
  // delay(2000);  // Başlangıçta 2 saniye bekle (isteğe bağlı)
  delay(2000);
  digitalWrite(relayPin, LOW);  // Röleyi aç (motoru çalıştır)
  delay(100000);  // Motoru 10 saniye çalıştır
  digitalWrite(relayPin, HIGH);  // Röleyi kapat (motoru durdur)  
}