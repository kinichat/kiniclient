#ifndef KINIC_STATE_H
#define KINIC_STATE_H
#include <sys/socket.h>
#include <arpa/inet.h>
#include "./error.h"

#ifndef KC_PORT
    #define KC_PORT 15999
#endif

typedef struct KcState KcState;
struct KcState {
    int socket;
    struct sockaddr_in server_address;
};

KcError kc_state_init(KcState* state);
KcError kc_state_connect(KcState* state, const char* address);

#endif


