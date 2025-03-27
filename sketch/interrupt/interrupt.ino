/*
          ,---------------------,
        Bottone       ,------,  |
             '--------|2  ...|  |
                      |......|  |
                      |...GND|--'
                      '------'
*/

int pin=2;
int count=0;

//aumenta count di 1
void ISR(){
  count++;
}

/*inizializza:
    - il pin del bottone come input con pull-up resistor
    - l'interrupt sul pin del bottone, che incrementa count di 1 ogni volta che il pin va da HIGH a LOW
    - la comunicazione seriale a 9600 baud

il pin 2 e 3 dell'R4 sono quelli adatti
*/
void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), ISR, FALLING);
}

//stampa il valore di millis() e count ogni 100ms
void loop() {
  Serial.print(millis());
  Serial.print(":");
  Serial.println(count);
  delay(100);
}