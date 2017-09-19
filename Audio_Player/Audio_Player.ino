/* To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. */

#define CUSTOM_SETTINGS
#define INCLUDE_MUSIC_PLAYER_SHIELD
#define INCLUDE_TOGGLE_BUTTON_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

const int trigpin = 2;
const int echopin = 4;

long distance_cm, cm, duration;

void setup(){
  
   /* Start communication. */
  OneSheeld.begin();
  
  pinMode(trigpin,INPUT);
  pinMode(echopin,OUTPUT);
}

void loop(){
  
  if(ToggleButton.getStatus()){
    
    /* Turn on the music. */
       MusicPlayer.play(); 
  }
  
  else {
    MusicPlayer.pause();
  }
  
  distance_cm = ultrasonic();
   /* Set the volume. */
       MusicPlayer.setVolume(map(distance_cm,2,30,0,10));
}

long ultrasonic(){
  
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  duration = pulseIn(echopin,HIGH); 
  
  cm = duration / 29 / 2;
  
  return cm;
  
}
