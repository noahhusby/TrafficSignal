#define RED 2
#define YELLOW 3
#define GREEN 4
#define MODE 10
#define DB 13

static unsigned long lastTime = 0;
const long interval = 1000;
int state = 0;

const long si = 1000;
const long yi = 2500;
  
boolean mode_pressed = false;

int cm = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(MODE, INPUT);

  pinMode(DB,OUTPUT);
  digitalWrite(DB, LOW);

  Serial.begin(9600);
}

void loop() {
  
  unsigned long now = millis();

  Serial.println(cm);
  
  if(digitalRead(MODE) == HIGH && !mode_pressed) {
    mode_pressed = true;
    if(cm == 0) {
      cm = 1;
    } else if(cm == 1) {
      cm = 2;
    } else if(cm == 2) {
      cm = 3;
    } else if(cm == 3) {
      cm = 4;
    } else if(cm == 4) {
      cm = 5;
    } else if(cm == 5) {
      cm = 6;
    } else if(cm == 6) {
      cm = 0;
    }

    state = 0;
  }
  
  if(digitalRead(MODE) == LOW) {
    mode_pressed = false;
  }

  if(cm == 0) {
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, LOW);
    }
    if(cm == 1) {
      digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, LOW);
    }
    if(cm == 2) {
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, HIGH);
      digitalWrite(GREEN, LOW);
    }
    if(cm == 3) {
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
    }
    if(cm == 4) {
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, LOW);
      if ( now - lastTime > interval && state == 0) {
        state = 1;
        lastTime = now;
       digitalWrite(RED, HIGH);
      }

      if ( now - lastTime > interval && state == 1) {
        state = 0;
        lastTime = now;
        digitalWrite(RED, LOW);
      }
    }
    if(cm == 5) {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      if ( now - lastTime > interval && state == 0) {
        state = 1;
        lastTime = now;
       digitalWrite(YELLOW, HIGH);
      }

      if ( now - lastTime > interval && state == 1) {
        state = 0;
        lastTime = now;
        digitalWrite(YELLOW, LOW);
      }
    }
    
    if(cm == 6) {
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



