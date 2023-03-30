void blinkFor(int times) {
  int delayTime = 80;
  int counter = 0;
  while (counter < times) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);
    counter = counter + 1;
  }
}

// Output custom text
void wT(String text) {
  Serial.print(text);
  Serial.println();
}

// Just for end result
void wN(int number) {
  Serial.print("Output: ");
  Serial.print(number);
  Serial.println();
}

// Output the actual values
void i(int i) {
  //Serial.print(i);
  //Serial.println();
}

void setup() {
  Serial.begin(9600);
  // Sets the onboard LED as our output
  pinMode(LED_BUILTIN, OUTPUT);
  // Gets the HIGH and LOW from Digital 2
  pinMode(2, INPUT);
  // Hello i am alive
  wT("Hello");
  blinkFor(3);
}


void loop() {
  int breaks = 0;
  int counter = 0;
  boolean done = false;
  
  int input = digitalRead(2);
  i(input);

  // Count breaks in a cluster
  while (counter < 20) {
    // Reset
    done = false;
    input = digitalRead(2);
    i(input);

    // Count singular break
    while (input == LOW) {
      if (!done) {
        // This if only gets executed once
        done = true;
        // Reset idle counter
        counter = 0;
        // Add to breaks counter
        breaks++;
      }
      // Repeat until circuit gets closed again
      input = digitalRead(2);
      i(input);
    }

    // Count idle time -> either new break or 20x wait
    counter++;

    // It does not work without this, i dont know why
    delay(5);
  }

  // Output results
  if (breaks != 0) {
    blinkFor(breaks);
    wN(breaks);
    // Reset
    breaks = 0;
  }
}
