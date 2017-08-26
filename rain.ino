//Rain effect

bool rain_array[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

void rainRun() {
  int randNumber = random(0, 4);
  for (int i = 0; i < randNumber; i++) {
    int randX = random(0, 8);
    rain_array[0][randX] = 1;
  }
  show(rain_array, 100);
  shift();
}

void shift() {
  for (int i = 7; i >= 1; i--) {
    for (int j = 0; j < 8; j++) {
      rain_array[i][j] = rain_array[i - 1][j];
    }
  }
  for (int j = 0; j < 8; j++) {
    rain_array[0][j] = 0;
  }
}
