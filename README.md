# WaehlscheibentelefonW48

## Beschreibung

Im Rahmen dieses Projektes wollen wir eine die Wählscheibe eines W48 Telefons auslesbar machen, indem wir das Nummernelement per Sensor auslesen und an ein externes Ziel versenden.

## Prozesse

### Aufbau des N38 Nummernschalters
![grafik](https://user-images.githubusercontent.com/69843539/222415091-131c2bbd-e8e3-494b-afca-9eecb5d05f55.png)

Der N38 Nummernschalter verwendet eine elektronische Schaltung, um die jeweils ausgewählte Zahl darzustellen. Das Nockenrad (rot, im Hintergrund, mit messingfarbenem Zähnen) ist starr mit der Wählscheibe auf der Frontseite verbunden.

Der orangene Pfeil zeigt hier auf das Rad, welches den elektrischen Impuls steuert.

*Beispielhaft hier gezeigt das Herstellen des Kontaktes:*

![grafik](https://user-images.githubusercontent.com/69843539/222415148-465c6221-bb20-4c55-9a29-936e778b8555.png)

### Auslesen der gewählten Nummer

Sobald eine Nummer ausgewählt wird, erzeugt der Nummernschalter eine bestimmte Anzahl elektrischer Impulse, die die Nummer darstellen `(Nummer n + 2 = Anzahl Impulse)`. Diese müssen wir auslesen und an ein Steuerelement weiterleiten.

#### Spannungssensor

Wir wollen die Wahlscheibe auslesen, um die ausgewählte Nummer beispielhaft in einer Datei auf einem anderen Gerät (Schul-PC) zu erfassen.

##### Shunt

>Als Shunt bezeichnet man einen niederohmigen Messwiderstand, den man in einen Stromkreis einbaut, um indirekt den Strom zu messen. Dazu misst man die Spannung, die am Widerstand abfällt, und errechnet daraus den Strom. Mehrere Umstände erzwingen diesen Umweg: A/D-Wandler können keine Stromwerte messen, da sie sich dabei in den Stromkreis einklinken müssten. Hohe Ströme verursachen am Shunt eine entsprechende Verlustleistung, weswegen man ihn in der Regel vom eigentlichen Kreislauf zum Messen trennt.

>Der Shunt sollte möglichst geringe Toleranzwerte aufweisen, um die Messung nicht zu verfälschen. Bei der Strommessung fällt am Shunt auf jeden Fall eine Spannung (U=R x I) ab, die dann nicht mehr für den Verbraucher bereitsteht. Der Spannungsabfall am Shunt erzeugt eine an der Energiequelle gespeiste Verlustleistung (P=U x I), die immer Abwärme bedeutet. Bei Einsatz eines Shunts gilt es daher, immer die maximale Leistung des Bauteils zu beachten, sonst brennt es einfach ab.

https://www.raspberry-pi-geek.de/ausgaben/rpg/2019/02/strom-und-spannungssensor-ina3221/

#### Arduino Uno R3

![grafik](https://user-images.githubusercontent.com/69843539/228808262-680e2a32-f80f-4f46-8d08-755cfb9099ef.png)


https://tutorials-raspberrypi.de/raspberry-pi-gpio-erklaerung-beginner-programmierung-lernen/

## Zielsetzung

- [ ]	Konzeption der Hardwareelemente
- [ ]	Erfassen der nötigen Hardwarekomponenten für
- [ ]	Sensor für Wählscheibenausleser
- [ ]	Iot-Controller (Raspberry Pi 3)
- [ ]	Kabel (Strom, Patchkabel, Arduino)
- [ ]	Netzteil
- [ ]	Erstellen einer "Proof of Concept"-Modellierung der Softwareelemente in Packet Tracer

# Quellen
[Nummernschalter N38](https://elektronikbasteln.pl7.de/nummernschalter-n38)

[Funktionsweise](https://elektronikbasteln.pl7.de/nummernschalter-funktionsweise)
