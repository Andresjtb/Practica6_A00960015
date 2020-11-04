#include "device_config.h" 
#include "Practice6.h"
#include <math.h>


void portInit(void){
/**
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB7 = 1;
 **/
    ANSELB = 0;
    ANSELD = 0;
    TRISD = 255; // 11111111b 0xFF
    
}    

void larsonDisplay(void){
    LATB = 1;
    for(int i = 0; i < 8; i++){
        LATB = LATB << 1;
        __delay_ms(DELAY_SWEEP);
    }
     for(int i = 7; i >= 0; i--){
        LATB = LATB >> 1;
        __delay_ms(DELAY_SWEEP);
    }
}

void main(void) {
    portInit();
    while(1){
            //Activar de manera aleatoria un LED utilizando pow() y RAND
        __delay_ms(500);
        // obtener estado de los Pushbuttons
        
        if(PORTB == ~(LATD)){
            larsonDisplay();
        } else{
            __delay_ms(500);
            //Obtener el estatus de los PushButton
            if(PORTB == ~(LATD)){
                //Larso display
            }
        }
    }
    return;
}
