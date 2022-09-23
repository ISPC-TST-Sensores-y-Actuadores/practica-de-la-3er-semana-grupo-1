int led=6;
int led2=3;
int sensor=7; //sensor izquierda
int sensor2=8; //sensor derecha
int motor1A=11;//motor izquierda
int motor1B=10;
int motor2A=5; //motor derecha
int motor2B=4;
int valorsen=0;
int valorsen2=0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(sensor, INPUT); //config pin sensor1 cny70
  pinMode(sensor2, INPUT);//config pin sensor2 cny70
  pinMode(2, OUTPUT);
}

void loop() {
 digitalWrite(2,HIGH); // Genero 5 V para el circuito desde pin 2
 digitalWrite(9,HIGH); // Genero 5 V para el circuito desde pin 2
 valorsen=digitalRead(sensor); // lectura de sensor izq
 valorsen2=digitalRead(sensor2);//lectura de sensor der
 if((valorsen==0)&&(valorsen2==0)){ //estructura de decision para motores, si en ambos se absorbe luz superficie negra 
  
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  delay(1000);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
  delay(1000);
  }
 else if((valorsen==0)&&(valorsen2==1)){ //estructura de decision para motores, giro izquierda 
  
  digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,LOW);
  delay(1000);
  digitalWrite(motor2A,HIGH);
  digitalWrite(motor2B,LOW);
  delay(1000);
  }
  else if((valorsen==1)&&(valorsen2==0)){ //estructura de decision para motores, giro derecha 
  
  digitalWrite(motor1A,HIGH);
  digitalWrite(motor1B,LOW);
  delay(1000);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,LOW);
  delay(1000);
  }
  else{//estructura de decision para motores, en otro caso como ambos superficie blanca detener motores
    digitalWrite(motor1A,LOW);
  digitalWrite(motor1B,LOW);
  delay(1000);
  digitalWrite(motor2A,LOW);
  digitalWrite(motor2B,LOW);
  delay(1000);
    
    }
 
 digitalWrite(led, valorsen);
 digitalWrite(led2, valorsen2);
 delay(500);
 Serial.print("Valor sensor 1 = "); //impresion de data por monitor en serie para verificar
 Serial.println(valorsen);
  Serial.print("Valor sensor 2 = ");
 Serial.println(valorsen2);
 
}
