#include <stdio.h>
#include "./error.h"
#include "./state.h"

int main() {
    KcState state;

    KC_REPORT(kc_state_init(&state));
    KC_REPORT(kc_state_connect(&state, "127.0.0.1"));
    
    return 0;
}

