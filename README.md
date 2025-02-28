# Campo Minato

Benvenuti nel progetto "Campo Minato"!

Questo progetto è sviluppato da Leonardo e Antonio. Stiamo programmando in C utilizzando le librerie raylib, fork e pipe per creare una versione del classico gioco Campo Minato.

## Descrizione del Progetto

"Campo Minato" è un gioco in cui il giocatore deve scoprire tutte le celle di una griglia che non contengono mine. Il nostro obiettivo è implementare questo gioco utilizzando la libreria grafica raylib per la visualizzazione e le librerie fork e pipe per la gestione dei processi.

## Caratteristiche

- **Grafica**: Utilizziamo la libreria raylib per creare un'interfaccia grafica semplice e intuitiva.
- **Gestione dei Processi**: Utilizziamo le funzioni `fork()` e `pipe()` per gestire i processi e la comunicazione tra di essi.
- **Suoni**: Il gioco include effetti sonori per migliorare l'esperienza di gioco.
- **Impostazioni**: Il giocatore può modificare le impostazioni del gioco, come il colore di sfondo.

## Requisiti

- **Libreria raylib**: Assicurati di avere installato la libreria raylib. Puoi scaricarla e installarla dal sito ufficiale: [raylib](https://www.raylib.com/).
- **Compilatore C**: Assicurati di avere un compilatore C installato. Consigliamo GCC.

## Installazione

1. Clona il repository:
   ```bash
   git clone https://github.com/tuo-username/campo-minato.git
   ```

2. Naviga nella directory del progetto:
   ```bash
   cd campo-minato
   ```

3. Compila il progetto:
   ```bash
   gcc -o campo_minato main.c -lraylib -pthread
   ```

4. Esegui il gioco:
   ```bash
   ./campo_minato
   ```

## Utilizzo

- **Menu Principale**:
  - Premi `ENTER` per iniziare il gioco.
  - Premi `I` per accedere alle impostazioni.
  - Premi `ESC` per uscire dal gioco.

- **Gioco**:
  - Scopri le celle della griglia facendo clic con il mouse.
  - Evita le mine!

- **Impostazioni**:
  - Premi `C` per cambiare il colore di sfondo.
  - Premi `ESC` per tornare al menu principale.

## Contribuisci

Siamo sempre aperti a contributi! Se hai idee per migliorare il gioco o hai trovato un bug, sentiti libero di aprire una issue o inviare una pull request.

## Autori

- **Leonardo** - [Leozz18](https://github.com/Leozz18)
- **Antonio** - [Antonio](https://github.com/Antonio)

## Licenza

Questo progetto è distribuito sotto la licenza MIT. Vedi il file [LICENSE](LICENSE) per i dettagli.

Grazie per aver visitato il nostro progetto! Speriamo che ti diverta a giocare a Campo Minato tanto quanto noi ci siamo divertiti a programmarlo.
