#ifndef SONG_H
#define SONG_H

#define Song const uint8_t PROGMEM

Song music[] = {
0x08,			              // Number of tracks
0x00, 0x00,		          // Address of track 0
0x0F, 0x00,		          // Address of track 1
0x17, 0x00,		          // Address of track 2
0x1A, 0x00,		          // Address of track 3
0x1E, 0x00,		          // Address of track 4
0x25, 0x00,		          // Address of track 5
0x40, 0x00,		          // Address of track 6
0x51, 0x00,		          // Address of track 7

0x00,			              // Channel 0 entry track
0x01,			              // Channel 1 entry track
0x02,			              // Channel 2 entry track
0x03,			              // Channel 3 entry track

//"Track 0 channel 0"
0x9D, 8,                // SET song tempo: value = 8
0x9E, 0, 1, 2, 3,       // FX: GOTO advanced
0x40, 48,               // FX: SET VOLUME: volume = 48
0xFD, 15, 5,             // REPEAT: count = 15 + 1 / track = 5
0x40, 0,                // FX: SET VOLUME: volume = 0
0x9F,                   // FX: STOP CURRENT CHANNEL

//"Track 1 channel 1"
0x40, 48,               // FX: SET VOLUME: volume = 48
0xFD, 63, 6,             // REPEAT: count = 63 + 1 / track = 6
0x40, 0,                // FX: SET VOLUME: volume = 0
0x9F,                   // FX: STOP CURRENT CHANNEL

//"Track 2 channel 2"
0x40, 0,                // FX: SET VOLUME: volume = 0
0x9F,                   // FX: STOP CURRENT CHANNEL

//"Track 3 channel 3"
0xFD, 63, 7,             // REPEAT: count = 63 + 1 / track = 7
0x9F,                   // FX: STOP CURRENT CHANNEL



//"Track 4"
0x40, 32,		     // FX: SET VOLUME: volume = 32
0x41, -16,	     // FX: VOLUME SLIDE ON: steps = -16
0x9F + 2,		     // DELAY: ticks = 2
0x43,			       // FX: VOLUME SLIDE OFF
0xFE,			       // RETURN

//"Track 5"
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 4,		    // DELAY: ticks = 4
0x00 + 25,		  // NOTE ON: note = 25
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 26,		  // NOTE ON: note = 26
0x9F + 2,		    // DELAY: ticks = 2
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 4,		    // DELAY: ticks = 4
0x00 + 29,		  // NOTE ON: note = 29
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 30,		  // NOTE ON: note = 30
0x9F + 2,		    // DELAY: ticks = 2
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 4,		    // DELAY: ticks = 4
0x00 + 32,		  // NOTE ON: note = 32
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 33,		  // NOTE ON: note = 33
0x9F + 2,		    // DELAY: ticks = 2
0x00 + 0,       // NOTE ON: note = 0
0x9F + 8,       // DELAY: ticks = 8
0xFE,			      // RETURN

//"Track 6"
0x00 + 8,		    // NOTE ON: note = 8
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 10,		  // NOTE ON: note = 10
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 8,		    // NOTE ON: note = 8
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 10,		  // NOTE ON: note = 10
0x9F + 1,		    // DELAY: ticks = 1
0x00 + 0,		    // NOTE ON: note = 0
0x9F + 1,		    // DELAY: ticks = 1
0xFE,			      // RETURN

//"Track 7"
0x9F + 2,		    // DELAY: ticks = 2
0xFC, 4,		    // GOTO track 0
0x9F + 4,		    // DELAY: ticks = 4
0xFE,			      // RETURN

};



#endif
