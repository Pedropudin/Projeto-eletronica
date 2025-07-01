#include <Arduino.h>

int playRound(int *values, int level, int position);
void game_over_warning();
void game_start_warning();
void blink_leds(int *values, int valuesSize);
void leds_on();
void leds_off();

#define QUANTITY 5

const int buttonsPin[QUANTITY] = {2, 3, 4, 5, 6};
const int ledsPin[QUANTITY] = {7, 8, 9, 10, 11};

int level = 1;
int *values;
int game_over = false;
int position = 0;

void setup()
{
    for (int i = 0; i < QUANTITY; i++)
    {
        pinMode(buttonsPin[i], INPUT);
        pinMode(ledsPin[i], OUTPUT);
    }

    randomSeed(analogRead(0)); // Uses an unconnected pin as random seed
    Serial.begin(9600);
}

void loop()
{
    if(game_over) {
        game_over_warning();
        level = 1;
        position = 0;
        free(values);
        values = NULL;
        game_over = false;
    }
    
    if(level == 1) {
        game_start_warning();
    }

    if(position == 0) {
        values = (int *)realloc(values, level * sizeof(int));
        values[level - 1] = random(level - 1);
        blink_leds(values, level);
    }

    if(playRound(values, level, position)) {
        if(position == (level - 1)) {
            position = 0;
            level += 1;
            for(int i=0 ; i<QUANTITY ; i++) {
                digitalWrite(ledsPin[i], HIGH);
                delay(100);
            }
            for(int i=0 ; i<QUANTITY ; i++) {
                digitalWrite(ledsPin[i], LOW);
                delay(100);
            }
            delay(100);
        } else {
            position += 1;
        }
    } else {
        game_over = true;
    }

    delay(10); // Used only for simulation
    // TODO: remove delay in real arduino
}

int playRound(int *values, int level, int position)
{
    int played = false;
    int input = -1;

    Serial.print("Esperando input\n");
    while(!played) {
        for(int i=0 ; i<QUANTITY ; i++) {
            if(digitalRead(buttonsPin[i]) == HIGH) {
                played = true;
                input = i;
                digitalWrite(ledsPin[i], HIGH);
                delay(300);
                digitalWrite(ledsPin[i], LOW);
                delay(10);
            }
        }
    }

    Serial.print("Input foi: ");
    Serial.print(input);
    Serial.print("\n");

    return input == values[position];
}

void game_over_warning() {
    Serial.print("PERDEU OTARIO");

    for(int i=0 ; i<3 ; i++) {
        leds_on();
        delay(500);
        leds_off();
        delay(500);
    }
} 

void game_start_warning() {
    Serial.print("Comecando\n");

    leds_on();
    delay(1500);
    leds_off();
}

void blink_leds(int *values, int valuesSize) {
    for(int i=0 ; i<valuesSize ; i++) {
        Serial.print("Acende: ");
        Serial.print(values[i]);
        Serial.print("\n");

        digitalWrite(ledsPin[values[i]], HIGH);
        delay(1000);
        digitalWrite(ledsPin[values[i]], LOW);
        delay(1000);
    }
}

void leds_on() {
    for(int i=0 ; i<QUANTITY ; i++) {
        digitalWrite(ledsPin[i], HIGH);
    }
}

void leds_off() {
    for(int i=0 ; i<QUANTITY ; i++) {
        digitalWrite(ledsPin[i], LOW);
    }
}