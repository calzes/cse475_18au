
// Solder closed jumper on bottom!
#include <Adafruit_FeatherOLED.h>
Adafruit_FeatherOLED oled = Adafruit_FeatherOLED();

#define ARDUINO_SAMD_FEATHER_M0

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
  uint8_t len;
  uint8_t* notes;
  uint8_t* durations;
} SoundGesture ;


#if defined(__AVR_ATmega32U4__) || defined(ARDUINO_SAMD_FEATHER_M0) || defined(TEENSYDUINO) || defined(ARDUINO_STM32_FEATHER)
  #define VS1053_MIDI Serial1
#elif defined(ESP32)
  HardwareSerial Serial1(2);
  #define VS1053_MIDI Serial1
#elif defined(ESP8266)
  #define VS1053_MIDI Serial
#endif

void setup() {
  delay(1000);
  
  Serial.begin(115200);

  oled.init();

  Serial.println("VS1053 MIDI test");

  VS1053_MIDI.begin(31250); // MIDI uses a 'strange baud rate'
  
  midiSetChannelBank(0, VS1053_BANK_MELODY);

  midiSetChannelVolume(0, 127);

  midiSetInstrument(0, VS1053_GM1_OCARINA);
}

//Basic creepy scale
uint8_t scale_notes[8] = {64, 0, 68, 70, 72, 74, 76, 78};
uint8_t scale_durations[8] = {50, 50, 50, 50, 50, 50, 50, 50};
SoundGesture basicScale = {
  VS1053_BANK_MELODY,
  43,
  127,
  true,
  8,
  scale_notes,
  scale_durations
};

uint8_t randomsound_notes[8] = {64, 66, 68, 70, 72, 74, 76, 78};
uint8_t randomsound_durations[8] = {50, 50, 50, 50, 50, 50, 50, 50};
SoundGesture randomSound = {
  VS1053_BANK_MELODY,
  43,
  127,
  true,
  8,
  scale_notes,
  scale_durations
};


void loop() {  
  oled.clearDisplay();
  oled.print("Sound 1");
  oled.display();
  playSounds(&basicScale);
  delay(1000);
}

void playSounds(SoundGesture* gesture) {
//1 half note is about 1 second
  midiSetChannelBank(0,gesture->bank);
  midiSetInstrument(0,gesture->instrument);
  midiSetChannelVolume(0,gesture->volume);

    midiSetChannelBank(1,gesture->bank);
  midiSetInstrument(1,gesture->instrument);
  midiSetChannelVolume(1,gesture->volume);

    midiSetChannelBank(2,gesture->bank);
  midiSetInstrument(2,gesture->instrument);
  midiSetChannelVolume(2,gesture->volume);
     
  for (int i=0; i<gesture->len; i++) {
    midiNoteOn(1,gesture->notes[0],gesture->volume);
    midiNoteOn(0,gesture->notes[i],gesture->volume);
    midiNoteOn(2,gesture->notes[2],gesture->volume);
    delay(gesture->durations[i] * 20);
    midiNoteOff(1,gesture->notes[0],gesture->volume);
    midiNoteOff(0,gesture->notes[i],gesture->volume);
    midiNoteOn(2,gesture->notes[2],gesture->volume);
    delay(20);
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
