#include "mbed.h"
#include "ultrasonic.h"

//Serial pc(USBTX,USBRX);
DigitalOut led1(LED1);
int currentDistance;
int newDistance;

void dist(int distance)
{
    if (distance < 300)
    {
        for (int i = 0; i < 5; i++)
        {
            led1 = true;
            wait(.1);
            led1 = false;
            wait(.1);
        }
    }
    else if (distance < 1000)
    {
        for (int i = 0; i < 2; i++)
        {
            led1 = true;
            wait(.25);
            led1 = false;
            wait(.25);
        }
    }
    else
    {
        led1 = true;
        wait(1);
        led1 = false;
        
    } 
    
}

ultrasonic mu(p10,p11,.1,1,&dist);

int main()
{
    led1 = false;
    mu.startUpdates();
    while(1)
    {
        mu.checkDistance();
    }
}