#include <math.h>
#define mosfet 13 //mosfetin bağlı olduğu pin

void setup() {
  Serial.begin(9600);
  pinMode(mosfet,OUTPUT);
}

double Termistor(int analogOkuma){

 double sicaklik;
 sicaklik = log(((10240000 / analogOkuma) - 10000));
 sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik)) * sicaklik);
 sicaklik = sicaklik - 273.15;
 return sicaklik;
}


void loop() {

  int val = analogRead(4); // potansiyo metre pini A4
  val = map(val, 0, 1023, 20, 50);//potansiyometre sıcaklık ayar aralığı 20-50 derece
    int deger = analogRead(A5); // NTC okuma pini A5
  double sicaklik = Termistor(deger);
  Serial.println(sicaklik);

  if(sicaklik < val){
    digitalWrite(mosfet ,HIGH);
  }
  else{
    digitalWrite(mosfet,LOW);
  }

  delay(250);
  
  

}
