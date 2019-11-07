// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

// Set up lots of global variables that we'll be using
InternetButton b = InternetButton();

uint32_t startMillis = millis();

int rainbowRemote(String command);
// void smileAnimate1();

void setup() {
    b.begin();

    
    // Particle.function("rainbow", rainbowRemote);
    // Particle.function("animate1", smileAnimate1);
    // Particle.function("animate2", smileAnimate2);
    // Particle.function("animate3", smileAnimate3);
    // Particle.function("animate4", smileAnimate4);
    // Particle.function("animate5", smileAnimate5);

}

void loop() {

}

void smileAnimate1(){
    
    
}

int rainbowRemote(String command){
    
    char inputStr[10];
    command.toCharArray(inputStr,10);
    uint32_t i = atoi(inputStr);
    uint32_t startMillis = millis();
    // int s = (millis() - stratMillis < i*1000UL)
    while(millis() - startMillis < i*1000UL){
    // if(s == (millis() - stratMillis < i*1000UL)){

        // b.advanceRainbow(10,30);
        if(i == 5){
         b.ledOn(1,200,200,200);
         b.ledOn(12,200,200,200);
         b.ledOn(4,200,200,200);
         b.ledOn(5,200,200,200);
         b.ledOn(6,200,200,200);
         b.ledOn(7,200,200,200);
         b.ledOn(8,200,200,200);
        Particle.process();
        }
        
        if(i == 10){
         b.ledOn(1,200,200,200);
         b.ledOn(12,200,200,200);
         
         b.ledOn(5,200,200,200);
         b.ledOn(6,200,200,200);
         b.ledOn(7,200,200,200);
        
        Particle.process();
        
        }
        
        if(i == 15){
         b.ledOn(1,200,60,60);
         b.ledOn(12,200,60,60);
        
         b.ledOn(6,255,60,60);
         
        Particle.process();
        
        }
        
        if(i == 19){
         b.ledOn(1,255,0,0);
         b.ledOn(12,255,0,0);
        
         b.ledOn(6,255,0,0);
         
        Particle.process();
        
        }
        
        if(i == 20){
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
    


