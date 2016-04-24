/**
 * Ein C-Programm, das beim Kommando "wuerfel"
 * einen zufaelligen Wert im Bereich von eins bis
 * sechs ausgibt und sich beim Kommando "quit"
 * oder "exit" beendet. Alle Kommandos duerfen
 * mit beliebigen Gross- und Kleinbuchstaben
 * geschrieben werden.
 *
 * Datei: betriebssysteme_kap2_aufg1
 * Datum: 3. Nov 2013
 * Author: Maksym Levchenko (333674)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define BEFEHLLAENGE 10
#define EXIT "exit"
#define QUIT "quit"
#define WUERFELN "wuerfeln"

/* Funktionsprototypen */
void hilfe(void);
int wuerfeln(void);
void fortsetzen(void);
void toLowerCase(char * befehl);

int main(void)
{
    /* Begruessung ausgeben */
    printf("\tWir begruessen Sie bei dem Programm \"Wuerfel\"\n");
    hilfe();
    time_t zeit;     /* Eine Variable, die jetzigen Zeitwert speichert 	*/
    srand((unsigned) time(&zeit));	/* Initialisiere Random Number Generator */
    fortsetzen();
    return EXIT_SUCCESS;
}

/**
 * Gib alle Befehle und ihre Bedeutung aus.
 */
void hilfe(void)
{
    printf("\n\tMoegliche Befehle:"
           "\n\t%s: einen zufaelligen Wert im Bereich von 1 bis 6 "
           "ausgeben"
           "\n\t%s: das Programm beenden"
           "\n\t%s: das Programm beenden\n", WUERFELN, EXIT, QUIT);
}

/**
 * Gib eine Zahl, die >= 1 UND <= 6 ist, zurueck.
 * @return eine Zahl, die >= 1 UND <= 6 ist.
 */
int wuerfeln(void)
{
    return (rand() %6) + 1;
}

/**
 * Faenge an bzw. setze das Programm fort.
 *
 */
void fortsetzen(void)
{
    char befehl[BEFEHLLAENGE];
    printf("\n\tBitte geben Sie einen Befehl an: ");
    /* den Befehl einlesen */
    fgets(befehl, BEFEHLLAENGE, stdin);
    /* "\n" abschneiden */
    long stringLaenge = strlen(befehl);
    befehl[stringLaenge - 1] = '\0';
    toLowerCase(befehl);
    /* Je nach dem Befehl reagieren */
    if(0 == strcmp(befehl, EXIT) || 0 == strcmp(befehl, QUIT))
    {
        printf("\tAde!\n");
        return;
    }
    else if(0 == strcmp(befehl, WUERFELN))
    {
        printf("\tDie gewuerfelte Zahl: \n\t<< %d >>"
               "\n\n\tMoechten Sie noch Mal wuerfeln?", wuerfeln());
//        int c;
//        while ((c = getchar()) != '\n') /* Wenn "wuerfeln wuerfeln wuerfeln" angegeben wurde*/
//        {;}
        fortsetzen();
    }
    else
    {
        printf("\n\tSie haben einen ungueltigen Befehl eingegeben\n");
        hilfe();
        fortsetzen();
    }
}

/**
 * Wandle den Argumenten in ein kleines Buchstabe.
 * @befehl Zeiger auf eine Zeichenkette(Eingegebener Befehl)
 */
void toLowerCase(char * befehl)
{
    for(int i = 0; befehl[i] != '\0' ;i++)
    {
        befehl[i] = tolower(befehl[i]);
    }
}




