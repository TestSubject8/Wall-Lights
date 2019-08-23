int dim = 3;
int ind = LED_BUILTIN;
int bright = 4;
int changePin = 2;
volatile int level = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dim, OUTPUT);
  pinMode(bright, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(changePin, INPUT);
  attachInterrupt(digitalPinToInterrupt(changePin),change,RISING);
  Serial.begin(9600);
  for(int i=0;i<bracket;i++){
    values[i]=0;
  }
}

void change(){
  level++;
  level%=3;
}

void loop() {
//  digitalWrite(ind, HIGH);
  Serial.println(level);
  
  switch(level){
    case 0:
      digitalWrite(dim,LOW);
      digitalWrite(bright,HIGH);
      break;
    case 1:
      digitalWrite(dim,HIGH);
      digitalWrite(bright,LOW);
      break;
    case 2:
      digitalWrite(dim,LOW);
      digitalWrite(bright,LOW);
      break;
    default:
      digitalWrite(dim,HIGH);
      digitalWrite(bright,HIGH);
      break;
  }

  

  //digitalWrite(ind,LOW);
  
}
