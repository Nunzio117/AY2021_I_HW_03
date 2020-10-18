# ASSIGNMENT 3
## Richieste
Le richieste per tale assignment sono esplicitate nel README generale.


## Schematico
Vi sono presenti i seguenti componenti:
. Pagina 1:
	- CY8CKIT-059 KIT: impostato con "visibile" solo sui canali Rx e TX;
	- X3 Resistenze da 330 Ohm;
	- Led_Red: Pin relativo al canale del rosso;
	- Led_Green: Pin relativo al canale del verde;
	- Led_blue: Pin relativo al canale del blu;
	- Red: rappresentazione del canale rosso del led RGB;
	- Green: rappresentazione del canale verde del led RGB;
	- Blue: rappresentazione del canale blu del led RGB;
	- UART: componente interno al PSoC per comunicazione con terminale.
. Pagina 2:
	- PWM_RG: PWM per gestire i colori rosso e verde del LED RGB;
	- PWM_BLUE: PWM per gestire il colore blu del LED RGB;
	- Timer: timer per avere una isr per conteggio dei 5 secondi come richiesti da assignment.


## Port/Pin
Si hanno le seguenti porte con i corrispettivi pin:
- P2[5]: porta relativa al canale del colore blue e corrispondente al pin 68;
- P2[6]: porta relativa al canale del colore verde e corrispondente al pin 1;
- P2[7]: porta relativa al canale del colore rosso e corrispondente al pin 2;
- P12[6]: port relativa al Rx del PSoC e corrispondente al pin 20;
- P12[7]: port relativa al Rx del PSoC e corrispondente al pin 21.


## Firmware
Nei file di "Header" e di "Source" vi sono esplicitati già i dettagli reativi alle righe di codice presenti.


## Nota sulla programmazione dell'elaborato


