/*
 * bai1.c
 * Project -> Configure -> C Compiler -> Libraries -> Alphanumeric LCD(alcd.h)  -> Enable ...
 * RS|PORTA|0
 * RD|PORTA|1
 * EN|PORTA|2
 * D4|PORTA|3
 * D5|PORTA|4
 * D6|PORTA|5
 * D7|PORTA|6
 * Created: 11/18/2020 8:28:53 AM
 * Author: dungpb
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdio.h>

#define CT1 PINB.2
#define CT2 PINB.3
#define CT3 PINB.0

char s[12] = "hello-world";

int pos = 0, index = 0;

void main(void)
{
DDRB = 0x00;
PORTB = 0xff;
DDRD.7 = 1;
PORTD.7 = 1;
lcd_init(16);
lcd_clear(); 
while (1)
    {      
        if (CT1 == 0){
            delay_ms(250);      
            index = 0;
            for (index = 0; index < 11; index++){
                for (pos = 0; pos < 16 - index; pos++){    
                    lcd_gotoxy(pos - 1, 0);
                    lcd_puts(" ");    
                    lcd_gotoxy(pos, 0); 
                    lcd_putchar(s[10 - index]);        
                    delay_ms(100);
                }        
            }
        } 
        
        if (CT2 == 0){
            delay_ms(250);      
            index = 0;
            for (index = 0; index < 11; index++){
                for (pos = 0; pos < 16 - index; pos++){    
                    lcd_gotoxy(15 - pos + 1, 0);
                    lcd_puts(" ");    
                    lcd_gotoxy(15 - pos, 0); 
                    lcd_putchar(s[index]);        
                    delay_ms(100);
                }        
            }
        }  
        
        if (CT3 == 0){
           lcd_clear(); 
        }  
    }
}
