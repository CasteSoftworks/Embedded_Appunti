/*
Faccio lampeggiare un led ogni secondo

   ,---------------------------------,
   |                    ,------,     |
   '-[R]---[- LED +]----|3     |     |
                        |......|     |
                        |...GND|-----'
                        '------'
   
*/

//definisco il GPIO a cui collego il LED
const int LED = 3;
//definisco l'attesa
const int attesa = 1000;

void setup() {
  //setto il pin del LED come di output (manda un segnale)
  pinMode(LED, OUTPUT);
}

void loop() {
  //mando un segnale alto --> corrente
  digitalWrite(LED, HIGH);
  //aspetto 1 secondo  
  delay(attesa);
  //mando un segnale basso --> non erogo corrente
  digitalWrite(LED, LOW);
  //aspetto un secondo
  delay(attesa);
}
