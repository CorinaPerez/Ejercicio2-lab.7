long randNumber;
String inputString;

void setup(){
  Serial.begin(115200);
  randomSeed(analogRead(0));
  }

void loop(){
  delay(100);
  SerialEvent();
  }

void SerialEvent(){
  while(Serial.available()){
    char inputChar = Serial.read();
    inputString += inputChar;
    }
    if(inputString.indexOf("getValue")>=0){
      randNumber = random(100);
      String json_data = "{\"Sensor_id\":\"3E24R\",\"Value\":" + (String)randNumber + "}";
      Serial.println(json_data);  
    } 
    inputString = "";
  }
