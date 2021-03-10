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
    int cont = 0;
    
    
    disp7seg_init();
    
    while( 1 )
    {
        disp7seg( cont );
        if( botao_Up() == 1)
        {
            cont++;
            if (cont > 15)
                cont = 0;
            while ( botao_Up() == 1)
            {
              disp7seg( cont );  
            }
        }
        if( botao_Down() == 1)
        {
            cont--;
            if (cont < 0)
                cont = 15;
            while ( botao_Down() == 1)
            {
              disp7seg( cont );  
            }
        }
    }
    return;
}
