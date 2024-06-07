/*
  Modified tone example, orginal:
  created 8 Mar 2010
  by Tom Igoe
  based on a snippet from Greg Borenstein

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone4

  But I have updated it quite a bit, really a lot. But the original above is useful.
  Brett Stalbaum

  ////////////////////////////////////////////////////////////////////////////////
  Jinying Xie 06/02/2024

  I arrange everything to fit my song's need, including changing the notes, adding
  duration, and creating new function.

  Music note is transcribed from: 
  https://www.bilibili.com/video/BV1V84y1t7qq/

  eMajor frequency is from:
  https://blog.csdn.net/wzf28/article/details/54348743

*/


// Initialize tones (very accurate)
const unsigned int eMajor[] = {
          // E major scale notes (A4 octave)
          329.63, // E
          369.99, // F#
          415.3, // G#
          440, // A
          493.88, // B
          554.37, // C#
          587.33, // D#

          // E major scale notes (A5 octave)
          659.26, // E5 (one octave higher)
          739.99, // F#5
          830.61, // G#5
          880, // A5
          987.77, // B5
          1108.7, // C#5
          1244.5, // D#5

          // E major scale notes (A6 octave)
          1318.5  // E6
};


// Initialize melody
const unsigned int Matsuri[] {
  987.77,	0,	1108.7,	0,	659.26,	0,	739.99,	0,
  329.63,	0,	554.37,	0,	659.26,	0,	739.99,	0,
  329.63,	0,	739.99,	0,	739.99,	739.99,	0,	739.99,
  739.99,	0,	830.61,	0,	739.99,	0,	659.26,	0,
  554.37,	0,	493.88,	0,	554.37,	0,	659.26,	0,
  739.99,	0,	329.63,	0,	554.37,	0,	659.26,	0,
  739.99,	0,	587.33,	0,	0,	739.99,	0,	739.99,
  739.99,	0,	739.99,	739.99,	0,	739.99,	987.77,	880,
  880,	830.61,	739.99,	659.26,	0,	830.61,	0,	415.3,
};

// Initialize melody's duration (1/2)
// const unsigned int duration[]{
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
//   500,	500,	500,	500,	500,	500,	500,	500,
// };

// Initialize melody's duration (1/8)
// const unsigned int duration[]{
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
//   125,	125,	125,	125,	125,	125,	125,	125,
// };

// Initialize melody's duration (1/6)
const unsigned int duration[]{
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
  167,	167,	167,	167,	167,	167,	167,	167,
};



// Pin for the speaker
const int speakerPin = 9;

// Variable to keep track of note index
int noteIndex = 0;


// Set up
void setup() {
  // turn on serial communication between the arduion and the arduino ide 
  // (really your computer) over USB.
  Serial.begin(9600);
  
  // Set speaker pin as output
  pinMode(speakerPin, OUTPUT);
}


// Loop
void loop() {
  // Play the current note at the specified frequency and duration
  tone(speakerPin, Matsuri[noteIndex], duration[noteIndex]);
  delay(duration[noteIndex]);

  // Stop playing the note after the duration
  noTone(speakerPin);

  // Print debug message (optional)
  Serial.print("Playing note: ");
  Serial.print(Matsuri[noteIndex]);
  Serial.print(" for ");
  Serial.print(duration[noteIndex]);
  Serial.println(" ms");

  // Increment note index for the next iteration
  noteIndex++;

  // Check if reached the end of the melody and durations
  if (noteIndex >= sizeof(Matsuri) / sizeof(Matsuri[0])) {
    noteIndex = 0; // Reset index to loop the melody
  }

}
