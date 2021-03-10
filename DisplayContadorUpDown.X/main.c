/*
 * File:   main.c
 * Author: 19179172
 *
 * Created on 25 de Fevereiro de 2021, 14:52
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "disp7seg.h"

void main(void) 
{
    char estado = 0;
    char contador = 0;
    disp7seg_init();
    while(1)
    {
        switch(estado)
        {
            case 0:
                    estado = 1;
                    break;
            case 1:
                    if( botao_Up() )
                    estado = 90;
                    if( botao_Down() )
                    estado = 100;
                    break;
            case 90:
//                  ++contador;
//                  if(contador > 15)
//                  contador = 0;
                    contador = ++contador % 16;
                    disp7seg ( contador );
                    estado = 255;
                    break;
            case 255:
                    if( !botao_Up() )
                    estado = 1;
                    break;
            case 100:
//                  if(contador <= 0)
//                  contador = 15;
//                  else
//                  --contador;
                    contador = --contador % 16;
                    disp7seg(contador);
                    estado = 150;
                    break;
            case 150:
                    if( !botao_Down() )
                    estado = 1;
                    break;
        }
    }
}
