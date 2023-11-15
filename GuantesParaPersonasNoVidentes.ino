#include <Ultrasonic.h>
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#include <string.h>

#define MOTOR 5
#define BUZZER 10
#define TRIG 8
#define ECHO 7

#define MOTOR2 16
#define BUZZER2 17
#define TRIG2 15
#define ECHO2 14

#define Pulsador_1 2
#define Pulsador_2 3
#define Pulsador_3 6
#define Pulsador_4 18

#define SD_PIN 4
TMRpcm Audio;

int distancia, velocidad, dist_parlante, dist_izq, dist_der, velocidad_izq, velocidad_der;
char parlante[7], menu_config, val_conf, val_param;

int parametro_tiempo = 5, parametro_velocidad = 3;

int t1_anterior, t1_actual, t2_anterior, t2_actual;

int flag_pul_menu = 0;

Ultrasonic ultrasonic(TRIG,ECHO);
Ultrasonic ultrasonic2(TRIG2,ECHO2);

int right_hand = 1, left_hand = 0;

void setup() {
  Serial.begin(9600);

  if(!SD.begin(SD_PIN)){
    return;
  }

  Audio.speakerPin = 9;
  Audio.quality(1);
  Audio.setVolume(5);

  pinMode(BUZZER, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(Pulsador_1, INPUT);
  pinMode(Pulsador_2, INPUT);
  pinMode(Pulsador_3, INPUT);
  pinMode(Pulsador_4, INPUT);

  t1_anterior = millis();
  t2_anterior = t1_anterior;
}

void loop() {
    if(digitalRead(Pulsador_1) == 1){
      while(digitalRead(Pulsador_1) == 1);
      if(digitalRead(Pulsador_1) == 0){
        flag_pul_menu = 0;
        Audio.play("menu.wav");
        delay(1250);
        Audio.play("modos.wav");
        Serial.println("Presione 1 para modo por pitido, 2 para modo por vibrador, 3 para modo de audio por voz, 4 para seleccionar el lado de la mano");
        delay(6700);

        while(flag_pul_menu == 0){

          if(digitalRead(Pulsador_1) == 1){
            while(digitalRead(Pulsador_1) == 1);
            if(digitalRead(Pulsador_1) == 0){
              flag_pul_menu = 1;
              Audio.play("pitido.wav");
              delay(2000);
            }
          }

          if(digitalRead(Pulsador_2) == 1){
            while(digitalRead(Pulsador_2) == 1);
            if(digitalRead(Pulsador_2) == 0){
              flag_pul_menu = 2;
              Audio.play("vibrador.wav");
              delay(2000);
            }
          }

          if(digitalRead(Pulsador_3) == 1){
            while(digitalRead(Pulsador_3) == 1);
            if(digitalRead(Pulsador_3) == 0){
              if(right_hand == 1 && left_hand == 1){
                Serial.println("ERROR! Este modo no se puede utilizar con ambas manos. Presione 1 para reconfigurar.");
                flag_pul_menu = 0;
                Audio.play("erm.wav");
                delay(4900);
              }
              else{
                flag_pul_menu = 3;
                Audio.play("modo_voz.wav");
                delay(2300);
              }
            }
          }

          if(digitalRead(Pulsador_4) == 1){
            while(digitalRead(Pulsador_4) == 1);
            if(digitalRead(Pulsador_4) == 0){
              Serial.println("Ud. seleccionó seleccionar el lado de la mano: 1 p/ mano derecha, 2 p/ mano izquierda o 3 p/ ambas manos.");
              flag_pul_menu = 4;
              Audio.play("manos.wav");
              delay(5200);
            }
          }

          if (Serial.available() > 0){
            menu_config = Serial.read();

            if(menu_config != '1')
              menu_config = '0';

            if(menu_config == '1'){
              Audio.play("par.wav");
              delay(3000);
              break;
            }

            if(menu_config != '1' && menu_config != '0'){
              Audio.play("er.wav");
            }
          }
          
        }
      }
    }

  while(menu_config == '1'){
    if(Serial.available() > 0){
    Audio.play("vcon.wav");
    val_conf = Serial.read();
    
      if(val_conf == '1'){
        menu_config = '0';
        Audio.play("vpar.wav");
        delay(2500);
        Serial.flush();
      }
      if(val_conf == '2'){
        menu_config = '0';
        Audio.play("vpar.wav");
        delay(2500);
        Serial.flush();
      }
    }
  }

  while(val_conf == '1'){
    if(Serial.read() != 10)
      Serial.flush();

    if(Serial.available() > 0){
      parametro_tiempo = Serial.read() - 48;
      Serial.print("par tiemp: "); Serial.println(parametro_tiempo);
      Audio.play("time.wav");
      delay(1400);
      menu_config = 0;
      val_conf = 0;
      flag_pul_menu = 0;
      Serial.flush();
    }
  }

  while(val_conf == '2'){
    if(Serial.read() != 10)
      Serial.flush();

    if(Serial.available() > 0){
      parametro_velocidad = Serial.read() - 48;
      Serial.print("par vel: "); Serial.println(parametro_velocidad);
      Audio.play("vel.wav");
      delay(1650);
      menu_config = 0;
      val_conf = 0;
      flag_pul_menu = 0;
      Serial.flush();
    }
  }
  
  while(flag_pul_menu == 4){

    if(digitalRead(Pulsador_1) == 1){
      while(digitalRead(Pulsador_1) == 1);
      if(digitalRead(Pulsador_1) == 0){
        Serial.println("Seleccionó la mano derecha.");
        flag_pul_menu = 0;
        right_hand = 1;
        left_hand = 0;
        Audio.play("der.wav");
        delay(1800);
      }
    }

    if(digitalRead(Pulsador_2) == 1){
      while(digitalRead(Pulsador_2) == 1);
      if(digitalRead(Pulsador_2) == 0){
        Serial.println("Seleccionó la mano izquierda.");
        flag_pul_menu = 0;
        left_hand = 1;
        right_hand = 0;
        Audio.play("izq.wav");
        delay(1900);
      }
    }

    if(digitalRead(Pulsador_3) == 1){
      while(digitalRead(Pulsador_3) == 1);
      if(digitalRead(Pulsador_3) == 0){
        Serial.println("Seleccionó ambas manos.");
        flag_pul_menu = 0;
        left_hand = 1;
        right_hand = 1;
        Audio.play("2manos.wav");
        delay(1900);
      }
    }
  }

  while(flag_pul_menu == 1){
    t1_actual = millis();
    t2_actual = millis();

    if(t1_actual - t1_anterior > 250){

      t1_anterior = millis();

      if(right_hand == 1 && left_hand == 0)
        distancia = ultrasonic.read();
      
      if(left_hand == 1 && right_hand == 0)
        distancia = ultrasonic2.read();
      
      if(right_hand == 1 && left_hand == 1){
        dist_der = ultrasonic.read();
        dist_izq = ultrasonic2.read();
      }

      Serial.println(distancia);

    }

    if(right_hand == 1 && left_hand == 0){
      if(t2_actual - t2_anterior > ((parametro_tiempo*2)*distancia)){
        if(distancia < 7)
          tone(BUZZER, 600);
        else{
          t2_anterior = millis();
          tone(BUZZER, 600);
          delay(100);
          noTone(BUZZER);
        }
      }
    }

    if(left_hand == 1 && right_hand == 0){
      if(t2_actual - t2_anterior > ((parametro_tiempo*2)*distancia)){
        if(distancia < 7)
          tone(BUZZER2, 600);
        else{
          t2_anterior = millis();
          tone(BUZZER2, 600);
          delay(100);
          noTone(BUZZER2);
        }
      }
    }

    if(right_hand == 1 && left_hand == 1){
      if(t2_actual - t2_anterior > ((parametro_tiempo*2)*dist_der)){
        if(dist_der < 7)
          tone(BUZZER, 600);
        else{
          t2_anterior = millis();
          tone(BUZZER, 600);
          delay(100);
          noTone(BUZZER);
        }
      }

      if(t2_actual - t2_anterior > ((parametro_tiempo*2)*dist_izq)){
        if(dist_izq < 7)
          tone(BUZZER2, 600);
        else{
          t2_anterior = millis();
          tone(BUZZER2, 600);
          delay(100);
          noTone(BUZZER2);
        }
      }
    }

    if(digitalRead(Pulsador_1) == 1){
      flag_pul_menu = 0;
      digitalWrite(MOTOR, LOW);
      digitalWrite(MOTOR2, LOW);
      noTone(BUZZER);
      noTone(BUZZER2);
    }
  }

  while(flag_pul_menu == 2){
    t1_actual = millis();
    t2_actual = millis();

    if(t1_actual - t1_anterior > 250){

      t1_anterior = millis();

      if(right_hand == 1 && left_hand == 0)
        distancia = ultrasonic.read();
      
      if(left_hand == 1 && right_hand == 0)
        distancia = ultrasonic2.read();

      if(right_hand == 1 && left_hand == 1){
        dist_der = ultrasonic.read();
        dist_izq = ultrasonic2.read();
      }
      
      Serial.println(dist_izq);
      Serial.println(dist_der);
    }

    if(right_hand == 1 && left_hand == 0){
      if(t2_actual - t2_anterior > (250)){
        t2_anterior = millis();
        velocidad = (parametro_velocidad * 1500)/distancia;
        if(distancia > 18){
          analogWrite(MOTOR, velocidad);
          delay(300);
        }
        else if(distancia < 18){
          analogWrite(MOTOR, 250);
        }
      }
    }

    if(left_hand == 1 && right_hand == 0){
      if(t2_actual - t2_anterior > (250)){
        t2_anterior = millis();
        velocidad = (parametro_velocidad * 1500)/distancia;
        if(distancia > 18){
          analogWrite(MOTOR2, velocidad);
          delay(300);
        }
        else if(distancia < 18){
          analogWrite(MOTOR2, 250);
        }
      }
    }

    if(right_hand == 1 && left_hand == 1){
      if(t2_actual - t2_anterior > (250)){
        t2_anterior = millis();
        velocidad_der = (parametro_velocidad * 1500)/dist_der;
        velocidad_izq = (parametro_velocidad * 1500)/dist_izq;

        if(dist_der > 18 || dist_izq  > 18){

          if(dist_der > 18){
            analogWrite(MOTOR, velocidad_der);
            
          }

          if(dist_izq > 18){
            analogWrite(MOTOR2, velocidad_izq);
            
          }
          
          delay(300);
        }

        if(dist_der < 18 || dist_izq < 18){
          if(dist_der < 18){
            analogWrite(MOTOR, 250);
            
          }
          if(dist_izq < 18){
            analogWrite(MOTOR2, 250);
            
          }
          
        }
      }
    }

    if(digitalRead(Pulsador_1) == 1){
      flag_pul_menu = 0;
      digitalWrite(MOTOR, LOW);
      digitalWrite(MOTOR2, LOW);
      noTone(BUZZER);
      noTone(BUZZER2);
    }
  }

while(flag_pul_menu == 3){
    if(right_hand == 1 && left_hand == 0)
      distancia = ultrasonic.read();
      
    if(left_hand == 1 && right_hand == 0)
      distancia = ultrasonic2.read();

    if(distancia > 0 && distancia < 200)
      dist_parlante = (distancia / 10) * 10;
    if(distancia >= 200 && distancia <= 357)
      dist_parlante = ((distancia - 1) / 20) * 20;

    

    if(distancia >= 1 && distancia < 5)
      Audio.play("1.wav");
      delay(2000);

    if(distancia >= 5 && distancia <= 100){
      if(dist_parlante > distancia && dist_parlante < (distancia + 5)){
        sprintf(parlante, "%d", dist_parlante);
        strcat(parlante, ".wav");
        Audio.play(parlante);
        delay(2000);
      }
      else{
        sprintf(parlante, "%d", (dist_parlante + 5));
        strcat(parlante, ".wav");
        Audio.play(parlante);
        delay(2000);
      }
    }

    if(distancia > 100 && distancia <= 200){
      if(dist_parlante > distancia && dist_parlante < (distancia + 10)){
        sprintf(parlante, "%d", dist_parlante);
        strcat(parlante, ".wav");
        Audio.play(parlante);
        delay(2000);
      }
      else{
        sprintf(parlante, "%d", (dist_parlante + 10));
        strcat(parlante, ".wav");
        Audio.play(parlante);
        delay(2000);
      }
    }

    if(distancia > 200 && distancia <= 357){
      if(dist_parlante > distancia && dist_parlante < (distancia + 20)){
        sprintf(parlante, "%d", dist_parlante);
        strcat(parlante, ".wav");
        Audio.play(parlante);
        delay(2000);
      }
      else{
        sprintf(parlante, "%d", (dist_parlante + 20));
        strcat(parlante, ".wav");
        Audio.play(parlante);
        delay(2000);
      }
    }

    delay(250);

    if(digitalRead(Pulsador_1) == 1){
      flag_pul_menu = 0;
      digitalWrite(MOTOR, LOW);
      digitalWrite(MOTOR2, LOW);
      noTone(BUZZER);
      noTone(BUZZER2);
    }

  }

}
