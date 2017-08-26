// Mapping of Arduino pins to rows and columns
int row_mapping[] = {A2, A1, 2, 3, A0, A3, A4, A5};
int column_mapping[] = {4, 5, 8, 9, 11, 10, 7, 6};

// Turn on the lights accordint to the pattern in leds array
void show(bool leds[8][8], unsigned long duration) {
  unsigned long startTime = millis();
  unsigned long currentTime = millis();
  while (currentTime - startTime < duration) {
    currentTime = millis();
    for (int i = 0; i < 8; i++) {
      digitalWrite(column_mapping[i], LOW);
      digitalWrite(row_mapping[0], leds[0][i]);
      digitalWrite(row_mapping[1], leds[1][i]);
      digitalWrite(row_mapping[2], leds[2][i]);
      digitalWrite(row_mapping[3], leds[3][i]);
      digitalWrite(row_mapping[4], leds[4][i]);
      digitalWrite(row_mapping[5], leds[5][i]);
      digitalWrite(row_mapping[6], leds[6][i]);
      digitalWrite(row_mapping[7], leds[7][i]);
      delayMicroseconds(250);
      digitalWrite(row_mapping[0], LOW);
      digitalWrite(row_mapping[1], LOW);
      digitalWrite(row_mapping[2], LOW);
      digitalWrite(row_mapping[3], LOW);
      digitalWrite(row_mapping[4], LOW);
      digitalWrite(row_mapping[5], LOW);
      digitalWrite(row_mapping[6], LOW);
      digitalWrite(row_mapping[7], LOW);
      delayMicroseconds(50);
      digitalWrite(column_mapping[i], HIGH);
    }
  }
}
