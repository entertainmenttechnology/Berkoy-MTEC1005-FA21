/*
  /*
  PIEZO PITCH FOLLOWER

  Example using tone() and anolog input to change pitch.
  
  Create piezo circuit with one side connected to digital pin 2 and other side connected to ground.
  Create circuit for analog sensor, receiving data from analog pin A0.

  Arguments for tone= pin #, frequency in Hz, and duration of the tone in milliseconds:
  tone (pin, frequency, duration)

  Recommended to use frequencies 30-5,000 Hz.

  Modified from example code in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone2
*/

// Creates global variables
const int piezo = 2; // piezo pin
int sensorReading; //to track sensor input
int pitch;  // to track pitch

void setup() {
  // initialize serial communications (for debugging only):
  //Serial.begin(9600);
}

void loop() {

  sensorReading = analogRead(A0);    // read the sensor:

  //Serial.println(sensorReading);    // print the sensor reading so you know its range

  // use map() of analog input range (0-1023 from the FSR)
  // to the output pitch range (120 - 3000Hz)

  pitch = map(sensorReading, 0, 1023, 120, 3000);

  tone(piezo, pitch, 10);  // plays pitch
  delay(1);        // delay in between reads for stability
}
