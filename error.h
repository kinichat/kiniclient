#ifndef KINIC_ERROR_H
#define KINIC_ERROR_H

typedef enum KcError KcError;
enum KcError {
    KC_ERROR_SUCCESS,
    
    KC_ERROR_SOCKET_CREATION,
    KC_ERROR_INVALID_ADDRESS,
    KC_ERROR_CONNECTION_FAILED,
};

extern const char* kc_error_strings[];


// NOTE: This is for debugging, do not use it for real
//  error printing. We need to implement a better way
//  (TODO)
#define KC_REPORT(expr)				\
    do {					\
	KcError err = expr;			\
	if (err != KC_ERROR_SUCCESS)				\
	    printf("Error: %s\n", kc_error_strings[err]);	\
    } while(0)

#endif

