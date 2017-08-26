void setup() {
  // initialize all pins as output
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

//Programs to run
typedef void (*vvFunction)();
vvFunction functions[] =  {diagonalRun, gameOfLifeRun, rainRun, planeBoingRun, sendPixelRun, sineRun, timeRun};
int functionIndex = 0;

void loop() {
  // Run the programs in the loop
  unsigned long startTime = millis();
  unsigned long currentTime = millis();
  unsigned long programDuration = 120000;
  while (currentTime - startTime < programDuration) {
    currentTime = millis();
    functions[functionIndex]();
  }
  functionIndex = (functionIndex + 1) % (sizeof(functions) / sizeof(vvFunction));
}
