// Declare variables
int red_led_port = 13;		// port # corresponding to `redLED` on the Arduino
int unit = 200;				// base morse unit in MS
int dot = unit;				// 1 morse unit
int dash = unit * 3;		// 3 morse units
int space_blink = dot;		// space between each blink
int space_letter = dash;	// space between each letter
int space_words = unit * 7; // space between each word
int loop_cooldown = 300;	// delay between each itteration of the main simulation loop

// Declare functions
void blinkLED(int port, double delayOn = 0, double delayOff = 0)
/*
	Causes the specified port, inferred as a connection
	to the LED device, to blink, conforming to the specified
	arguments representing delays

	Both delays are optional arguments and default to 0

	This function is designed to be portable
	into other sections of this lab, therefor it
	has more arguments to allow for more customization
*/
{
	digitalWrite(port, HIGH);
	delay(delayOn);
	digitalWrite(port, LOW);
	delay(delayOff);
};

void blink(double delayOn)
/*
	A wrapper function designed to alieviate some
	repeadeted code when calling blinkLED. Since, the
	first and third argument of that function are always
	the same in this level of the lab
*/
{
	blinkLED(red_led_port, delayOn, space_blink);
};

void blinkLetterS()
/*
	In this level, I chose to spell out
	the word `SOS` in Morse Code. Since, this
	word has 2 letters `s`. This function
	handles that operation automatically
	to apply better DRY principles to the program
*/
{
	blink(dot);
	blink(dot);
	blink(dot);
};

void scenario()
/*
	Delegates to each pattern, executing the main program.
	Spells out "SOS" in Morse Code using the LED
*/
{
	// S - Dot Dot Dot
	blinkLetterS();
	delay(space_letter);

	// O - Dash Dash Dash
	// Since this letter only occurs once, I did not make a function for it
	blink(dash);
	blink(dash);
	blink(dash);
	delay(space_letter);

	// S - Dot Dot Dot
	blinkLetterS();
	delay(space_words);
}

// Arduino boilerplate and simulation init

void setup()
/*
	The initial setup for the simulation
	+ initializes the pin related to the red_led_port
*/
{
	pinMode(red_led_port, OUTPUT);
};

void loop()
// repeats all scenarios for the lifetime of the simulation
{
	scenario();
	delay(loop_cooldown);
};