#include <Arduino.h>

int playRound(int *v, int r);
void game_over_warning();
void game_start_warning();
void play_game();

#define QUANTITY 5

const int buttonsPin[QUANTITY] = {2, 3, 4, 5, 6};
const int ledsPin[QUANTITY] = {7, 8, 9, 10, 11};

int roundNumber;
int *values;
int game_over = false;

void setup()
{
    for (int i = 0; i < QUANTITY; i++)
    {
        pinMode(buttonsPin[i], INPUT);
        pinMode(ledsPin[i], OUTPUT);
    }

    roundNumber = 1;

    randomSeed(analogRead(0)); // Uses an unconnected pin as random seed
    Serial.begin(9600);
}

void loop()
{
    if(game_over) {
        game_over_warning();
        roundNumber = 1;
        values = (int *)realloc(values, roundNumber * sizeof(int));
    }
    
    if(roundNumber == 1) game_start_warning();

    playRound(values, roundNumber);

    Serial.print("\n");
    delay(10); // Used only for simulation
    // TODO: remove delay in real arduino
}

int playRound(int *v, int r)
{
    // ...existing code...

    return EXIT_SUCCESS;
}