// NCurses colour formatting. 

#include <ncurses.h>

int main() {
	initscr(); //Start a new ncurses window

	if (! has_colors()) { //'if' statement to validate colour support
		addstr("ERROR - TERMINAL DOES NOT SUPPORT COLOURS!");
		endwin();
		return 0;
	}

	if (start_color() != OK) { //'if' statement to validate colour function working
		endwin();
		return 0;
	}

	init_pair(1, COLOR_BLUE, COLOR_WHITE); // init_pair creates a shared pair of colours
	init_pair(2, COLOR_BLACK, COLOR_BLUE);

	bkgd(COLOR_PAIR(2)); //bkgd applies specified colour pair to whole window.

	attron(COLOR_PAIR(1) | A_BOLD); //attron overwrites bkgd when differing attributes are present.
	addstr("This text is blue, with a white background in a blue window.\n"); //string will have bkgd and attron attributes applied.


	refresh(); //displays to actual screen
		  
	getch(); //halts ncurses to view text in terminal, by waiting for a keyboard input.
		 //once key is pressed, programme moves to next line.

	endwin(); //ends ncurses session, returns to normal programme.

	return 0; //ends main().

}

