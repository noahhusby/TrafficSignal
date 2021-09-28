/**
 * A simple controller for a traffic signal
 * @author Noah Husby
 */

#define RED 2
#define YELLOW 3
#define GREEN 4
#define BUTTON 10
#define INTERVAL 1000

static unsigned long lastTime = 0;
boolean button_pressed = false;
int state = 0;

enum trafficMode {
	OFF,
	RED_ON,
	YELLOW_ON,
	GREEN_ON,
	RED_FLASH,
	YELLOW_FLASH,
	CYCLE
};

trafficMode mode = OFF;

void setup() {
	pinMode(RED, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BUTTON, INPUT);
}

void loop() {
	unsigned long now = millis();
	if(digitalRead(BUTTON) == HIGH) {
		if(!button_pressed) {
			button_pressed = true;
			if(mode < 6) {
				mode = mode + 1;
			} else {
				mode = 0;
			}
			state = 0;
		}	
	} else {
		button_pressed = true;
	}
  
	if(mode == OFF) {
		digitalWrite(RED, LOW);
		digitalWrite(YELLOW, LOW);
		digitalWrite(GREEN, LOW);
	} else if(mode == RED_ON) {
		digitalWrite(RED, HIGH);
		digitalWrite(YELLOW, LOW);
		digitalWrite(GREEN, LOW);
	} else if(mode == YELLOW_ON) {
		digitalWrite(RED, LOW);
		digitalWrite(YELLOW, HIGH);
		digitalWrite(GREEN, LOW);
	} else if(mode == GREEN_ON) {
		digitalWrite(RED, LOW);
		digitalWrite(YELLOW, LOW);
		digitalWrite(GREEN, HIGH);
	} else if(mode == RED_FLASH) {
		digitalWrite(YELLOW, LOW);
		digitalWrite(GREEN, LOW);
		if ( now - lastTime > INTERVAL) {
			state = state == 0 ? 1 : 0;
			lastTime = now;
			digitalWrite(RED, state);
		}
    } else if(mode == YELLOW_FLASH) {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      if ( now - lastTime > INTERVAL) {
			state = state == 0 ? 1 : 0;
			lastTime = now;
			digitalWrite(YELLOW, state);
		}
    } else if(mode == CYCLE) {
      if ( now - lastTime > 15000 && state == 0) {
        state = 1;
        lastTime = now;
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, HIGH);
      }

      if ( now - lastTime > 15000 && state == 1) {
        state = 2;
        lastTime = now;
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, HIGH);
        digitalWrite(GREEN, LOW);
      }

      if ( now - lastTime > 1500 && state == 2) {
        state = 0;
        lastTime = now;
        digitalWrite(RED, HIGH);
        digitalWrite(YELLOW, LOW);
        digitalWrite(GREEN, LOW);
      }
    }
}
