const int PSpin = A0; // palm sensor (clockwise/close) is connected to pin A0
const int SSpin = A1;// side sensor (anticlcokwise/open) is connected to pin A1

const int PWMpin = 5; // input to motordriver (speed)
const int input1pin = 6; // input to motordriver (direction) 
const int input2pin = 7; // input to motordriver (direction)

const int threshold = 200; //value to determin if sensor is pressed
  
const unsigned long spinTime = 3000; //motor spins for 3seconds

int prevPS = 0; // last signal from palm
int prevSS = 0; //last signal from side
int lastSensor = 0; //which sensor was pressed last

bool motorRunning = false; // is the motor currently running
unsigned long motorStartTime = 0; // how long the motor has been running

void startMotor() { //when start motor is used run this code:
  motorRunning = true; //motor is running
  motorStartTime = millis(); //note the time the motor started

  if(lastSensor == 1){ //if the last sensor to turn the motor on was the palm then motor spins clockwise(LOW,HIGH)
  digitalWrite(input1pin, LOW);
  digitalWrite(input2pin, HIGH);
  }

  else if(lastSensor == 2){ // if the last sensor to turn on the motor was the side the motor spins aniclockwise(HIGH,LOW)
  digitalWrite(input1pin, HIGH);
  digitalWrite(input2pin, LOW);
  }
  analogWrite(PWMpin, 180); //sets the speed of the motor
}

void stopMotor(){ //when stop motor is used run this code:
  motorRunning = false; //motor isnt running
  digitalWrite(input1pin, LOW);
  digitalWrite(input2pin, LOW);
  analogWrite(PWMpin, 0); // motor speed is 0
}

void setup() {
  pinMode(PWMpin, OUTPUT); // output from arduino to motordriver
  pinMode(input1pin, OUTPUT); // output from arduino to motordriver
  pinMode(input2pin, OUTPUT); // output from arduino to motordriver 
}

void loop() {

  int PS = analogRead(PSpin); //takes reading from palm sensor
  int SS = analogRead(SSpin); //takes reading from side sensor

  bool PSactive = PS > threshold; //is palm sensor pressed
  bool SSactive = SS > threshold; //is side sensor pressed

  bool prevPSactive = prevPS > threshold; //was the palm sensor pressed last cycle
  bool prevSSactive = prevSS > threshold; // was the side sensor pressed last cycle 

  if(PSactive && !prevPSactive && !motorRunning) //if palm sensor is pressed now but wasnt last cycle and the motor isnt running then:
  lastSensor = 1; //last sensor to start motor was palm
  startMotor(); //starts motor

  if(SSactive && !prevSSactive && !motorRunning) //if palm sensor is pressed now but wasnt last cycle and the motor isnt running:
  lastSensor = 2; //last sensor to start motor was side
  startMotor(); //starts motor

  if(motorRunning && millis()-motorStartTime >= spinTime){ // if the motor is running and has been on for the run time then:
    stopMotor(); //stops motor
  }
}
