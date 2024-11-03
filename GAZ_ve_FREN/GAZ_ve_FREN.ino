const int relayPin = 8;  // Röle modülünün IN4 pininin bağlandığı dijital pin
int r_en = 2;  
int l_en = 3;  
int r_pwm = 5; 
int l_pwm = 6; 

const unsigned long HALF_OPEN_DURATION = 600; // 5 saniye (yarı açık)
const unsigned long FULL_OPEN_DURATION = 5000; // 10 saniye (tam açık)

void setup() {
  pinMode(relayPin, OUTPUT);  // Röle pinini çıkış olarak ayarla
  digitalWrite(relayPin, HIGH);  // Başlangıçta röleyi kapalı tut (motor çalışmaz)
  pinMode(r_en, OUTPUT);
  pinMode(l_en, OUTPUT);
  pinMode(r_pwm, OUTPUT);
  pinMode(l_pwm, OUTPUT);
}

void loop() {
  
  
  loopbldc();
  
  // Aktüatörü tamamen kapat
  closeActuator();
  halfOpenActuator();
  // Aktüatörü yarı aç
  // Sonsuz döngüde bekleyin, böylece loop() bir daha çalışmaz
  while (true) {
    // Do nothing, infinite loop to stop further execution
  }
}

void closeActuator() {
  // Motorları etkinleştir
  digitalWrite(r_en, HIGH);
  digitalWrite(l_en, HIGH);

  // Geri hareket ettir (kapat)
  analogWrite(r_pwm, 255);
  analogWrite(l_pwm, 0); // Maksimum hızda geri

  // Tam kapanması için bekle
  delay(FULL_OPEN_DURATION);

  // Motorları durdur
  analogWrite(r_pwm, 0);
  analogWrite(l_pwm, 0);
  delay(100);

  // Motorları devre dışı bırak
  digitalWrite(r_en, LOW);
  digitalWrite(l_en, LOW);
  
}

void halfOpenActuator() {
  // Motorları etkinleştir
  digitalWrite(r_en, HIGH);
  digitalWrite(l_en, HIGH);

  // İleri hareket ettir (yarı açık)
  analogWrite(r_pwm, 0); // Maksimum hızda ileri
  analogWrite(l_pwm, 255);

  // Yarı açık konuma gelmesi için bekle
  delay(HALF_OPEN_DURATION);

  // Motorları durdur
  analogWrite(r_pwm, 0);
  analogWrite(l_pwm, 0);
  delay(100);
}

void loopbldc() {
  // delay(2000);  // Başlangıçta 2 saniye bekle (isteğe bağlı)
  delay(5000);
  digitalWrite(relayPin, LOW);  // Röleyi aç (motoru çalıştır)
  delay(10000);  // Motoru 10 saniye çalıştır
  digitalWrite(relayPin, HIGH);  // Röleyi kapat (motoru durdur)  
}