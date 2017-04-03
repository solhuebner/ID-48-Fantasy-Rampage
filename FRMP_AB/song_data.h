#ifndef SONG_H
#define SONG_H

#define Song const uint8_t PROGMEM

Song music[] = {
0x09,			// Number of tracks
0x00, 0x00,		// Address of track 0
0x07, 0x00,		// Address of track 1
0x20, 0x00,		// Address of track 2
0x31, 0x00,		// Address of track 3
0x34, 0x00,		// Address of track 4
0x39, 0x00,		// Address of track 5
0x44, 0x00,		// Address of track 6
0x4c, 0x00,		// Address of track 7
0x4f, 0x00,		// Address of track 8
0x05,			// Channel 0 entry track
0x06,			// Channel 1 entry track
0x07,			// Channel 2 entry track
0x08,			// Channel 3 entry track
//"Track snare"
0x40, 32,		// FX: SET VOLUME: volume = 32
0x41, -16,		// FX: VOLUME SLIDE ON: steps = -16
0x9F + 2,		// DELAY: ticks = 2
0x43,			// FX: VOLUME SLIDE OFF
0xFE,			// RETURN
//"Track Track 1"
0x00 + 0,		// NOTE ON: note = 0
0x9F + 4,		// DELAY: ticks = 4
0x00 + 25,		// NOTE ON: note = 25
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 26,		// NOTE ON: note = 26
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 4,		// DELAY: ticks = 4
0x00 + 29,		// NOTE ON: note = 29
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 30,		// NOTE ON: note = 30
0x9F + 2,		// DELAY: ticks = 2
0x00 + 0,		// NOTE ON: note = 0
0x9F + 4,		// DELAY: ticks = 4
0x00 + 32,		// NOTE ON: note = 32
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 33,		// NOTE ON: note = 33
0x9F + 2,		// DELAY: ticks = 2
0xFE,			// RETURN
//"Track Track 3"
0x00 + 8,		// NOTE ON: note = 8
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 10,		// NOTE ON: note = 10
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 8,		// NOTE ON: note = 8
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0x00 + 10,		// NOTE ON: note = 10
0x9F + 1,		// DELAY: ticks = 1
0x00 + 0,		// NOTE ON: note = 0
0x9F + 1,		// DELAY: ticks = 1
0xFE,			// RETURN
//"Track Track 4"
0x00 + 0,		// NOTE ON: note = 0
0x9F + 8,		// DELAY: ticks = 8
0xFE,			// RETURN
//"Track Track 6"
0x9F + 2,		// DELAY: ticks = 2
0xFC, 0,		// GOTO track 0
0x9F + 4,		// DELAY: ticks = 4
0xFE,			// RETURN
//"Track channel 0"
0x9D, 8,		// SET song tempo: value = 8
0x40, 48,		// FX: SET VOLUME: volume = 48
0xFC, 1,		// GOTO track 1
0xFC, 3,		// GOTO track 3
0x40, 0,		// FX: SET VOLUME: volume = 0
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 1"
0x40, 48,		// FX: SET VOLUME: volume = 48
0xFD, 3, 2,		// REPEAT: count = 3 + 1 / track = 2
0x40, 0,		// FX: SET VOLUME: volume = 0
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 2"
0x40, 0,		// FX: SET VOLUME: volume = 0
0x9F,			// FX: STOP CURRENT CHANNEL
//"Track channel 3"
0x40, 0,		// FX: SET VOLUME: volume = 0
0xFD, 3, 4,		// REPEAT: count = 3 + 1 / track = 4
0x40, 0,		// FX: SET VOLUME: volume = 0
0x9F,			// FX: STOP CURRENT CHANNEL

};



#endif
