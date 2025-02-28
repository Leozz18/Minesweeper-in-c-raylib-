#include <unistd.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLONNA 10 // Numero di colonne della griglia
#define RIGA 10 // Numero di righe della griglia

#define ALTEZZA 800 // Altezza della finestra
#define LARGHEZZA 800// Larghezza della finestra

#define LCELLA (ALTEZZA / RIGA) // Larghezza di una cella
#define HCELLA (LARGHEZZA / COLONNA) // Altezza di una cella

typedef enum { MENU, GIOCO, IMPOSTAZIONI, USCITA } StatoGioco;// Stati del gioco

int main() {
    srand(time(NULL));

    // Inizializzazione della finestra e dell'audio
    InitWindow(LARGHEZZA, ALTEZZA, "CAMPO MINATO: GRIGLIA");// Inizializza la finestra
    InitAudioDevice();// Inizializza l'audio
    SetTargetFPS(60);// Imposta il frame rate a 60

    StatoGioco statoGioco = MENU;// Stato iniziale del gioco
    Color coloreSfondo = (Color){rand() % 256, rand() % 256, rand() % 256, 255};// Colore di sfondo iniziale

    // Carica l'immagine di sfondo
    Texture2D sfondo = LoadTexture("flag.png");// Carica l'immagine di sfondo
    if (sfondo.id == 0) {// Se l'immagine non è stata caricata correttamente
        printf("Errore: Impossibile caricare l'immagine di sfondo\n");
        return -1;
    }

    // Carica i suoni
    Sound suonoEnter = LoadSound("enter.wav");// Carica il suono di enter
    Sound suonoEscape = LoadSound("escape.wav");// Carica il suono di escape
    Sound suonoChangeColor = LoadSound("change_color.wav");// Carica il suono di cambio colore
    Sound suonoMouseClick = LoadSound("mouse_click.wav");// Carica il suono del click del mouse

    // Imposta il volume dei suoni
    SetSoundVolume(suonoEnter, 0.5f); // 50% del volume massimo
    SetSoundVolume(suonoEscape, 0.5f);// 50% del volume massimo
    SetSoundVolume(suonoChangeColor, 0.5f);// 50% del volume massimo
    SetSoundVolume(suonoMouseClick, 0.05f);// 5% del volume massimo

    while (!WindowShouldClose() && statoGioco != USCITA) {// Finché la finestra non è chiusa e lo stato del gioco non è USCITA
        BeginDrawing();// Inizia a disegnare

        switch (statoGioco) {// Switch sullo stato del gioco
            case MENU: {// Stato del menu
                ClearBackground(BLACK);// Sfondo nero
                DrawTexture(sfondo, 0, 0, WHITE);// Disegna l'immagine di sfondo

                DrawText("CAMPO MINATO", LARGHEZZA / 2 - MeasureText("CAMPO MINATO", 40) / 2, 200, 40, BLUE);// Disegna il titolo
                DrawText("Leonardo & Antso", LARGHEZZA / 2 - MeasureText("Leonardo & Antso", 20) / 2, 250, 20, BLUE);// Disegna gli autori 
                DrawText("Premi ENTER per iniziare", LARGHEZZA / 2 - MeasureText("Premi ENTER per iniziare", 20) / 2, 300, 20, DARKGRAY);// Disegna il testo per iniziare
                DrawText("Premi I per impostazioni", LARGHEZZA / 2 - MeasureText("Premi I per impostazioni", 20) / 2, 325, 20, DARKGRAY);// Disegna il testo per le impostazioni
                DrawText("Premi ESC per uscire", LARGHEZZA / 2 - MeasureText("Premi ESC per uscire", 20) / 2, 350, 20, DARKGRAY);// Disegna il testo per uscire
                
                if (IsKeyPressed(KEY_ENTER)) {// Se viene premuto il tasto ENTER
                    PlaySound(suonoEnter);// Riproduci il suono di enter
                    statoGioco = GIOCO;//   Vai allo stato di gioco
                }
                if (IsKeyPressed(KEY_I)) {// Se viene premuto il tasto I
                    statoGioco = IMPOSTAZIONI;// Vai allo stato delle impostazioni
                }
                if (IsKeyPressed(KEY_ESCAPE)) {// Se viene premuto il tasto ESC
                    PlaySound(suonoEscape);// Riproduci il suono di escape
                    statoGioco = USCITA;// Esci dal gioco
                }
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {// Se viene premuto il tasto sinistro del mouse
                    PlaySound(suonoMouseClick);// Riproduci il suono del click del mouse    
                }
            } break;

            case GIOCO: {// Stato di gioco
                ClearBackground(coloreSfondo);// Sfondo colorato

                // Disegna le linee verticali della griglia
                for (int i = 0; i <= COLONNA; i++) {// Per ogni colonna
                    DrawRectangleLines(i * LCELLA, 0, i * LCELLA, ALTEZZA, BLACK);// Disegna una linea verticale
                }

                // Disegna le linee orizzontali della griglia
                for (int i = 0; i <= RIGA; i++) {// Per ogni riga
                    DrawRectangleLines(0, i * HCELLA, LARGHEZZA, i * HCELLA, BLACK);// Disegna una linea orizzontale
                }

                if (IsKeyPressed(KEY_ESCAPE)) {// Se viene premuto il tasto ESC
                    PlaySound(suonoEscape);// Riproduci il suono di escape
                    statoGioco = MENU;// Torna al menu
                }
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {// Se viene premuto il tasto sinistro del mouse
                    PlaySound(suonoMouseClick);// Riproduci il suono del click del mouse    
                }
                if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {// Se viene premuto il tasto destro del mouse
                    PlaySound(suonoMouseClick);// Riproduci il suono del click del mouse
                }
            } break;

            case IMPOSTAZIONI: {// Stato delle impostazioni
                ClearBackground(RAYWHITE);// Sfondo bianco

                DrawText("IMPOSTAZIONI", LARGHEZZA / 2 - MeasureText("IMPOSTAZIONI", 40) / 2, 200, 40, BLUE);// Disegna il titolo
                DrawText("Premi C per cambiare colore di sfondo", LARGHEZZA / 2 - MeasureText("Premi C per cambiare colore di sfondo", 20) / 2, 300, 20, DARKGRAY);// Disegna il testo per cambiare colore
                DrawText("Premi BACKSPACE per tornare al menu", LARGHEZZA / 2 - MeasureText("Premi ESC per tornare al menu", 20) / 2, 350, 20, DARKGRAY);// Disegna il testo per tornare al menu
                
                if (IsKeyPressed(KEY_C)) {// Se viene premuto il tasto C
                    PlaySound(suonoChangeColor);// Riproduci il suono di cambio colore
                    coloreSfondo = (Color){rand() % 256, rand() % 256, rand() % 256, 255};// Cambia il colore di sfondo
                }
                if (IsKeyPressed(KEY_BACKSPACE)) {// Se viene premuto il tasto BACKSPACE
                    PlaySound(suonoEscape);// Riproduci il suono di escape
                    statoGioco = MENU;// Torna al menu
                }
                
            } break;

            default:/// Stato di uscita
                break;// Non fare nulla
        }

        EndDrawing();
    }

    // Scarica l'immagine di sfondo e i suoni
    UnloadTexture(sfondo);// Scarica l'immagine di sfondo
    UnloadSound(suonoEnter);// Scarica il suono di enter
    UnloadSound(suonoEscape);// Scarica il suono di escape
    UnloadSound(suonoChangeColor);// Scarica il suono di cambio colore
    UnloadSound(suonoMouseClick);// Scarica il suono del click del mouse
    
    CloseAudioDevice();// Chiudi l'audio
    CloseWindow();// Chiudi la finestra

    return 0;
}