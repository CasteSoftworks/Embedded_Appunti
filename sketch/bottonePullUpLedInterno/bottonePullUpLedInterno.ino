/*
          ,---------------------,
        Bottone       ,------,  |
             '--------|2  ...|  |
                      |......|  |
                      |...GND|--'
                      '------'
*/

//pin bottone
int pin_bottone=2;

//inizializzo il pin del bottone e il led
void setup() {
  pinMode(pin_bottone, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

/*
Se il pin riceve LOW (pressione con il PULLUP) accende il led
Altrimenti lo spegne
*/
void loop() {
  if(digitalRead(pin_bottone)==0){
    digitalWrite(LED_BUILTIN, 1);
    Serial.println("ok");
    
  }else{
    digitalWrite(LED_BUILTIN,0);
    Serial.println("no");
  }
}