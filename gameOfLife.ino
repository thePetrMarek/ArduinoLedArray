//Game of life simulation

bool play_field[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

bool all_true[8][8] = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
};

bool all_false[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

unsigned long startTime;

void gameOfLifeRun() {
  //Run simulation
  simulate();
  show(play_field, 250);
  //If the field is empty or the simulation runs more than 10s, than restart it
  if (isEmpty() || millis() - startTime > 10000) {
    startTime = millis();
    show(all_true, 1000);
    show(all_false, 1000);
    addRandom();
  }
}


void simulate() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int surroundings = calculateSurroundings(i, j);

      if (surroundings < 2) {
        play_field[i][j] = false;
      } else if (surroundings == 3) {
        play_field[i][j] = true;
      }
      else if (surroundings > 3) {
        play_field[i][j] = false;
      }
    }
  }
}

int calculateSurroundings(int i, int j) {
  int surroundings = 0;
  int startPosX = (i - 1 < 0) ? i : i - 1;
  int startPosY = (j - 1 < 0) ? j : j - 1;
  int endPosX =   (i + 1 > 7) ? i : i + 1;
  int endPosY =   (j + 1 > 7) ? j : j + 1;

  // See how many are alive
  for (int rowNum = startPosX; rowNum <= endPosX; rowNum++) {
    for (int colNum = startPosY; colNum <= endPosY; colNum++) {
      if (play_field[rowNum][colNum] == true) {
        if (i == rowNum && j == colNum) {
          continue;
        }
        surroundings++;
      }
    }
  }
  return surroundings;
}

bool isEmpty() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (play_field[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void addRandom() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (random(3) == 0) {
        play_field[i][j] = true;
      }
    }
  }
}


