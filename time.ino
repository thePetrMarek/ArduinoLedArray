//Show time

bool timeArray[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

int index = 0;
int minute = 0;

void timeRun() {
  int i = index / 8;
  int j = index % 8;
  timeArray[i][j] = (timeArray[i][j] + 1) % 2;
  index = (index + 1) % 64;
  minute = (minute + 1) % 60;
  if (minute == 59) {
    invert();
  } else {
    show(timeArray, 1000);
  }
}

void invert() {
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
      timeArray[i][j] = (timeArray[i][j] + 1) % 2;
    }
    show(timeArray, 20);
  }
  show(timeArray, 840);
}
