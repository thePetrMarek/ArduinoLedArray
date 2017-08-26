//Sending pixel from top to bottom and back

bool sendPixelArray[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

void sendPixelRun() {
  if (isEmptySendPixel()) {
    initialize();
  }
  show(sendPixelArray, 100);
  movePixel();
}

bool isEmptySendPixel() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (sendPixelArray[i][j] == 1) {
        return false;
      }
    }
  }
  return true;
}

void initialize() {
  for (int i = 0; i < 8; i++) {
    int randNumber = random(0, 2);
    if (randNumber == 0) {
      sendPixelArray[0][i] = 1;
    } else {
      sendPixelArray[7][i] = 1;
    }
  }
}

void movePixel() {
  int randNumber = random(0, 8);
  if (sendPixelArray[0][randNumber] == 1) {
    movePixelDown(randNumber);
  } else {
    movePixelUp(randNumber);
  }
}

void movePixelDown(int index) {
  for (int i = 0; i < 7; i++) {
    sendPixelArray[i][index] = 0;
    sendPixelArray[i + 1][index] = 1;
    show(sendPixelArray, 50);
  }
}

void movePixelUp(int index) {
  for (int i = 8; i > 0; i--) {
    sendPixelArray[i][index] = 0;
    sendPixelArray[i - 1][index] = 1;
    show(sendPixelArray, 50);
  }
}
