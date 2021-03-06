unsigned char port_byte_in ( unsigned short port ) {
// put AL register in variable result when finished
// d for load EDX with port
unsigned char result ;
__asm__ (" in %% dx , %% al " : "=a " ( result ) : "d " ( port ));
return result ;
}
void port_byte_out ( unsigned short port , unsigned char data ) {
// a for load EAX with data
// d for load EDX with port
__asm__ (" out %% al , %% dx " : :" a" ( data ), "d" ( port ));
}

// same but in word instead of byte
unsigned short port_word_in ( unsigned short port ) {
unsigned short result ;
__asm__ (" in %% dx , %% ax " : "=a " ( result ) : "d " ( port ));
return result ;
}
void port_word_out ( unsigned short port , unsigned short data ) {
__asm__ (" out %% ax , %% dx " : :" a" ( data ), "d" ( port ));
}