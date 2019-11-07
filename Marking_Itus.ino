// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

// Set up lots of global variables that we'll be using
InternetButton b = InternetButton();

// float ledPos = 1;
// float ledDesired = 3;
// uint8_t buttonAll = 0;
// uint8_t ledPosAchieved = 0;

// void ledControl(int ledn);
int rainbowRemote(String command);

void setup() {
    b.begin();

    // Particle.function("controlLed", ledControl);
    // Particle.function("animateSmile", smileAnimate);
    Particle.function("rainbow", rainbowRemote);

}

void loop() {

}

// void ledControl(int ledn){
//     b.ledOn(ledn,60,60,60);
//     delay(200);
//     ledDesired = ledn;
//     if(ledPos < ledDesired){ledDesired++;}
//     else{ledDesired--;}
//     ledPosAchieved = 0;
// }

// int smileAnimate(String command){
    
// }

int rainbowRemote(String command){
    char inputStr[10];
    command.toCharArray(inputStr,10);
    uint32_t i = atoi(inputStr);
    uint32_t startMillis = millis();
    while(millis() - startMillis < i*1000UL){
        // b.advanceRainbow(10,30);
         b.ledOn(1,200,200,200);
         b.ledOn(3,200,200,200);
         b.ledOn(4,200,200,200);
         b.ledOn(5,200,200,200);
         b.ledOn(6,200,200,200);
         b.ledOn(7,200,200,200);
         b.ledOn(8,200,200,200);
         b.ledOn(9,200,200,200);
        Particle.process();
    }
    b.allLedsOff();
    return 1;
}
