#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SerialFlash.h>

// Create a Reverb object
AudioEffectReverb reverb;

// Connect audio processing blocks to the inputs and outputs
AudioInputI2S i2sin;
AudioOutputI2S i2sout;
AudioConnection c1(i2sin, 0, reverb, 0);
AudioConnection c2(reverb, 0, i2sout, 0);

// Pin for the potensiometer
const int potPin = A0;

void setup() {
  // Start the audio library
  AudioMemory(120);
  reverb.setSampleRate(AUDIO_SAMPLE_RATE_EXACT);
  reverb.roomsize(0.5);
  reverb.damping(0.5);
  reverb.width(0.5);
}

void loop() {
  // Read the value of the potensiometer
  int potValue = analogRead(potPin);
  
  // Map the pot value to a range of 0 to 1
  float wetValue = map(potValue, 0, 1023, 0, 1);
  
  // Set the wet value on the reverb object
  reverb.wet(wetValue);
}
