# BME280

Il bme280 è un sensore di umidità, temperatura e pressione atmosferica.
Funziona a 3.3V.

### Modalità

Il bme280 ha 3 modalità di funzionamento:

* Sleep mode:
La modalità di default di avvio inserita dopo l'operazione di power-on-reset.
Non viene effettuata nessuna misurazione ed il consumo di energia è minimo.

* Forced mode:
Una volta selezionata la modalità, viene effettuata una sola misurazione e poi
il sensore ritorna in sleep mode.

* Normal mode:
Effettua misurazioni cicliche alternate da periodi di standby preimpostati.

Per cambiare modalità bisogna scrivere sul registro 0xF4, i bit 7,6,5 settano
l'oversampling della temperatura, i bit 4,3,2 l'oversampling della pressione,
i bit 1,0 settano la modalità: 00 sleep mode, 01 e 10 forced mode, 11 normal mode.

### Interfaccia I2C

In questo chip l'interfaccia I2C è selezionata di default.
Il bme280 funge da slave ed il suo indirizzo nel bus I2C è 1110110 (0x76).

* I2C write 
Il master deve inviare l'indirizzo del device in write mode, poi invia a coppie
di byte, l'indirizzo del registro su cui scrivere e il byte di dati da scrivere.

* I2C read
Per poter leggere un registro bisogna prima inviarlo in write mode.
Poi bisogna iniziare un'altra transazione inviando l'indirizzo del device in read mode.
Poi lo slave trasmetterà i dati a partire dal registro scritto inizialmente
fino a che non si verifica un noackm e una condizione di stop.
