Rover
*******************************

Sketches e librerie per la gestione di un mini rover con sensore a ultrasuoni per evitare ortacoli.


Setup
=======

Gli sketch utilizzano la libreria common presente nella cartella
``libraries/rover/``: questa deve essere quindi inclusa tra le librerie
utilizzate. Un modo rapido per farlo e' settare nelle preferences dell'Arduino
IDE l'intero repo ``rover`` come cartella degli sketchbook, oppure
copiare la cartella ``libraries/rover`` dentro ``libraries`` dello sketchbook
attuale.

Download
===============

Download tramite git:
    git clone git://git.andreamanni.com/rover

Per aggiornare all'ultima versione::

    cd ~/rover
    git pull

* `Download manuale archivio <https://git.andreamanni.com/web?p=rover;a=snapshot;h=HEAD;sf=tgz>`_
* `Interfaccia git Web <https://git.andreamanni.com/web?p=rover>`_
* `Wiki <http://wiki.piffa.net/index.php/Mini_Rover>`_ 
* `Foum di Discussione <https://forum.piffa.net/viewtopic.php?f=5&t=431>`_
   

Utilizzo
=========

I vari sketch usano la libreria ``rover`` per le funzionalita' di base, nel file ``libraries/rover/rover.cpp`` sono contenute tutte le impostazioni di PIN / variabili (a mo' di file di configurazione) utilizzate per tutte le versioni degli sketch.


Links
=========
Risorse utili:

* Per poter programmare le schede Arduino: `Arduino IDE <https://www.arduino.cc/en/Main/Software#>`_
* Testi consigliati: https://lab.piffa.net/testi.html
* Risorse online: http://wiki.piffa.net/index.php/Guide
