
// Solder closed jumper on bottom!
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_FeatherOLED.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306();

#define VS1053_MIDI Serial1

// See http://www.vlsi.fi/fileadmin/datasheets/vs1053.pdf Pg 31
#define VS1053_BANK_DEFAULT 0x00
#define VS1053_BANK_DRUMS1 0x78
#define VS1053_BANK_DRUMS2 0x7F
#define VS1053_BANK_MELODY 0x79

// See http://www.vlsi.fi/fileadmin/datasheets/vs1053.pdf Pg 32 for more!
#define VS1053_GM1_OCARINA 80

#define MIDI_NOTE_ON  0x90
#define MIDI_NOTE_OFF 0x80
#define MIDI_CHAN_MSG 0xB0
#define MIDI_CHAN_BANK 0x00
#define MIDI_CHAN_VOLUME 0x07
#define MIDI_CHAN_PROGRAM 0xC0

typedef struct mySoundGesture {
  const uint8_t bank;
  const uint8_t instrument;
  const uint8_t volume;
  bool loop;
  uint8_t voices;
  uint8_t len;
  uint8_t* notes;
  uint8_t* durations;
} SoundGesture ;

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.begin(31250);

  Serial.println("OLED FeatherWing test");
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  Serial.println("OLED begun");
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  oled.display();
  delay(1000);
    // Clear the buffer.
  oled.clearDisplay();
  oled.display();
  oled.setTextSize(1);
  oled.setTextColor(WHITE, BLACK);
  oled.setCursor(0,0);

  Serial.println("VS1053 MIDI test");
  VS1053_MIDI.begin(31250); // MIDI uses a 'strange baud rate'
  //midiSetChannelBank(0, VS1053_BANK_MELODY);
  //midiSetChannelVolume(0, 127);
  //midiSetInstrument(0, VS1053_GM1_OCARINA);
}

//Basic creepy scale
uint8_t scale_notes[8] = {64, 0, 68, 70, 72, 74, 76, 78};
uint8_t scale_durations[8] = {50, 50, 50, 50, 50, 50, 50, 50};
SoundGesture basicScale = {
  VS1053_BANK_MELODY,
  53,
  127,
  true,
  1,
  8,
  scale_notes,
  scale_durations
};

//Chord 1: Bflat = 70, G = 67, Eflat = 63
//Chord 2: F = 65, D = 62, Bflat = 70?
//Chord 3: G = 67, Eflat = 63, C = 60
//Chord 4:F = 65, D = 62, Bflat = 58
uint8_t angel_notes[12] = {70, 70, 67, 65,  //Voice 1
                           67, 65, 63, 62,  //Voice 2
                           63, 62, 60, 58}; //Voice 3
uint8_t angel_durations[4] = {100, 100, 100, 100};
SoundGesture angelSound = {
  VS1053_BANK_MELODY,
  54,                           //Instrument = Voice Oohs
  127,                          //Volume = 127
  true,                         //Loop
  3,                            //3 voices total
  4,                            //4 notes per voice
  angel_notes,
  angel_durations
};


//Notes: Bb Ab Bb G Bb F Bb Eb
uint8_t twinkle_notes[8] = {82, 80, 82, 79, 82, 77, 82, 75};
uint8_t twinkle_durations[8] = {15, 15, 15, 15, 15, 15, 15, 15};
SoundGesture twinkleSound = {
  VS1053_BANK_MELODY,           //Bank for Melody
  9,                          //Instument = ?
  127,                          //Volume = 120
  true,                         //Loop
  1,                            //1 Voice
  8,                            //8 Notes
  twinkle_notes,
  twinkle_durations
};

uint8_t temple_notes[16] = {50, 55, 60, 65, 50, 55, 60, 65, 
                    65, 60, 55, 50, 65, 60, 55, 50};
uint8_t temple_durations[4] = {100, 100, 100, 100};
SoundGesture templeSound = {
  VS1053_BANK_MELODY,
  113,
  127,
  true,
  4,
  4,
  temple_notes,
  temple_durations
};

