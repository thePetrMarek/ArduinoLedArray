//Show sine curve

bool sineArray[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

int counter = 0;

void sineRun() {
  sineClean();
  for (int i = 0; i < 8; i++) {
    int pos = (int)(sin((i + counter) * 0.5) * 4 + 4);
    sineArray[pos][i] = 1;
  }
  show(sineArray, 100);
  counter = (counter + 1) % 100000;
}

void sineClean() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      sineArray[i][j] = 0;
    }
  }
}
