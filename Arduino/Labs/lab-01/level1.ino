// Declare variables
int blue_led_port = 13; // port # corresponding to `blueLED` on the Arduino
int fast_delay = 1000;
int slow_delay = 100;
int space_blink = 100;		 // delay between each blink
int scenario_cooldown = 300; // delay between each scenario (1 & 2)
int loop_cooldown = 300;	 // delay between each itteration of the main simulation loop

// Declare functions
void blinkLED(int port, double delayOn = 0, double delayOff = 0)
/*
	Causes the specified port, inferred as a connection
	to the LED device, to blink, conforming to the specified
	arguments representing delays

	Both delays are optional arguments and default to 0

	This function is designed to be portable
	into other sections of this lab, therefor it
	as more arguments to allow for more customization
*/
{
	digitalWrite(port, HIGH);
	delay(delayOn);
	digitalWrite(port, LOW);
	delay(delayOff);
};

void blink(double delayOn = 0)
/*
	A wrapper function designed to alieviate some
	repeadeted code when calling blinkLED. Since, the
	first and third argument of that function are always
	the same in this level of the lab
*/
{
	blinkLED(blue_led_port, delayOn, space_blink);
}

void pattern1()
// Blinks the LED 3 times, slowly.
{
	for (int i = 0; i < 3; i++)
	{
		blink(slow_delay);
	};
}

void pattern2()
// Blinks the LED 3 times, rapidly.
{
	for (int i = 0; i < 3; i++)
	{
		blink(fast_delay);
	};
}

void scenario()
// Delegates to each pattern, executing the main program.
{
	pattern1();
	delay(scenario_cooldown);
	pattern2();
}

// Arduino boilerplate and simulation init

void setup()
/*
	The initial setup for the simulation
	+ initializes the pin related to the blue_led_port
*/
{
	pinMode(blue_led_port, OUTPUT);
};

void loop()
// repeats all scenarios for the lifetime of the simulation
{
	scenario();
	delay(loop_cooldown);
};