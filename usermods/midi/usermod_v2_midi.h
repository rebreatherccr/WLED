#pragma once

#include "wled.h"

#ifndef USERMOD_V2_MIDI_H
#define USERMOD_V2_MIDI_H

/*
 * Usermod V2 Midi
 *
 * usermods/midi
 *
 * rebreatherccr
 *
 ***
 * 1
 * Used for Keyboard Practice / Tutorials / Training
 * Playback Midi File(s) from SD Card
 * Animate LED Segments 1,2,3,4 ... 5,6,7,8 etc. to Music
 * 
 ***
 * 2
 * Used for Keyboard Lighting Effects
 * Playback Midi Inputs from USB/Serial/Midi Keyboard
 * Animate 1 LED Segment for Effects Lighting
 *
 * See: https://github.com/Aircoookie/WLED/wiki/Add-own-functionality
 *
 *
 ******************************* 
 * Steps to create this UserMod:
 *******************************
 *
 * copy example header file
 *   from usermod_v2_example/usermod_v2_example.h
 *   (not just a header file it poorly includes code)
 * create header file
 *   usermod_v2_midi.h
 * create cpp file
 *   usermod_v2_midi.cpp
 * 
 * name new class UsermodXXX : public Usermod
 * 
 * edit file
 * usermods_list.cpp
 * add include code
 * #ifdef USERMOD_V2_MIDI
 * #include "../usermods/midi/usermod_v2_midi.h"
 * #include "../usermods/midi/usermod_v2_midi.cpp"
 * #endif
 * edit function 
 * void registerUsermods()
 * add code
 * #ifdef USERMOD_V2_MIDI
 *   usermods.add(new UsermodV2Midi());
 * #endif
 *
 * edit file
 * const.h
 * under //Usermod IDs
 * add code
 * #define USERMOD_ID_V2_MIDI       99            //Usermod "usermod_v2_midi.h"
 * 
 *
 **************************************
 * How to Build WLED with this UserMod:
 **************************************
 * Edit platformio.ini
 *  under build_flags = 
 *  add the following line
 *  -D USERMOD_V2_MIDI
 * 
 *
 ******************
 * Using a usermod:
 * 1. Copy the usermod into the sketch folder (same folder as wled00.ino)
 * 2. Register the usermod by adding #include "usermod_filename.h" in the top and registerUsermod(new MyUsermodClass()) in the bottom of usermods_list.cpp
 */



// class definition
class UsermodV2Midi : public Usermod {

  // Private class members
  private:

    unsigned long lastTime;                       // last time loop() was called - rudimentary time based delay without using delay()

  // Public class members
  public:

    void setup();                                 // called once at boot
    void connected();                             // called every time wifi/ethernet is connected
    void loop();                                  // called by wled.cpp main loop WLED::loop() after userLoop(); by usermods.loop();
    // void addToJsonInfo(JsonObject& root);
    void addToJsonState(JsonObject& root);
    void readFromJsonState(JsonObject& root);
    void addToConfig(JsonObject& root);
    void readFromConfig(JsonObject& root);
    uint16_t getId();                             // return custom USERMOD_ID from const.h file

};

#endif