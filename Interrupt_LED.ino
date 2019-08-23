int dim = 2;
int ind = LED_BUILTIN;
int bright = 3;

int pot = A6;

int threshold_low = 300;
int threshold_high = 600; 
char level;
int val, vall;
const int bracket = 10;
int values[bracket];
int index = 0;
int total = 0;
int avg;

void setup() {
  // put your setup code here, to run once:
  pinMode(dim, OUTPUT);
  pinMode(bright, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
  for(int i=0;i<bracket;i++){
    values[i]=0;
  }
}

void loop() {
  digitalWrite(ind, HIGH);

  val = analogRead(pot);

  total = total - values[index];
  total = total + val;
  avg = total / bracket;
  values[index] = val;
  index++;
  index%=bracket;

  delay(50);
  vall = 1000 - avg;

  if(vall<threshold_low){
    level = 'a';
  }
  if(vall<threshold_high && vall>=threshold_low){
    level = 'b';
  }
  if(vall>=threshold_high){
    level = 'c';
  }

//  Serial.print(val);
//  Serial.print(" ,");
//  Serial.print(vall);
//  Serial.print(" ,");
  Serial.println(level);
  
  switch(level){
    case 'a':
      digitalWrite(dim,LOW);
      digitalWrite(bright,HIGH);
      break;
    case 'b':
      digitalWrite(dim,HIGH);
      digitalWrite(bright,LOW);
      break;
    case 'c':
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
