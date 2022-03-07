#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include "../avr_common/uart.h" // this includes the printf and initializes it

unsigned int COUNTER = 0;

//Di default assumo che lo stato sia 00.
void S1(uint8_t k1 ,uint8_t k2 );
void S2(uint8_t k1 ,uint8_t k2 );
void S3(uint8_t k1 ,uint8_t k2 );
void S4(uint8_t k1 ,uint8_t k2 );


typedef void (*StatePointer)(uint8_t k1 ,uint8_t k2 );

StatePointer currentState = S1;

void S1(uint8_t k1 ,uint8_t k2 ){
    if(k1&1 ){
        if(k2 & 1){
            //Invalid state.
        }else{
            currentState = S4;
            COUNTER--;
        }
    }else{
        if(k2 & 1){
            currentState = S2;
            COUNTER++;
        }else{
            //Invalid STATE
            currentState = S1;
        }
    }
}

void S2(uint8_t k1 ,uint8_t k2 ){
     if(k1&1 ){
        if(k2 & 1){
            currentState = S3;
            COUNTER++;
        }else{
            //Invalid state
        }
    }else{
        if(k2 & 1){
            //Invalid State
            currentState = S2;
        }else{
            currentState = S1;
            COUNTER--;
        }
    }
}
void S3(uint8_t k1 ,uint8_t k2 ){
    if(k1&1 ){
        if(k2 & 1){
            //Invalid state
            currentState = S3;
        }else{
            currentState = S4;
            COUNTER++;
        }
    }else{
        if(k2 & 1){
            currentState = S2;
            COUNTER--;
        }else{
            //iNVALID STATe
        }
    }
}
void S4(uint8_t k1 ,uint8_t k2 ){
    if(k1&1 ){
        if(k2 & 1){
            currentState = S3;
            COUNTER--;
        }else{
            //Invalid state
            currentState = S4;
        }
    }else{
        if(k2 & 1){
            //Invalid State
        }else{
            currentState = S1;
            COUNTER++;
        }
    }
}



int main(void){
    printf_init();

    //Scelgo i pin 10 (B4) (FRANCESCO TOTTI)
    const uint8_t mask1 = (1<<4);
    DDRB &= ~mask1; //setto 4° bit del registro B a 0 (input)
    
    //ora setto il pin 6 (H3)
    const uint8_t mask2 = (1<<3);
    DDRH &= ~mask2; //setto 4° bit del registro B a 0 (input)
    
    //Per scrivere sulla seriale abilito , per i due pin, il pullup resistor.
    PORTB |= mask1;
    PORTH |= mask2;


    
    while(1){
        uint8_t key1 = (PINB&mask1)==0; // se == 0 vuol dire che ho inserito il cavo che fa da ponte e quindi leggo 0.
        uint8_t key2 = (PINH&mask2)==0;
        
        currentState(key1, key2);
        printf("COUNTER %d\n", COUNTER);
        _delay_ms(500); // from delay.h, wait 1 sec
  
    }
    




}