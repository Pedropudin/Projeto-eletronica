#include <Arduino.h>
# include "/home/pudim/Arduino/libraries/2820675-bbe995aa22826a8fbbb6b56ccd56513f9db6cb00/pitches.h"

int playRound(int *values, int level, int position);
void game_over_warning();
void game_start_warning();
void blink_leds(int *values, int valuesSize);
void leds_on();
void leds_off();

#define QUANTITY 5

const int start_game[5] = {
    NOTE_E3,
    NOTE_E3,
    NOTE_E3,
    NOTE_C3,
    NOTE_G3
};

const int next_level[4] = {
    NOTE_F4,
    NOTE_FS4,
    NOTE_G4,
    NOTE_GS4
};

const int lost_level[4] = {
    NOTE_GS3,
    NOTE_G3,
    NOTE_FS3,
    NOTE_F3
};

const int start_game_time[5] = {
    400,
    400,
    400,
    300,
    500
};

const int next_level_time[4] = {
    250,
    250,
    250,
    1500
};

const int lost_level_time[4] = {
    250,
    250,
    250,
    1500
};

const int buttonsPin[QUANTITY] = {2, 3, 4, 5, 6};
const int ledsPin[QUANTITY] = {7, 8, 9, 10, 11};
const int buzzer = 13;
const int soundButtons[QUANTITY] = {
    NOTE_C5,
    NOTE_D5,
    NOTE_E5,
    NOTE_F5,
    NOTE_G5
};

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

    pinMode(buzzer, OUTPUT);

    randomSeed(analogRead(1) + analogRead(0)); // Uses an unconnected pin as random seed
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
            for(int i=0 ; i<4 ; i++) {
                tone(buzzer, next_level[i], next_level_time[i]);
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

    while(!played) {
        for(int i=0 ; i<QUANTITY ; i++) {
            if(digitalRead(buttonsPin[i]) == HIGH) {
                played = true;
                input = i;
                digitalWrite(ledsPin[i], HIGH);
                tone(buzzer, soundButtons[i]);
                delay(300);
                digitalWrite(ledsPin[i], LOW);
                noTone(buzzer);
                delay(10);
            }
        }
    }

    return input == values[position];
}

void game_over_warning() {
    for(int i=0 ; i<4 ; i++) {
        tone(buzzer, lost_level[i], lost_level_time[i]);
        delay(100);
    }

    for(int i=0 ; i<3 ; i++) {
        leds_on();
        delay(500);
        leds_off();
        delay(500);
    }
} 

void game_start_warning() {
    for(int i=0 ; i<5 ; i++) {
        tone(buzzer, start_game[i], start_game_time[i]);
        delay(100);
    }

    leds_on();
    delay(1500);
    leds_off();
}

void blink_leds(int *values, int valuesSize) {
    for(int i=0 ; i<valuesSize ; i++) {
        digitalWrite(ledsPin[values[i]], HIGH);
        tone(buzzer, soundButtons[values[i]]);
        delay(1000);
        noTone(buzzer);
        digitalWrite(ledsPin[values[i]], LOW);
        delay(900);
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