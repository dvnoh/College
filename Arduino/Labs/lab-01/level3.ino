// Declare variables
int red_led_port = 13;		// port # corresponding to `redLED` on the Arduino
int blue_led_port = 12;		// port # corresponding to `blueLED` on the Arduino
int space_blink = 200;		// space between each blink
int pattern_cooldown = 100; // delay between each call to a pattern function
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

void blink(int port)
/*
	A wrapper function designed to alieviate some
	repeadeted code when calling blinkLED. Since, the second
	and third argument of that function are always
	the same in this level of the lab
*/
{
	blinkLED(port, space_blink);
}

void pattern1()
// Blinks both LEDs in an alternating fashion
{
	for (int i = 0; i < 5; i++)
	{
		blink(red_led_port);
		blink(blue_led_port);
	}
}

void pattern2()
/*
	Blinks both LEDs in sync.
	Done manually using `digitalWrite` because
	`blinkLED` is a yielding function (rightfully so)
	therefor this was the only alternative without multithreading
*/
{
	for (int i = 0; i < 4; i++)
	{
		digitalWrite(blue_led_port, HIGH);
		digitalWrite(red_led_port, HIGH);
		delay(space_blink);
		digitalWrite(blue_led_port, LOW);
		digitalWrite(red_led_port, LOW);
	}
}

void scenario()
/*
  Delegates to each pattern, executing the main program.
*/
{
	pattern1();
	delay(pattern_cooldown);
	pattern2();
}

// Arduino boilerplate and simulation init

/*
  The initial setup for the simulation
  + initializes the pin related to the red_led_port
  + initializes the pin related to the blue_led_port
*/
void setup()
{
	pinMode(red_led_port, OUTPUT);
	pinMode(blue_led_port, OUTPUT);
}

void loop()
// repeats all scenarios for the lifetime of the simulation
{
	scenario();
	delay(loop_cooldown);
};