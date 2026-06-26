#include "AnalogReadNow.h"

#include "wiring_private.h"
#include "pins_arduino.h"

void analogSwitchPin(uint8_t pin)
{
#if defined(analogPinToChannel)
#if defined(__AVR_ATmega32U4__)
	if (pin >= 18) pin -= 18;
#endif
	pin = analogPinToChannel(pin);
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	if (pin >= 54) pin -= 54;
#elif defined(__AVR_ATmega32U4__)
	if (pin >= 18) pin -= 18;
#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)
	if (pin >= 24) pin -= 24;
#else
	if (pin >= 14) pin -= 14;
#endif

#if defined(ADCSRB) && defined(MUX5)

	ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((pin >> 3) & 0x01) << MUX5);
#endif

#if defined(ADMUX)
#if defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
	ADMUX = (DEFAULT << 4) | (pin & 0x07);
#else
	ADMUX = (DEFAULT << 6) | (pin & 0x07);
#endif
#endif

#if defined(ADCSRA) && defined(ADCL)

	sbi(ADCSRA, ADSC);
#endif
}

int analogReadNow()
{
#if defined(ADCSRA) && defined(ADCL)

	while (bit_is_set(ADCSRA, ADSC));

	uint8_t low, high;
	low  = ADCL;
	high = ADCH;

	return (high << 8) | low;
#else

	return 0;
#endif
}
