#include <reg51.h>

sbit led1 = P1^1;
sbit led2 = P1^2;
sbit led3 = P1^3;
sbit led4 = P1^4;

sbit ip = P2^3;

sbit op = P2^6;



int mode = 0;
int run = 0;
int count = 0;
int alt = 0;
int flash = 0;

void delay(){
    int i, j;

    for(i=0;i<100;i++)
        for(j=0;j<350;j++);
}


void chk_button(){
    ip = 0; 

    if(op == 0){
        delay();

        if(op == 0){
            ++mode;

            if(mode > 4)
                mode = 1;

            while(op == 0);
            delay();
        }
    }

    ip = 1;
}


void led_run(){
    led1 = led2 = led3 = led4 = 0;

    switch(run){
        case 0:
            led1 = 1;
            break;

        case 1:
            led2 = 1;
            break;

        case 2:
            led3 = 1;
            break;

        case 3:
            led4 = 1;
            break;
    }

    delay();

    ++run;

    if(run > 3)
        run = 0;
}


void led_bin(){
    int temp;

    temp = count;

    led4 = temp%2;
    temp /= 2;
		
		led3 = temp%2;
    temp /= 2;
		
		led2 = temp%2;
    temp /= 2;
		
		led1 = temp%2;
		
    delay();

    ++count;

    if(count > 15)
        count = 0;
}



void led_alt(){
    if(alt == 0){
        led1 = led3 = 1;
        led2 = led4 = 0;
    }
    else {
        led1 = led3 = 0;
        led2 = led4 = 1;
    }

    delay();
		
    alt = !alt;
}


void led_flash(){
    if(flash == 0)
        led1 = led2 = led3 = led4 = 1;
    else
			  led1 = led2 = led3 = led4 = 0;

    delay();

    flash = !flash;
}

void main(){
    while(1)    {
        chk_button();

        switch(mode){
            case 1:
                led_run();
                break;

            case 2:
                led_bin();
                break;

            case 3:
                led_alt();
                break;

            case 4:
                led_flash();
                break;

            default: led1 = led2 = led3 = led4 = 0;
                break;
        }
    }
}