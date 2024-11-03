#define STEP_PIN 3   // STEP pininin Arduino'daki numarası
#define DIR_PIN 2    // DIR pininin Arduino'daki numarası
const int right = 9;
const int left = 8;

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  
}

void loop() {
  unsigned long startTime = millis(); // Başlangıç zamanını al
  while (millis() - startTime < 20000) { 

    
    
digitalWrite(DIR_PIN, LOW);  // LOW=SAĞ
    for (int i = 0; i < 150; i++) {

      digitalWrite(right, HIGH);
      digitalWrite(left, LOW);
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(4000);  // Adım hızı, ihtiyaca göre ayarlanabilir
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(4000);  // Adım hızı, ihtiyaca göre ayarlanabilir
    }

    delay(1000);

   digitalWrite(DIR_PIN, HIGH);  //high=sol
    for (int i = 0; i < 300; i++) {
      digitalWrite(right, LOW);
      digitalWrite(left, HIGH);
   
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(4000);  // Adım hızı, ihtiyaca göre ayarlanabilir
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(4000);  // Adım hızı, ihtiyaca göre ayarlanabilir
    }

    delay(1000);  // Bir saniye bekleme

    digitalWrite(DIR_PIN, LOW);  // LOW=SAĞ
    for (int i = 0; i < 150; i++) {
      digitalWrite(right, HIGH);
      digitalWrite(left, LOW);
   
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(4000);  // Adım hızı, ihtiyaca göre ayarlanabilir
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(4000);  // Adım hızı, ihtiyaca göre ayarlanabilir
      digitalWrite(right,HIGH);
      digitalWrite(left , HIGH);
    }

    delay(1000);

  // 10 saniye sonunda motoru durdur
  while (true) {
    // Motoru durdurmak için hiçbir şey yapma (sonsuz döngü)
  }
  }
}