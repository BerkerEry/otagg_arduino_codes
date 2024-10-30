const int RELAY_PIN=8;
const int STEP_PIN=3;   // STEP pininin Arduino'daki numarası
const int DIR_PIN=2;    // DIR pininin Arduino'daki numarası
const int left = 9;
const int right = 10;

int r_en = 4;  
int l_en = 5;  
int r_pwm = 6; 
int l_pwm = 7; 
// const int relayPin = 8;
int stop = 11;

const unsigned long HALF_OPEN_DURATION = 1100;
const unsigned long FULL_OPEN_DURATION = 5000;


String control_package;

char Cpackage[10];

char *bit1,*bit2,*bit3;

int i1=0,i2=1,i3=0;

double cTime,pTime;

void setup() {
  Serial.begin(115200);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(r_en, OUTPUT);
  pinMode(l_en, OUTPUT);
  pinMode(r_pwm, OUTPUT);
  pinMode(l_pwm, OUTPUT);
  pinMode(stop, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  digitalWrite(RELAY_PIN,HIGH);
  digitalWrite(left, HIGH);
  digitalWrite(right, HIGH);
  digitalWrite(stop, HIGH);
}

int total_steering_l=0;

int total_steering_r=0;

double currrent_signal_timer=0;


void loop() {
    while (Serial.available()) {
        control_package=Serial.readStringUntil('#');

        control_package.toCharArray(Cpackage,6);

        bit1=strtok(Cpackage,"|");
        bit2=strtok(NULL,"|");
        bit3=strtok(NULL,"#");

        i1=atoi(bit1);
        i2=atoi(bit2);
        i3=atoi(bit3);

        int relay_pos=digitalRead(RELAY_PIN);

        
        digitalWrite(stop,!i2);

        Serial.println("a");
        if (i2 && !relay_pos) {
          
          Serial.println("b");
          digitalWrite(stop,LOW);
          
        digitalWrite(RELAY_PIN,HIGH);

            digitalWrite(r_en, HIGH);
  digitalWrite(l_en, HIGH);

  // Geri hareket ettir (kapat)
  digitalWrite(r_pwm, 255);
  digitalWrite(l_pwm, 0); // Maksimum hızda geri
//  digitalWrite(relayPin, LOW);
  // Tam kapanması için bekle
  delay(FULL_OPEN_DURATION);

  // Motorları durdur
  digitalWrite(r_pwm, 0);
  digitalWrite(l_pwm, 0);
  //delay(100);

  // Motorları devre dışı bırak
  digitalWrite(r_en, LOW);
  digitalWrite(l_en, LOW);
      
          
        } else if (!i2 && relay_pos) {
          Serial.println("c");
          digitalWrite(stop,HIGH);

            digitalWrite(r_en, HIGH);
  digitalWrite(l_en, HIGH);

  // İleri hareket ettir (yarı açık)
  digitalWrite(r_pwm, 0); // Maksimum hızda ileri
  digitalWrite(l_pwm, 255);
 // digitalWrite(relayPin, HIGH);
  // Yarı açık konuma gelmesi için bekle
  delay(HALF_OPEN_DURATION);

  // Motorları durdur
  digitalWrite(r_pwm, 0);
  digitalWrite(l_pwm, 0);
  
        digitalWrite(RELAY_PIN,LOW);
        }
        //digitalWrite(DIR_PIN,i1);        
    }
	//sol
	if (i3 && total_steering_l<30 && !i1){

    if ((i3-total_steering_l)<0) {
      digitalWrite(DIR_PIN,1);


    for (int i=0; i<5 ; i++) {

      digitalWrite(STEP_PIN,HIGH);
      delayMicroseconds(2000);
      digitalWrite(STEP_PIN,LOW);
      delayMicroseconds(2000);
                        
    }
      total_steering_l--;
      total_steering_r++;
      
    } else if (i3-total_steering_l>0){

      digitalWrite(DIR_PIN,0);

		for (int i=0; i<5 ; i++) {

      digitalWrite(STEP_PIN,HIGH);
      delayMicroseconds(2000);
      digitalWrite(STEP_PIN,LOW);
      delayMicroseconds(2000);
                        
		}
    total_steering_l++;
		total_steering_r--;
   }
	}
  else if (i3 && total_steering_r<30 && i1){

if (i3-total_steering_r>0){

      digitalWrite(DIR_PIN,1);

    for (int i=0; i<5 ; i++) {

      digitalWrite(STEP_PIN,HIGH);
      delayMicroseconds(2000);
      digitalWrite(STEP_PIN,LOW);
      delayMicroseconds(2000);
                        
    }
    total_steering_l--;
    total_steering_r++;


   }
   
if (i3-total_steering_r<0){

      digitalWrite(DIR_PIN,0);

    for (int i=0; i<5 ; i++) {

      digitalWrite(STEP_PIN,HIGH);
      delayMicroseconds(2000);
      digitalWrite(STEP_PIN,LOW);
      delayMicroseconds(2000);
                        
    }
      total_steering_l++;
      total_steering_r--;

    }
  }

   if (total_steering_r>20 && millis()%1000<500) {
    
      digitalWrite(left, LOW);
      digitalWrite(right, HIGH);
   }

   else if (total_steering_l>20 && millis()%1000<500) {
    
      digitalWrite(left, HIGH);
      digitalWrite(right, LOW);
   } else {
      digitalWrite(left, HIGH);
      digitalWrite(right, HIGH);

   }

    
   }