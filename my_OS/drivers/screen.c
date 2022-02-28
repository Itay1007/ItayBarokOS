# define VIDEO_ADDRESS 0 xb8000
# define MAX_ROWS 25
# define MAX_COLS 80
// Attribute byte for our default colour scheme .
# define WHITE_ON_BLACK 0 x0f
// Screen device I/O ports
# define REG_SCREEN_CTRL 0 x3D4
# define REG_SCREEN_DATA 0 x3D5


/* Print a char on the screen at col , row , or at cursor position */
void print_char ( char character , int col , int row , char attribute_byte ) {
	unsigned char * vidmem = ( unsigned char *) VIDEO_ADDRESS ;
	int offset ;
	if ( col >= 0 && row >= 0) {
		offset = get_screen_offset ( col , row );
	} 
	else {
		offset = get_cursor ();
	}

	vidmem [ offset ] = character ;
	vidmem [ offset +1] = attribute_byte ;

	// Update the offset to the next character cell , which is
	// two bytes ahead of the current cell .
	offset += 2;
	// Make scrolling adjustment , for when we reach the bottom
	// of the screen .
	offset = handle_scrolling ( offset );
	// Update the cursor position on the screen device .
	set_cursor ( offset );
}



void print_at ( char * message , int col , int row ) {
	// Update the cursor if col and row not negative .
	if ( col >= 0 && row >= 0) {
		set_cursor ( get_screen_offset ( col , row ));

		int i = 0;
		while ( message [ i] != 0) {
			print_char ( message [ i ++] , col , row , WHITE_ON_BLACK );
		}
	}
}


void print ( char * message ) {
	int i = 0;
	while ( message [ i] != 0) {
		print_char ( message [ i ++] , col , row , WHITE_ON_BLACK );
	}
}

void clear_screen () {
	int row = 0;
	int col = 0;
	/* Loop through video memory and write blank characters . */
	for ( row =0; row < MAX_ROWS ; row ++) {
		for ( col =0; col < MAX_COLS ; col ++) {
			print_char ( ’ ’ , col , row , WHITE_ON_BLACK );
		}
	}
	// Move the cursor back to the top left .
	set_cursor ( get_screen_offset (0 , 0));
}


int get_cursor() {
    /* Use the VGA ports to get the current cursor position
     * 1. Ask for high byte of the cursor offset (data 14)
     * 2. Ask for low byte (data 15)
     */
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8; /* High byte: << 8 */
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset * 2; /* Position * size of character cell */
}


void set_cursor(int offset) {
    /* Similar to get_cursor, but instead of reading we write data */
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

int get_screen_offset(int col, int row) 
{
	 return 2 * (row * MAX_COLS + col);
}