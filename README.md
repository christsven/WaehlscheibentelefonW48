# WaehlscheibentelefonW48

## Beschreibung

Im Rahmen dieses Projektes wollen wir eine die Wählscheibe eines W48 Telefons auslesbar machen, indem wir das Nummernelement per Sensor auslesen und an ein externes Ziel versenden. Dazu verwenden wir einen Arduino Uno, welcher für Stromzufuhr und Auslesen der elektrischen Spannung des Stromkreises sowie den Output der ausgelesenen Zahl zuständig ist.

## Prozesse

### Aufbau des N38 Nummernschalters
![grafik](https://user-images.githubusercontent.com/69843539/222415091-131c2bbd-e8e3-494b-afca-9eecb5d05f55.png)

Der N38 Nummernschalter verwendet eine elektronische Schaltung, um die jeweils ausgewählte Zahl darzustellen. Das Nockenrad (rot, im Hintergrund, mit messingfarbenem Zähnen) ist starr mit der Wählscheibe auf der Frontseite verbunden.

Der orangene Pfeil zeigt hier auf das Rad, welches den elektrischen Impuls steuert.

*Beispielhaft hier gezeigt das Herstellen des Kontaktes:*

![grafik](https://user-images.githubusercontent.com/69843539/222415148-465c6221-bb20-4c55-9a29-936e778b8555.png)

### Auslesen der gewählten Nummer

Sobald eine Nummer ausgewählt wird, erzeugt der Nummernschalter eine bestimmte Anzahl elektrischer Impulse, die die Nummer darstellen `(Nummer n + 2 = Anzahl Impulse)`. Diese müssen wir auslesen und an ein Steuerelement weiterleiten.

#### Arduino Uno R3

![grafik](https://user-images.githubusercontent.com/69843539/228808262-680e2a32-f80f-4f46-8d08-755cfb9099ef.png)

## Zielsetzung

- [x]	Konzeption der Hardwareelemente
- [x]	Erfassen der nötigen Hardwarekomponenten für
  - [x]	Sensor für Wählscheibenausleser
  - [x]	Kabel (Strom, Patchkabel, Arduino)
- [x]	Erstellen einer TinkerCAD-Darstellung des Arduino

## Umsetzung

### Code
```
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
```

# Quellen
https://elektronikbasteln.pl7.de/nummernschalter-n38 </br>
https://elektronikbasteln.pl7.de/nummernschalter-funktionsweise </br>
https://www.raspberry-pi-geek.de/ausgaben/rpg/2019/02/strom-und-spannungssensor-ina3221/ </br>
https://tutorials-raspberrypi.de/raspberry-pi-gpio-erklaerung-beginner-programmierung-lernen/ </br>
