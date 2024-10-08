#pragma once
#include <Arduino.h>

#define GFX_PGM(name) const static uint8_t name[] PROGMEM

namespace GFX_icons {
GFX_PGM(email) = {0xff, 0x85, 0x89, 0x91, 0x91, 0x89, 0x85, 0xff};           // 0 email
GFX_PGM(github) = {0x3c, 0x5e, 0xa3, 0x03, 0x03, 0xe3, 0x7e, 0x3c};          // 1 github
GFX_PGM(user) = {0x80, 0xc0, 0xe6, 0xef, 0xef, 0xe6, 0xc0, 0x80};            // 2 user
GFX_PGM(lock) = {0xf0, 0xfe, 0xf1, 0x91, 0x91, 0xf1, 0xfe, 0xf0};            // 3 lock, password
GFX_PGM(cog) = {0x18, 0x7e, 0x7e, 0xe7, 0xe7, 0x7e, 0x7e, 0x18};             // 4 cog, settings
GFX_PGM(clock) = {0x3c, 0x42, 0x81, 0x9d, 0x91, 0x91, 0x42, 0x3c};           // 5 clock
GFX_PGM(search) = {0x1e, 0x33, 0x21, 0x21, 0x33, 0x7e, 0xe0, 0xc0};          // 6 search
GFX_PGM(message) = {0x7e, 0x3f, 0x15, 0x15, 0x15, 0x1d, 0x1f, 0x0e};         // 7 message
GFX_PGM(bluetooth) = {0x00, 0x42, 0x24, 0x18, 0xff, 0x99, 0x66, 0x00};       // 8 bluetooth
GFX_PGM(battery100) = {0x00, 0x3c, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e};      // 9 battery 100%
GFX_PGM(battery75) = {0x00, 0x3c, 0x7e, 0x42, 0x7e, 0x7e, 0x7e, 0x7e};       // 10 battery 75%
GFX_PGM(battery50) = {0x00, 0x3c, 0x7e, 0x42, 0x42, 0x7e, 0x7e, 0x7e};       // 11 battery 50%
GFX_PGM(battery25) = {0x00, 0x3c, 0x7e, 0x42, 0x42, 0x42, 0x7e, 0x7e};       // 12 battery 25%
GFX_PGM(battery0) = {0x00, 0x3c, 0x7e, 0x42, 0x42, 0x42, 0x42, 0x7e};        // 13 battery 0%
GFX_PGM(screen) = {0xe7, 0x81, 0x81, 0x00, 0x00, 0x81, 0x81, 0xe7};          // 14 full screen
GFX_PGM(smallscreen) = {0x24, 0x24, 0xe7, 0x00, 0x00, 0xe7, 0x24, 0x24};     // 15 small screen
GFX_PGM(trash) = {0x02, 0xfa, 0x8b, 0xfb, 0xfb, 0x8b, 0xfa, 0x02};           // 16 trash, remove, delete
GFX_PGM(calendar) = {0x7c, 0x82, 0x83, 0x82, 0xb2, 0xb3, 0x82, 0x7c};        // 17 calendar
GFX_PGM(minimize) = {0x7e, 0x81, 0x81, 0x9d, 0x98, 0x94, 0x82, 0x71};        // 18 minimize
GFX_PGM(maximize) = {0x7e, 0x81, 0x81, 0x91, 0x88, 0x85, 0x83, 0x77};        // 19 maximize
GFX_PGM(printer) = {0x7c, 0x44, 0xe7, 0xa5, 0xa5, 0xe7, 0x44, 0x7c};         // 20 printer
GFX_PGM(share) = {0x00, 0x18, 0x18, 0x24, 0x24, 0xc3, 0xc3, 0x00};           // 21 share
GFX_PGM(map) = {0x1c, 0x3e, 0x73, 0xe1, 0xe1, 0x73, 0x3e, 0x1c};             // 22 map
GFX_PGM(handbag) = {0xd8, 0x88, 0xde, 0xda, 0xda, 0xde, 0x88, 0xd8};         // 23 case
GFX_PGM(warning) = {0xe0, 0xfc, 0xfe, 0xa3, 0xfe, 0xfc, 0xe0, 0x00};         // 24 warning
GFX_PGM(error) = {0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xe7, 0x7e, 0x3c};           // 25 error
GFX_PGM(record) = {0x3c, 0x42, 0x81, 0x99, 0x99, 0x81, 0x42, 0x3c};          // 26 record
GFX_PGM(play) = {0xff, 0xff, 0xff, 0x7e, 0x7e, 0x3c, 0x3c, 0x18};            // 27 play
GFX_PGM(stop) = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};            // 28 stop
GFX_PGM(pause) = {0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00};           // 29 pause
GFX_PGM(forward) = {0xff, 0x7e, 0x3c, 0x18, 0xff, 0x7e, 0x3c, 0x18};         // 30 forward
GFX_PGM(backward) = {0x18, 0x3c, 0x7e, 0xff, 0x18, 0x3c, 0x7e, 0xff};        // 31 backward
GFX_PGM(filter) = {0x07, 0x0f, 0x1f, 0xff, 0xff, 0x1f, 0x0f, 0x07};          // 32 filter
GFX_PGM(filter_out) = {0x07, 0x09, 0x11, 0xe1, 0xe1, 0x11, 0x09, 0x07};      // 33 filter outline
GFX_PGM(sound100) = {0x3c, 0x7e, 0xff, 0x00, 0x18, 0x42, 0x3c, 0x00};        // 34 sound 100%
GFX_PGM(sound50) = {0x3c, 0x7e, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00};         // 35 sound 50%
GFX_PGM(sound0) = {0x3c, 0x7e, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00};          // 36 sound 0%
GFX_PGM(sound_off) = {0x01, 0x02, 0x3c, 0x7e, 0xff, 0x20, 0x40, 0x80};       // 37 sound off
GFX_PGM(download) = {0xe0, 0x88, 0x90, 0xbf, 0xbf, 0x90, 0x88, 0xe0};        // 38 download
GFX_PGM(upload) = {0xe0, 0x84, 0x82, 0xbf, 0xbf, 0x82, 0x84, 0xe0};          // 39 upload
GFX_PGM(text_file) = {0x7e, 0x81, 0xa1, 0xa1, 0xaf, 0xa9, 0x8a, 0x7c};       // 40 text file
GFX_PGM(link) = {0xf0, 0x88, 0xa0, 0x92, 0x49, 0x05, 0x11, 0x0f};            // 41 link
GFX_PGM(pencil) = {0xe0, 0x90, 0x88, 0x44, 0x26, 0x19, 0x0a, 0x04};          // 42 pencil
GFX_PGM(bookmark) = {0xfe, 0x7f, 0x3f, 0x1f, 0x1f, 0x3f, 0x7f, 0xfe};        // 43 bookmark
GFX_PGM(flash) = {0x00, 0x98, 0xdc, 0xfe, 0x7f, 0x3b, 0x19, 0x18};           // 44 flash, lighting
GFX_PGM(attach) = {0x7e, 0x81, 0x99, 0xa5, 0xa5, 0xa5, 0xa1, 0x9e};          // 45 attach
GFX_PGM(heart) = {0x1e, 0x3f, 0x7f, 0xfe, 0xfe, 0x7f, 0x3f, 0x1e};           // 46 heart
GFX_PGM(heart_out) = {0x1e, 0x21, 0x41, 0x82, 0x82, 0x41, 0x21, 0x1e};       // 47 heart outline
GFX_PGM(direction) = {0x72, 0x77, 0x77, 0xff, 0xff, 0x77, 0x77, 0x27};       // 48 direction
GFX_PGM(eye) = {0x18, 0x24, 0x42, 0x5a, 0x5a, 0x42, 0x24, 0x18};             // 49 eye, visible
GFX_PGM(antenna) = {0x06, 0x09, 0x11, 0xff, 0xff, 0x11, 0x09, 0x06};         // 50 antenna
GFX_PGM(signal_100) = {0x00, 0xe0, 0x00, 0xf0, 0x00, 0xfc, 0x00, 0xff};      // 51 mobile signal 100%
GFX_PGM(signal_75) = {0x00, 0xe0, 0x00, 0xf0, 0x00, 0xfc, 0x00, 0x80};       // 52 mobile signal 75%
GFX_PGM(signal_50) = {0x00, 0xe0, 0x00, 0xf0, 0x00, 0x80, 0x00, 0x80};       // 53 mobile signal 50%
GFX_PGM(signal_25) = {0x00, 0xe0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80};       // 54 mobile signal 25%
GFX_PGM(signal_0) = {0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80};        // 55 mobile signal 0%
GFX_PGM(sync) = {0x20, 0x40, 0xff, 0x00, 0x00, 0xff, 0x02, 0x04};            // 56 sync
GFX_PGM(video) = {0x7e, 0x7e, 0x7e, 0x7e, 0x3c, 0x18, 0x3c, 0x7e};           // 57 video
GFX_PGM(wifi) = {0x02, 0x09, 0x25, 0x95, 0x95, 0x25, 0x09, 0x02};            // 58 wifi
GFX_PGM(cloud) = {0x70, 0x88, 0x84, 0x84, 0xa4, 0x98, 0x90, 0x60};           // 59 cloud
GFX_PGM(flashlight_on) = {0x01, 0x0a, 0xf8, 0xfb, 0xf8, 0x0a, 0x01, 0x00};   // 60 flashlight on
GFX_PGM(flashlight_off) = {0x00, 0x08, 0xf8, 0x88, 0xf8, 0x08, 0x00, 0x00};  // 61 flashlight off
GFX_PGM(bell) = {0x70, 0x4e, 0x41, 0xc1, 0xc1, 0x41, 0x4e, 0x70};            // 62 bell
GFX_PGM(unlock) = {0xf0, 0xfe, 0xf1, 0x91, 0x91, 0xf1, 0xf2, 0xf0};          // 63 unlock
GFX_PGM(vibrate) = {0x3c, 0x00, 0xff, 0x81, 0x81, 0xff, 0x00, 0x3c};         // 64 vibrate
GFX_PGM(checked) = {0x7e, 0x81, 0x91, 0xa1, 0x91, 0x89, 0x84, 0x72};         // 65 checked
GFX_PGM(unchecked) = {0x7e, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x7e};       // 66 unchecked
GFX_PGM(chip) = {0x54, 0x00, 0xff, 0x81, 0x81, 0xff, 0x00, 0x54};            // 67 chip
GFX_PGM(bug) = {0x48, 0x48, 0xfd, 0x82, 0x82, 0xfd, 0x48, 0x48};             // 68 bug
GFX_PGM(save) = {0xff, 0x89, 0xe9, 0xa9, 0xa9, 0xe9, 0x8a, 0xfc};            // 69 save
GFX_PGM(open) = {0xfe, 0xa2, 0x92, 0x8a, 0x8a, 0xcc, 0x28, 0x18};            // 70 open
GFX_PGM(tool) = {0xc0, 0xe0, 0x70, 0x3e, 0x19, 0x11, 0x10, 0x0c};            // 71 tool
GFX_PGM(console) = {0xff, 0xdd, 0xeb, 0xb7, 0xbf, 0xbf, 0xbf, 0xff};         // 72 console
GFX_PGM(list) = {0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb};            // 73 todo, list
GFX_PGM(apps) = {0xe7, 0xe7, 0xe7, 0x00, 0x00, 0xe2, 0xe7, 0xe2};            // 74 apps
GFX_PGM(android) = {0xf1, 0x8a, 0xa4, 0x84, 0x84, 0xa4, 0x8a, 0xf1};         // 75 android
GFX_PGM(bulb) = {0x00, 0x0e, 0x71, 0xa1, 0xa1, 0x71, 0x0e, 0x00};            // 76 bulb
GFX_PGM(logout) = {0x7e, 0x81, 0x99, 0x99, 0x18, 0x5a, 0x3c, 0x18};          // 77 logout
GFX_PGM(login) = {0x18, 0x18, 0x5a, 0x3c, 0x99, 0x81, 0x81, 0x7e};           // 78 login
GFX_PGM(zoom_in) = {0x3e, 0x41, 0x49, 0x5d, 0x49, 0x41, 0xfe, 0xc0};         // 79 zoom in
GFX_PGM(zoom_out) = {0x3e, 0x41, 0x49, 0x49, 0x49, 0x41, 0xfe, 0xc0};        // 80 zoom out
GFX_PGM(dashboard) = {0xff, 0xff, 0xff, 0x00, 0xf7, 0xf7, 0xf7, 0xf7};       // 81 dashboard
GFX_PGM(all_out) = {0xc3, 0x99, 0x3c, 0x7e, 0x7e, 0x3c, 0x99, 0xc3};         // 82 all out
GFX_PGM(science) = {0xc0, 0xe0, 0xf1, 0xff, 0xff, 0xf1, 0xe0, 0xc0};         // 83 science
GFX_PGM(block) = {0x3c, 0x42, 0xa1, 0x91, 0x89, 0x85, 0x42, 0x3c};           // 84 block
GFX_PGM(cat) = {0x7f, 0x82, 0xb4, 0x84, 0x84, 0xb4, 0x82, 0x7f};             // 85 cat, fox
GFX_PGM(celsius) = {0x06, 0x09, 0x09, 0x06, 0x78, 0x84, 0x84, 0x48};         // 86 celsius
GFX_PGM(temperature) = {0x06, 0x09, 0x09, 0x06, 0x08, 0xfc, 0x88, 0xc0};     // 87 temperature
GFX_PGM(kelvin) = {0x06, 0x09, 0x09, 0x06, 0xf8, 0x20, 0x50, 0x88};          // 88 kelvin
GFX_PGM(tag) = {0x24, 0x24, 0xff, 0x24, 0x24, 0xff, 0x24, 0x24};             // 89 tag
GFX_PGM(chevron_right) = {0x00, 0x00, 0x81, 0xc3, 0x66, 0x3c, 0x18, 0x00};   // 90 chevron right
GFX_PGM(chevron_left) = {0x00, 0x18, 0x3c, 0x66, 0xc3, 0x81, 0x00, 0x00};    // 91 chevron left
GFX_PGM(chevron_up) = {0x30, 0x18, 0x0c, 0x06, 0x06, 0x0c, 0x18, 0x30};      // 92 chevron up
GFX_PGM(chevron_down) = {0x0c, 0x18, 0x30, 0x60, 0x60, 0x30, 0x18, 0x0c};    // 93 chevron down
GFX_PGM(note1) = {0x00, 0x60, 0x90, 0x90, 0x7f, 0x00, 0x00, 0x00};           // 94 note 1
GFX_PGM(note2) = {0x00, 0x60, 0xf0, 0xf0, 0x7f, 0x00, 0x00, 0x00};           // 95 note 2
GFX_PGM(note3) = {0x00, 0x60, 0x90, 0x90, 0x7f, 0x01, 0x01, 0x00};           // 96 note 3
GFX_PGM(note4) = {0x00, 0x60, 0xf0, 0xf0, 0x7f, 0x01, 0x01, 0x00};           // 97 note 4
GFX_PGM(note5) = {0x00, 0x60, 0x90, 0x90, 0x7f, 0x05, 0x05, 0x00};           // 98 note 5
GFX_PGM(note6) = {0x00, 0x60, 0xf0, 0xf0, 0x7f, 0x05, 0x05, 0x00};           // 99 note 6
GFX_PGM(cup0) = {0x7f, 0x81, 0x81, 0x81, 0x81, 0x7f, 0x22, 0x1e};            // 100 cup empty
GFX_PGM(cup20) = {0x7f, 0xe1, 0xe1, 0xe1, 0xe1, 0x7f, 0x22, 0x1e};           // 101 cup 20%
GFX_PGM(cup40) = {0x7f, 0xf1, 0xf1, 0xf1, 0xf1, 0x7f, 0x22, 0x1e};           // 102 cup 40%
GFX_PGM(cup60) = {0x7f, 0xf9, 0xf9, 0xf9, 0xf9, 0x7f, 0x22, 0x1e};           // 103 cup 60%
GFX_PGM(cup80) = {0x7f, 0xfd, 0xfd, 0xfd, 0xfd, 0x7f, 0x22, 0x1e};           // 104 cup 80%
GFX_PGM(cup100) = {0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x22, 0x1e};          // 105 cup 100%
GFX_PGM(wineglass) = {0x07, 0x09, 0x91, 0xe1, 0xe1, 0x91, 0x09, 0x07};       // 106 wineglass
GFX_PGM(glass) = {0x07, 0x19, 0xe1, 0x81, 0x81, 0xe1, 0x19, 0x07};           // 107 glass
GFX_PGM(hammer) = {0x04, 0x06, 0xff, 0xff, 0xff, 0x06, 0x0f, 0x0f};          // 108 hammer
GFX_PGM(folder_out) = {0xff, 0x81, 0x81, 0x81, 0x82, 0x82, 0x82, 0xfc};      // 109 folder outline
GFX_PGM(folder) = {0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfc};          // 110 folder
GFX_PGM(folder_add) = {0xff, 0x81, 0x81, 0x91, 0xba, 0x92, 0x82, 0xfc};      // 111 add folder
GFX_PGM(microphone) = {0x1c, 0x30, 0x20, 0xef, 0xef, 0x20, 0x30, 0x1c};      // 112 microphone
GFX_PGM(equalizer) = {0xe0, 0xe0, 0x00, 0xff, 0xff, 0x00, 0xfc, 0xfc};       // 113 equalizer
GFX_PGM(next) = {0xff, 0xff, 0xff, 0x7e, 0x3c, 0x18, 0x00, 0xff};            // 114 next
GFX_PGM(prev) = {0xff, 0x00, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0xff};            // 115 prev
GFX_PGM(monitor) = {0x3f, 0xa1, 0xa1, 0xe1, 0xe1, 0xa1, 0xa1, 0x3f};         // 116 monitor, display
GFX_PGM(headset) = {0x7c, 0xe2, 0xe1, 0x01, 0x01, 0xe1, 0xe2, 0x7c};         // 117 headset, earphones
GFX_PGM(workout) = {0x18, 0x3c, 0x7e, 0x18, 0x18, 0x7e, 0x3c, 0x18};         // 118 workout, fitness
GFX_PGM(sport) = {0xff, 0x0a, 0x15, 0x0a, 0x15, 0x0a, 0x15, 0x0a};           // 119 sport flag
GFX_PGM(location) = {0x18, 0x18, 0x24, 0xc3, 0xc3, 0x24, 0x18, 0x18};        // 120 location
GFX_PGM(cellular1) = {0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0x01, 0xbd};       // 121 cellular 1
GFX_PGM(cellular2) = {0xc0, 0xa0, 0x90, 0x88, 0x84, 0x82, 0x01, 0xbd};       // 122 cellular 2
GFX_PGM(cellular3) = {0xc0, 0xa0, 0x90, 0x88, 0x84, 0x82, 0x81, 0xff};       // 123 cellular 3
GFX_PGM(cellular4) = {0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff};       // 124 cellular 4
GFX_PGM(cellular5) = {0x43, 0x66, 0x7c, 0x78, 0x74, 0x6e, 0xdf, 0xbf};       // 125 cellular 5
GFX_PGM(cellular6) = {0xc0, 0xe0, 0xf0, 0xf8, 0x0c, 0xae, 0x4f, 0xaf};       // 126 cellular 6
GFX_PGM(waves) = {0x92, 0x49, 0x49, 0x92, 0x92, 0x49, 0x49, 0x92};           // 127 waves
GFX_PGM(home) = {0x18, 0xf4, 0x92, 0x91, 0x91, 0x92, 0xf4, 0x18};            // 128 home
GFX_PGM(dice1) = {0x7e, 0x81, 0xa5, 0x81, 0x81, 0xa5, 0x81, 0x7e};           // 129 dice 1
GFX_PGM(dice2) = {0x7e, 0x81, 0x85, 0x81, 0x81, 0xa1, 0x81, 0x7e};           // 130 dice 2
GFX_PGM(plug) = {0x3c, 0x44, 0x47, 0xc4, 0xc4, 0x47, 0x44, 0x3c};            // 131 plug
GFX_PGM(home2) = {0xf8, 0x84, 0x82, 0x81, 0xb1, 0xb2, 0x84, 0xf8};           // 132 home 2
GFX_PGM(radio) = {0xf0, 0x90, 0xf0, 0xf1, 0x92, 0x94, 0x98, 0xf0};           // 133 radio
GFX_PGM(memory) = {0x24, 0x7e, 0xc3, 0x5a, 0x5a, 0xc3, 0x7e, 0x24};          // 134 memory
GFX_PGM(gamepad) = {0x44, 0x92, 0xba, 0x92, 0x82, 0xaa, 0x82, 0x44};         // 135 gamepad
GFX_PGM(router) = {0x70, 0x88, 0xa8, 0x8a, 0xa9, 0x8d, 0x89, 0x72};          // 136 router
GFX_PGM(smile1) = {0x7e, 0x81, 0x95, 0xa1, 0xa1, 0x95, 0x81, 0x7e};          // 137 smile 1
GFX_PGM(smile2) = {0x7e, 0x81, 0xa5, 0x91, 0x91, 0xa5, 0x81, 0x7e};          // 138 smile 2
GFX_PGM(smile3) = {0x7e, 0x81, 0xa5, 0xa1, 0xa1, 0xa5, 0x81, 0x7e};          // 139 smile 3
GFX_PGM(smile4) = {0x7e, 0x81, 0x85, 0xb1, 0xb1, 0x85, 0x81, 0x7e};          // 140 smile 4
GFX_PGM(smile5) = {0x7e, 0x81, 0x8d, 0xe1, 0xe1, 0x8d, 0x81, 0x7e};          // 141 smile 5
GFX_PGM(sms) = {0x01, 0x03, 0xff, 0xfb, 0xbb, 0xab, 0xab, 0xff};             // 142 sms
GFX_PGM(toggle_on) = {0x3c, 0x7e, 0x7e, 0x7e, 0x7e, 0x66, 0x66, 0x3c};       // 143 toggle on
GFX_PGM(toggle_off) = {0x3c, 0x5a, 0x5a, 0x42, 0x42, 0x42, 0x42, 0x3c};      // 144 toggle off
GFX_PGM(arrow1_right) = {0x00, 0x00, 0xff, 0x7e, 0x3c, 0x18, 0x00, 0x00};    // 145 arrow type 1 right
GFX_PGM(arrow1_left) = {0x00, 0x00, 0x18, 0x3c, 0x7e, 0xff, 0x00, 0x00};     // 146 arrow type 1 left
GFX_PGM(arrow1_down) = {0x04, 0x0c, 0x1c, 0x3c, 0x3c, 0x1c, 0x0c, 0x04};     // 147 arrow type 1 down
GFX_PGM(arrow1_up) = {0x20, 0x30, 0x38, 0x3c, 0x3c, 0x38, 0x30, 0x20};       // 148 arrow type 1 up
GFX_PGM(arrow2_right) = {0x18, 0x18, 0x18, 0x18, 0xff, 0x7e, 0x3c, 0x18};    // 149 arrow type 2 right
GFX_PGM(arrow2_left) = {0x18, 0x3c, 0x7e, 0xff, 0x18, 0x18, 0x18, 0x18};     // 150 arrow type 2 left
GFX_PGM(arrow2_down) = {0x10, 0x30, 0x70, 0xff, 0xff, 0x70, 0x30, 0x10};     // 151 arrow type 2 down
GFX_PGM(arrow2_up) = {0x08, 0x0c, 0x0e, 0xff, 0xff, 0x0e, 0x0c, 0x08};       // 152 arrow type 2 up
GFX_PGM(alarm) = {0x02, 0x79, 0x85, 0xb4, 0xa4, 0x85, 0x79, 0x02};           // 153 alarm clock
GFX_PGM(key) = {0x3c, 0x42, 0x42, 0x3c, 0x08, 0x18, 0x08, 0x38};             // 154 key
}