uint8_t bird_notes[8] = {55, 60, 65, 70, 55, 60, 65, 70};
uint8_t bird_durations[8] = {10, 15, 20, 25, 10, 15, 20, 25};
SoundGesture birdSound = {
  VS1053_BANK_MELODY,
  124,
  127,
  true,
  1,
  8,
  bird_notes,
  bird_durations
};


uint8_t sea_notes[12] = {50, 52, 54, 56, 
                        52, 54, 56, 58,
                        54, 56, 58, 60};
uint8_t sea_durations[2] = {200, 200};
SoundGesture seaSound = {
  VS1053_BANK_MELODY,
  123,
  127,
  true,
  3,
  4,
  sea_notes,
  sea_durations
};

void loop() {  
  oled.clearDisplay(); 
  oled.print("\rSound 1"); oled.display();
  oled.display();
  playSounds(&angelSound);
  delay(1000);
  
  oled.clearDisplay(); oled.setCursor(0,0);
  oled.print("\rSound 2"); oled.display();
  playSounds(&twinkleSound);
  delay(1000);

  oled.clearDisplay(); oled.setCursor(0,0);
  oled.print("\rSound 3"); oled.display();
  playSounds(&templeSound);
  delay(1000);

  oled.clearDisplay(); oled.setCursor(0,0);
  oled.print("\rSound 4"); oled.display();
  playSounds(&birdSound);
  delay(1000);

  oled.clearDisplay(); oled.setCursor(0,0);
  oled.print("\rSound 5"); oled.display();
  playSounds(&seaSound);
  delay(1000);
  
  oled.clearDisplay(); oled.setCursor(0,0);
}

void playSounds(SoundGesture* gesture) {
//1 half note is about 1 second

  for(int i=0; i<gesture->voices; i++) {
    midiSetChannelBank(i,gesture->bank);
    midiSetInstrument(i,gesture->instrument);
    midiSetChannelVolume(i,gesture->volume);
  }
     
  for (int i=0; i < gesture->len; i++) { //loop through the "len" notes

    //Turn on the i'th note of every voice
    for (int j = 0; j < gesture->voices; j++) { 
      midiNoteOn(j,gesture->notes[i + j * gesture->len],gesture->volume);
    }

    //Delay
    delay(gesture->durations[i] * 20);

    //Turn of the i'th note of every voice
    for (int j = 0; j < gesture->voices; j++) {
      midiNoteOff(j,gesture->notes[i + j * gesture->len],gesture->volume);
    } 
  }
      
    
}

void midiSetInstrument(uint8_t chan, uint8_t inst) {
  if (chan > 15) return;
  inst --; // page 32 has instruments starting with 1 not 0 :(
  if (inst > 127) return;
  
  VS1053_MIDI.write(MIDI_CHAN_PROGRAM | chan);  
  delay(10);
  VS1053_MIDI.write(inst);
  delay(10);
}


void midiSetChannelVolume(uint8_t chan, uint8_t vol) {
  if (chan > 15) return;
  if (vol > 127) return;
  
  VS1053_MIDI.write(MIDI_CHAN_MSG | chan);
  VS1053_MIDI.write(MIDI_CHAN_VOLUME);
  VS1053_MIDI.write(vol);
}

void midiSetChannelBank(uint8_t chan, uint8_t bank) {
  if (chan > 15) return;
  if (bank > 127) return;
  
  VS1053_MIDI.write(MIDI_CHAN_MSG | chan);
  VS1053_MIDI.write((uint8_t)MIDI_CHAN_BANK);
  VS1053_MIDI.write(bank);
}

void midiNoteOn(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;
  
  VS1053_MIDI.write(MIDI_NOTE_ON | chan);
  VS1053_MIDI.write(n);
  VS1053_MIDI.write(vel);
}

void midiNoteOff(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;
  
  VS1053_MIDI.write(MIDI_NOTE_OFF | chan);
  VS1053_MIDI.write(n);
  VS1053_MIDI.write(vel);
}
