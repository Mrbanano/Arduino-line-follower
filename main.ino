//////CODIGO CREADO POR ALVARO CASTILLO CARREÑO/////////////////
//Sensores  
  //Biblica del uso de los sensores 
  #include <infrarrojo.h>
  //establecer pines de los sensores 
  infrarrojo IR1(12);
  infrarrojo IR2(13);
  //Varibale que recibe los datos
  int A,B;  
  //Variable que almacena los datos
  int a,b,v1,v2;
  //Motores
  //Control de velocidad
  int initM1 = 5;
  int initM2 =10 ;
  //Control de polaridad
  int in1 = 6;
  int in2 = 7;
  int in3 = 8;
  int in4 = 9;
  //inicializacion 
void setup() {
  //VELOCIDAD COMUNICACION SERIAL
  Serial.begin(9600); 
  //Declara salida de los motores 
  pinMode(initM1,OUTPUT);
  pinMode(initM2,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  v1=250;
  v2=250;
 delay(2500);
}
//metodos de movimiento
  //1010
  void Avanzar (){digitalWrite(in1,HIGH);digitalWrite(in2,LOW);analogWrite(initM1,v1);digitalWrite(in3,HIGH);digitalWrite(in4,LOW);analogWrite(initM2,v2);delay(100);}
  //1010
  void Atras   (){digitalWrite(in2,HIGH);digitalWrite(in1,LOW);analogWrite(initM1,v1);digitalWrite(in4,HIGH);digitalWrite(in3,LOW);analogWrite(initM2,v2);delay(100);}
  //1000
  void GirarDer(){digitalWrite(in1,HIGH);digitalWrite(in2,LOW);analogWrite(initM1,v1);digitalWrite(in3,LOW);digitalWrite(in4,LOW);analogWrite(initM2,v2);delay(100);}
  //0010   
  void GirarIzq(){digitalWrite(in1,LOW);digitalWrite(in2,LOW);analogWrite(initM1,v1);digitalWrite(in3,HIGH);digitalWrite(in4,LOW);analogWrite(initM2,v2);delay(100);}
  //1111  
  void Alto    (){digitalWrite(in1,HIGH);digitalWrite(in2,HIGH);analogWrite(initM1,0);digitalWrite(in3,HIGH);digitalWrite(in4,HIGH);analogWrite(initM2,v2);delay(100);}

void Check(){

Serial.print(IR1.lectura(A));Serial.print(IR2.lectura(B));Serial.print("\n \n" );
//Serial.print("\n leyendo estado sensor A: \n" );
  //Serial.print("\n leyendo estado sensor B: \n");   
delay(100); a = IR1.lectura(A); b = IR1.lectura(B);

}


//Metodo de control
void Controll(){
  //con el sensor IR que utilizo el (1) significa que esta en negro y (0) que se encontra sobre blanco 

  //si el sensor A esta en negro 
  if(a==1){
    //y el sensor B tambien esta en negro
    if(b==1){Avanzar();}
    //y el Sensor B ahora esta en blanco
    else{GirarDer();}
    } 
  //si el sensor A esta en blanco
  if(a==0){
    //y el sensor B esta en negro
    if (b==1){GirarIzq();}
    //y el Sensor B esta en blanco
    else{Atras();}    
    }
    }


void pruebas(){
  
  Avanzar();
  delay(2000);
  Atras();
  delay(1000);
  Avanzar();
  delay(2000);
  GirarDer();
  delay(2000);
  GirarIzq();
  delay(2000);
  }
