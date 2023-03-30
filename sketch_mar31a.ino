void blinkFor(int times) {
  int delayTime = 40;
  int count = 0;
  while (count < times) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);
    count++;
  }
}
void setup() {
  Serial.begin(9600);
  // Sets the onboard LED as our output
  pinMode(LED_BUILTIN, OUTPUT);
  // Gets the HIGH and LOW from Digital 2
  pinMode(2, INPUT);
  // Hello i am alive
  Serial.println("Hello");
  blinkFor(3);
}
void loop() {
  int breaks = 0;
  int counter = 0;
  boolean done = false;
  int input = digitalRead(2);
  // Count breaks in a cluster
  while (counter < 20) {
    // Reset
    done = false;
    input = digitalRead(2);
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
    }
    // Count idle time -> either new break or 20x wait
    counter++;
    // It does not work without this, i dont know why
    delay(5);
  }
  // Output results
  if (breaks != 0) {
    //blinkFor(breaks);
    Serial.print("Output: ");
    Serial.print(breaks);
    Serial.println();
    // Reset
    breaks = 0;
  }
}
