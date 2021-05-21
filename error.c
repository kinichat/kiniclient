#include "./error.h"

const char* kc_error_strings[] = {
    [KC_ERROR_SUCCESS] = "No error reported",
    
    [KC_ERROR_SOCKET_CREATION] = "Socket creation failed",
    [KC_ERROR_INVALID_ADDRESS] = "Invalid address",
    [KC_ERROR_CONNECTION_FAILED] = "Connection failed",
};

