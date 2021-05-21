#include "./state.h"
#include <unistd.h>
#include <string.h>

KcError kc_state_init(KcState* state) {
    state->socket = 0;
    state->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (state->socket < 0) {
	return KC_ERROR_SOCKET_CREATION;
    }

    state->server_address.sin_family = AF_INET;
    state->server_address.sin_port = htons(KC_PORT);

    return KC_ERROR_SUCCESS;
}

KcError kc_state_connect(KcState* state, const char* address) {
    if (inet_pton(AF_INET, address, &state->server_address.sin_addr) <= 0) {
	return KC_ERROR_INVALID_ADDRESS;
    }

    if (connect(state->socket, (struct sockaddr*)&state->server_address, sizeof(state->server_address) < 0)) {
	return KC_ERROR_CONNECTION_FAILED;
    }

    return KC_ERROR_SUCCESS;
}

