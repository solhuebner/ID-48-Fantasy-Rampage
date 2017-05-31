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

Song victory[] = {
  0x08,      // Number of tracks
  0x00, 0x00,   // Address of track 0
  0x03, 0x00,   // Address of track 1
  0x0f, 0x00,   // Address of track 2
  0x1b, 0x00,   // Address of track 3
  0x1c, 0x00,   // Address of track 4
  0x31, 0x00,   // Address of track 5
  0x34, 0x00,   // Address of track 6
  0x3d, 0x00,   // Address of track 7
  0x00,     // Channel 0 entry track
  0x01,     // Channel 1 entry track
  0x02,     // Channel 2 entry track
  0x03,     // Channel 3 entry track
  //"Track channel 0"
  0x9D, 24,   // FX: SET TEMPO: tempo = 24
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track channel 1"
  0x40, 48,   // FX: SET VOLUME: volume = 48
  0x41, -1,   // FX: SLIDE VOLUME ON: -1
  0x50, 4, 1,   // FX: SET VIBRATO: 4 1
  0x54, 3,    // FX: SET NOTE CUT: 3
  0xFC, 5,    // GOTO track 5
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track channel 2"
  0x40, 48,   // FX: SET VOLUME: volume = 48
  0x41, -1,   // FX: SLIDE VOLUME ON: -1
  0x4E, 6, 1,   // FX: SET TREMOLO: 6 1
  0x40, 24,   // FX: SET VOLUME: volume = 24
  0xFC, 4,    // GOTO track 4
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track channel 3"
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track Track 1"
  0x00 + 42,    // NOTE ON: note = 42
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 42,    // NOTE ON: note = 42
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 49,    // NOTE ON: note = 49
  0x9F + 20,    // DELAY: ticks = 20
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 49,    // NOTE ON: note = 49
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 56,    // NOTE ON: note = 56
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 54,    // NOTE ON: note = 54
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 52,    // NOTE ON: note = 52
  0x9F + 4,   // DELAY: ticks = 4
  0x00 + 54,    // NOTE ON: note = 54
  0x9F + 12,    // DELAY: ticks = 12
  0xFE,     // RETURN
  //"Track Track 2"
  0x00 + 6,   // NOTE ON: note = 6
  0x9F + 64,    // DELAY: ticks = 64
  0xFE,     // RETURN
  //"Track Track 4"
  0x00 + 6,   // NOTE ON: note = 6
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 1,   // DELAY: ticks = 1
  0x00 + 6,   // NOTE ON: note = 6
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 1,   // DELAY: ticks = 1
  0xFE,     // RETURN
  //"Track Track 5"
  0x00 + 6,   // NOTE ON: note = 6
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 1,   // DELAY: ticks = 1
  0xFE,     // RETURN
};


Song lost[] = {
  0x0a,      // Number of tracks
  0x00, 0x00,   // Address of track 0
  0x0d, 0x00,   // Address of track 1
  0x14, 0x00,   // Address of track 2
  0x15, 0x00,   // Address of track 3
  0x1e, 0x00,   // Address of track 4
  0x25, 0x00,   // Address of track 5
  0x2a, 0x00,   // Address of track 6
  0x3f, 0x00,   // Address of track 7
  0x42, 0x00,   // Address of track 8
  0x44, 0x00,   // Address of track 9
  0x00,     // Channel 0 entry track
  0x01,     // Channel 1 entry track
  0x02,     // Channel 2 entry track
  0x03,     // Channel 3 entry track
  //"Track channel 0"
  0x40, 0,    // FX: SET VOLUME: volume = 0
  0x9D, 25,   // FX: SET TEMPO: tempo = 25
  0xFC, 7,    // GOTO track 7
  0x40, 48,   // FX: SET VOLUME: volume = 48
  0x41, -12,    // FX: SLIDE VOLUME ON: -12
  0xFC, 6,    // GOTO track 6
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track channel 1"
  0x40, 48,   // FX: SET VOLUME: volume = 48
  0x41, -2,   // FX: SLIDE VOLUME ON: -2
  0xFC, 5,    // GOTO track 5
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track channel 2"
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track channel 3"
  0x40, 0,    // FX: SET VOLUME: volume = 0
  0xFC, 8,    // GOTO track 8
  0x40, 48,   // FX: SET VOLUME: volume = 48
  0xFC, 9,    // GOTO track 9
  0x9F,     // FX: STOP CURRENT CHANNEL
  //"Track snare"
  0x40, 32,   // FX: SET VOLUME: volume = 32
  0x41, -16,    // FX: VOLUME SLIDE ON: steps = -16
  0x9F + 2,   // DELAY: ticks = 2
  0x43,     // FX: VOLUME SLIDE OFF
  0xFE,     // RETURN
  //"Track Track 1"
  0x00 + 18,    // NOTE ON: note = 18
  0x9F + 24,    // DELAY: ticks = 24
  0x00 + 15,    // NOTE ON: note = 15
  0x9F + 24,    // DELAY: ticks = 24
  0xFE,     // RETURN
  //"Track Track 2"
  0x00 + 13,    // NOTE ON: note = 13
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 1,   // DELAY: ticks = 1
  0x00 + 13,    // NOTE ON: note = 13
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 5,   // DELAY: ticks = 5
  0x00 + 13,    // NOTE ON: note = 13
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 5,   // DELAY: ticks = 5
  0x00 + 13,    // NOTE ON: note = 13
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 1,   // DELAY: ticks = 1
  0x00 + 13,    // NOTE ON: note = 13
  0x9F + 3,   // DELAY: ticks = 3
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 5,   // DELAY: ticks = 5
  0xFE,     // RETURN
  //"Track Track 3"
  0x00 + 0,   // NOTE ON: note = 0
  0x9F + 48,    // DELAY: ticks = 48
  0xFE,     // RETURN
  //"Track Track 4"
  0x9F + 48,    // DELAY: ticks = 48
  0xFE,     // RETURN
  //"Track Track 5"
  0xFC, 4,    // GOTO track 4
  0x9F + 2,   // DELAY: ticks = 2
  0xFC, 4,    // GOTO track 4
  0x9F + 6,   // DELAY: ticks = 6
  0xFC, 4,    // GOTO track 4
  0x9F + 6,   // DELAY: ticks = 6
  0xFC, 4,    // GOTO track 4
  0x9F + 2,   // DELAY: ticks = 2
  0xFC, 4,    // GOTO track 4
  0x9F + 6,   // DELAY: ticks = 6
  0xFE,     // RETURN
};




#endif
