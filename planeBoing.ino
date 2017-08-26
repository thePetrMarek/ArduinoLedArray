//Lights lines, shifts them to side and return back

bool planeBoingArray[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

bool planeBoingArrayClear[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

void planeBoingRun() {
  fillUp(1);
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    verticalShiftDown();
  }
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    verticalShiftUp();
  }
  fillUp(0);
  fillLeft(1);
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    horizontalShiftRight();
  }
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    horizontalShiftLeft();
  }
  fillLeft(0);
  fillDown(1);
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    verticalShiftUp();
  }
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    verticalShiftDown();
  }
  fillDown(0);
  fillRight(1);
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    horizontalShiftLeft();
  }
  for (int i = 0; i < 7; i++) {
    show(planeBoingArray, 50);
    horizontalShiftRight();
  }
  fillRight(0);
}

void fillUp(int value) {
  for (int i = 0; i < 8; i++) {
    planeBoingArray[0][i] = value;
  }
}

void fillDown(int value) {
  for (int i = 0; i < 8; i++) {
    planeBoingArray[7][i] = value;
  }
}

void fillLeft(int value) {
  for (int i = 0; i < 8; i++) {
    planeBoingArray[i][0] = value;
  }
}

void fillRight(int value) {
  for (int i = 0; i < 8; i++) {
    planeBoingArray[i][7] = value;
  }
}

void verticalShiftDown() {
  for (int i = 7; i >= 1; i--) {
    for (int j = 0; j < 8; j++) {
      planeBoingArray[i][j] = planeBoingArray[i - 1][j];
    }
  }
  for (int j = 0; j < 8; j++) {
    planeBoingArray[0][j] = 0;
  }
}

void verticalShiftUp() {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 8; j++) {
      planeBoingArray[i][j] = planeBoingArray[i + 1][j];
    }
  }
  for (int j = 0; j < 8; j++) {
    planeBoingArray[7][j] = 0;
  }
}

void horizontalShiftRight() {
  for (int i = 0; i < 8; i++) {
    for (int j = 7 ; j > 0; j--) {
      planeBoingArray[i][j] = planeBoingArray[i][j - 1];
    }
  }
  for (int j = 0; j < 8; j++) {
    planeBoingArray[j][0] = 0;
  }
}

void horizontalShiftLeft() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0 ; j < 7; j++) {
      planeBoingArray[i][j] = planeBoingArray[i][j + 1];
    }
  }
  for (int j = 0; j < 8; j++) {
    planeBoingArray[j][7] = 0;
  }
}


