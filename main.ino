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