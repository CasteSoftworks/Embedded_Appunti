# APPUNTI EMBEDDED

## 25/02

Introduzione al corso  
Per il corso servono  
- IDE
- Board + cavo
- cavetti Dupont e breadboard
- sensori e componenti

## 27/02

Di default dev\tty non è abilitato su Linux, per risolvere:  
`ls -l /dev/tty*`
- trova ttyUSB* o ttyACM*

`sudo usermod -a -G dialout nomeUtente`
- setta nel gruppo dialout l'utente e tutta la sua roba tty

Si installa la .AppImage e la si rende eseguibile con:  
`chmod a+x arduino-ide_x.y.z_Linux_64bit.AppImage`

La lanci con:  
`./arduino-ide_x.y.z_Linux_64bit --no-sandbox`

### CICLO DI SVILUPPO

Un programma Arduino è detto Sketch  
Architettura Harvard

La scelta della board dipende dalla applicazione

Lo Sketch è diviso in due **macro funzioni**:
- **setup**: eseguito una volta sola, per preparare
- **loop**: eseguito in continuazione

## 4/03

### ELETTRICITA'

#### Come funziona la corrente elettrica
La corrente elettrica viagga sui materiali:
- facilmente: se è conduttore
- difficilmente: se è isolante

La corrente elettrica è il passaggio (la propagazione dell'effetto è quasi alla velocità della luce) da un atomo ad un'altro di elettroni.  
Un atomo con un numero di elettroni diverso da quello a riposo si dice **ione**:
- *positivo*: se ne ha in sovrannumero
- *negativo*: se ne ha in sottonumero  

Il movimento degli elettroni è generato dalla applicazione di un **differenziale di tensione** ai capi del materiale.  
Più è alta la tensione più elettroni si muoveranno  
L'unità di misura della tensione è il **Volt** V, il suo simbolo è V  
Quando il circuito è fisicamente aperto può essere ancora elettricamente chiuso se si ha una tensione abbastanza elevata (ogni 1000V la corrente *salta* un millimetro in aria).

La quantità di elettroni chd si muovono nel tempo si dice **intensità di corrente**
L'unità di misura della corrente è il *Culomb/Secondo* o **Ampere** A, il suo simbolo è I  
La direzione convenzionale della corrente è da - a + (inversa della direzione vera degli elettroni)

#### Leggi di Ohm
$V=R \cdot I$  
R è la **resistenza del materiale**, si misura in *Volt/Ampere* o **Ohm** $\Omega$ e si oppone allo spostamento della corrente, disperdendo della energia  

Dalla formula si ottiene anche la formula inversa della corrente $I=V/R$ e della resistenza $R=V/I$

Se vado a 12V e ho 100A la resistenza è di $R=V/I=12V/100A=0,12 \Omega$

#### Potenza
$P=V \times I$  
La potenza si misura in **Watt** e si indica con W  
Applicando una delle due leggi di Ohm posso ottenere: $P=R \cdot I^2$ o $P=V^2/R$

Indica il flusso di lavoro elettrico e la dissipazione calorifica  
La dissipazione non è detto sia lineare  
Il raddoppiamento della potenza on garantisce un raddoppiamento di prestazioni

#### Batterie
Hanno Voltaggio, Ah e (quelle grandi da auto e oltre) hanno la Corrente d'Impulso
##### Ah
Gli **Ampere Ora** Ah indicano quanti ampere una batteria riesce a erogare in un ora 
Se ho una batteria da 100Ah e chiedo 50A durerà due ore, se chiedo 100A durerà un'ora, ...
##### Corrente d'impulso
Quantità massima di corrente erogabile istantaneamente da una batteria

#### Carico
Quanta potenza viene assorbita da un qualunque apparato  
Carico puramente resistivo è un carico che assorbe *tutto*

## 11/3
### ELETTRICITA'
Una resistenza è visulizzabile come un dosso sulla discesa della tensione
```
VCC---100 Ohm--5K Ohm--GND

\
 \
  ---  /\
     \/  \
```
#### Leggi di Kirchhoff
1) la somma delle tensioni in un qualunque circuito è 0  
$\displaystyle\sum_{k=1}^n ik=0$
1) la somma dei voltaggi in un qualunque circuito è 0  
$\displaystyle\sum_{i=1}^n Vi=0$
## 13/3

HIGH --> 5v  
LOW --> 0V  
Alcune board fanno il contrario, **testare**
### Accendere un LED
vedi `./sketch/LampeggioLed/`

## 18/3

### Pullup e Pulldown
```
1)
          /-[+ -]-GND
GPIO----+/
           ----GND

2)
          /
GPIO----+/  --[+ -]-GND

3)
             /
GPIO----+--+/  --[+ -]-GND
        |
        100k
        |
       GND

4)
GPIO----+----100k--[+ -]-GND
       /
      / 
        |
       GND    
```
1) esempio *ideale*  
2) non va bene perché lascia floating  
3) Pulldown  
   1) bottone da pin a V
4) Pullup
   1) bottone da pin a GND

## 20/3
Laboratorio  
GPIO da in decine di mA
## 25/3

### ELETTRICITA
**Loop chiuso** --> lo stato viene controllato e modificato di conseguenza  

#### PWM - Pulse Width Modulation
Versione "semplice" del DAC  
Accende e spegne velocemente seguendo un duty cycle  

Dusty cicle del 100%
```
-------------------------  ...



```
Duty cicle 50%
```
-, ,-, ,-, ,-, ,-, ,-, ,-,
 | | | | | | | | | | | | |
 | | | | | | | | | | | | |
 '-' '-' '-' '-' '-' '-' ' ...
```
Duty cicle al 30%
```
-,   ,-,   ,-,   ,-,   ,-, 
 |   | |   | |   | |   | |
 |   | |   | |   | |   | |
 '---' '---' '---' '---' ' ...
```
`Veff` si dice il voltaggio equivalente alla tensione PWM erogata  
$Veff=sqrt(Duty)$

Su arduino il pin che può fare PWM è segnato con `~`  
Si usa con `analogWrite(pin, duty);`   
Esempio LED:
* GPIO con PWM
* resistenza
* LED
* massa
