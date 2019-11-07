// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

// Set up lots of global variables that we'll be using
InternetButton b = InternetButton();


int rainbowRemote(String command);

void setup() {
    b.begin();

    
    Particle.function("rainbow", rainbowRemote);

}

void loop() {

}



int rainbowRemote(String command){
    int s;
    char inputStr[10];
    command.toCharArray(inputStr,10);
    uint32_t i = atoi(inputStr);
    uint32_t startMillis = millis();
    if(s == (millis() - stratMillis < i*1000UL)
    while(s < i*1000UL) {
        // b.advanceRainbow(10,30);
        if(millis() - startMillis == 5){
         b.ledOn(1,200,200,200);
         b.ledOn(12,200,200,200);
         b.ledOn(4,200,200,200);
         b.ledOn(5,200,200,200);
         b.ledOn(6,200,200,200);
         b.ledOn(7,200,200,200);
         b.ledOn(8,200,200,200);
        Particle.process();
        }
        
        if(millis() - startMillis == 10){
         b.ledOn(1,200,200,200);
         b.ledOn(12,200,200,200);
         
         b.ledOn(5,200,200,200);
         b.ledOn(6,200,200,200);
         b.ledOn(7,200,200,200);
        
        Particle.process();
        
        }
        
        if(millis() - startMillis == 15){
         b.ledOn(1,200,60,60);
         b.ledOn(12,200,60,60);
        
         b.ledOn(6,255,60,60);
         
        Particle.process();
        
        }
        
        if(millis() - startMillis == 19){
         b.ledOn(1,255,0,0);
         b.ledOn(12,255,0,0);
        
         b.ledOn(6,255,0,0);
         
        Particle.process();
        
        }
        
        if(millis() - startMillis == 20){
         b.allLedsOn(255,0,0);
        
        Particle.process();
        
        }
        
        // else{
        //     b.allLedsOn(0,0,0);
        
        // }
        
    }
    b.allLedsOff();
    return 1;
}


