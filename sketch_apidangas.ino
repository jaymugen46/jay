
// inialisasi pin tombol
int relay1=6;
int relay2=7;
int baca;
int baca1;
int api=4;
int asap=3;


void setup() {
  // put your setup code here, to run once:

 pinMode(api,INPUT);
 pinMode(asap,INPUT);
 pinMode(relay1, OUTPUT);
 pinMode(relay2, OUTPUT);
 Serial.begin(9600);

}

void loop() {
 baca=digitalRead(asap);
 baca1=digitalRead(api);

 if (baca1==LOW || baca==LOW ){
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
 
 }
 
 else{
  digitalWrite(relay1,HIGH);
 
 }



}
 
 

 


