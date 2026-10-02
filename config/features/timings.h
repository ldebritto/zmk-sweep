#pragma once // This makes so that variables in this file will have precedence over the ones in other files

// Hold-taps
    #define HOLD_TAP_TERM 280       // For same hand activations, as urob's timeless home row mods is the default
    #define QUICK_TAP 200           // 
    #define REQUIRE_PRIOR_IDLE 250  // 
    #define COMBOS_PRIOR_IDLE 300   // Higher to avoid false positives when typing common combinations such as OU or WR
    
// Tap Dance
    #define TAP_DANCE_TERM 300

// Combos
    #define COMBO_TIMEOUT 60  // Default timeout for combos in ms
