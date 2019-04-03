
// MICROCONTROLADORES ETAPA 1
// POSADAS CORTES ETHAN MARCOS
// 
// Seguidor de linea negra con sensores TCRT5000

// declaramos las variables de tip enteros
int VelocidadMotor1 = 5; //ENA--- al pin 5 del Arduino 
int VelocidadMotor2 = 9; //ENB---al pin 9 

int Motor1A = 6; //IN2--- al pin 6 
int Motor1B = 7;  //IN1--- al pin 7
int Motor2C = 8; //IN4--- al pin 8
int Motor2D = 10; //IN3--- al pin 10

int infraPin = 2;    // izquierdo - pin del infrarrojos utilizado como entrada digital
int infraPin1=4;  //  derecho
int valorInfra = 0;  // Valor inicial de la lectura digital del infrarrojos izquierdo 
int valorInfra1 = 0;  // derecho

// declaracion de puertos como I/O
void setup() {
  delay(5000); // ESPERA 5 SEGUNDOS PARA LUEGO INICIAR CON LAS LECTURAS
   pinMode(infraPin, INPUT);    // Sensor Izquierdo
   pinMode(infraPin1, INPUT);   //Sensor derecho
   pinMode(Motor1A,OUTPUT);
   pinMode(Motor1B,OUTPUT);
   pinMode(Motor2C,OUTPUT);
   pinMode(Motor2D,OUTPUT);
   pinMode(VelocidadMotor1, OUTPUT);
   pinMode(VelocidadMotor2, OUTPUT);
   
   //VELOCIDAD INICIAL DEL MOTOR
    analogWrite(VelocidadMotor1, 200); //motor izquierdo
    analogWrite(VelocidadMotor2, 180);  //motor derecho

     // PARA INICIAR EL MOTOR EN ALTO DURANTE 5 SEGUNDOS
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor1B, LOW);
      digitalWrite(Motor2C, LOW);
      digitalWrite(Motor2D, LOW);

}

void loop() {
   valorInfra = digitalRead(infraPin);    // Lee el valor de la entrada que lee el infrarrojo izquierdo
   valorInfra1 = digitalRead(infraPin1);  // derecho
                 
   // 1= blanco / 0 = negro
  //compara los valores de los sensores
  if(valorInfra == 1 && valorInfra1 == 1){ // si ambos sensores detectan el blanco entonces avanza Hacia delante
     
      digitalWrite(Motor1A, HIGH);
      digitalWrite(Motor2D, HIGH);
      delay(20);                      // Tiempo de espera
      digitalWrite(Motor1A, LOW);
      digitalWrite(Motor2D,LOW);
       delay(20);                     // Tiempo de espera
}

 if(valorInfra == 1 && valorInfra1 == 0){  // Si el snesor derecho detecta el negro entonces Gira el motor izquierdo
     digitalWrite(Motor1A, LOW);
      digitalWrite(Motor2D,LOW);
       delay(25);
  digitalWrite(Motor1A, HIGH);
      digitalWrite(Motor2D,LOW);
      delay(20);
      analogWrite(VelocidadMotor1, 200); //motor izquierdo
      analogWrite(VelocidadMotor2, 150);
}

 if(valorInfra == 0 && valorInfra1 == 1){ // Si el sensor izquierdo detecta el negro entonces Gira el motor derecho

  digitalWrite(Motor1A,LOW);
      digitalWrite(Motor2D, LOW);
          delay(25);
           digitalWrite(Motor1A,LOW);
      digitalWrite(Motor2D, HIGH);
      delay(20);
      analogWrite(VelocidadMotor1, 150); 
      analogWrite(VelocidadMotor2, 200); //motor derecho
}

 if(valorInfra == 0 && valorInfra1 == 0){  // si ambos sensores detectan el negro entonces se DETIENE
     
  digitalWrite(Motor1A, LOW);
      digitalWrite(Motor1B, LOW);
      digitalWrite(Motor2C, LOW);
      digitalWrite(Motor2D, LOW);
      
}

}
