int BT_UP 	= 12;
int BT_DOWN = 2;
int VALOR = 0;
int VALOR_TEMP = 0;

int LE_U = 7;
int LE_D = 6;
int LE_C = 5;
int LE_M = 4;

int A_DT = 8;
int B_DT = 9;
int C_DT = 10;
int D_DT = 11;

int VALOR_M = 0;
int VALOR_C = 0;
int VALOR_D = 0;
int VALOR_U = 0;


void seta_ABCD (int entrada){
  if (entrada == 0){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, LOW);
  	digitalWrite(B_DT, LOW);
    digitalWrite(A_DT, LOW);}
  
  if (entrada == 1){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, LOW);
  	digitalWrite(B_DT, LOW);
    digitalWrite(A_DT, HIGH);}
  
  if (entrada == 2){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, LOW);
  	digitalWrite(B_DT, HIGH);
    digitalWrite(A_DT, LOW);}
  
  if (entrada == 3){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, LOW);
  	digitalWrite(B_DT, HIGH);
    digitalWrite(A_DT, HIGH);}
  
  if (entrada == 4){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, HIGH);
  	digitalWrite(B_DT, LOW);
    digitalWrite(A_DT, LOW);}
  
  if (entrada == 5){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, HIGH);
  	digitalWrite(B_DT, LOW);
    digitalWrite(A_DT, HIGH);}
  
  if (entrada == 6){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, HIGH);
  	digitalWrite(B_DT, HIGH);
    digitalWrite(A_DT, LOW);}
  
  if (entrada == 7){
    digitalWrite(D_DT, LOW);
  	digitalWrite(C_DT, HIGH);
  	digitalWrite(B_DT, HIGH);
    digitalWrite(A_DT, HIGH);}
  
  if (entrada == 8){
    digitalWrite(D_DT, HIGH);
  	digitalWrite(C_DT, LOW);
  	digitalWrite(B_DT, LOW);
    digitalWrite(A_DT, LOW);}
  
  if (entrada == 9){
    digitalWrite(D_DT, HIGH);
  	digitalWrite(C_DT, LOW);
  	digitalWrite(B_DT, LOW);
    digitalWrite(A_DT, HIGH);}}





void ATUALIZA_DISP (void){
  
  VALOR_M = VALOR / 1000;
  VALOR_C = (VALOR / 100) - (10*VALOR_M);
  VALOR_D = (VALOR / 10) - (10*VALOR_C) - (100*VALOR_M);
  VALOR_U = VALOR - (10*VALOR_D) - (100*VALOR_C) - (1000*VALOR_M);
  
  seta_ABCD (VALOR_U);
  
  digitalWrite(LE_U, LOW);
  delay(10);
  digitalWrite(LE_U, HIGH);
  
  seta_ABCD (VALOR_D);
  	
  digitalWrite(LE_D, LOW);
  delay(10);
  digitalWrite(LE_D, HIGH);
  
  seta_ABCD (VALOR_C);
  	
  digitalWrite(LE_C, LOW);
  delay(10);
  digitalWrite(LE_C, HIGH);
  
  seta_ABCD (VALOR_M);
  	
  digitalWrite(LE_M, LOW);
  delay(10);
  digitalWrite(LE_M, HIGH);
}
  



void setup(){
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  
  pinMode(LE_U, OUTPUT);
  pinMode(LE_D, OUTPUT);
  pinMode(LE_C, OUTPUT);
  pinMode(LE_M, OUTPUT);
  pinMode(D_DT, OUTPUT);
  pinMode(C_DT, OUTPUT);
  pinMode(B_DT, OUTPUT);
  pinMode(A_DT, OUTPUT);
  
  digitalWrite(A_DT, LOW);
  digitalWrite(B_DT, LOW);
  digitalWrite(C_DT, LOW);
  digitalWrite(D_DT, LOW);
  
  digitalWrite(LE_U, LOW);
  digitalWrite(LE_D, LOW);
  digitalWrite(LE_C, LOW);
  digitalWrite(LE_M, LOW);
  
  delay(10);
  
  digitalWrite(LE_U, HIGH);
  digitalWrite(LE_D, HIGH);
  digitalWrite(LE_C, HIGH);
  digitalWrite(LE_M, HIGH);
  
  
  
  
}

void loop(){
  
  if (VALOR != VALOR_TEMP){
    Serial.println(VALOR);
    ATUALIZA_DISP ();
    VALOR_TEMP = VALOR;}
  
  if (digitalRead(BT_UP) == 0){
    delay(20);
    VALOR = VALOR + 1;
    digitalWrite(13,HIGH);
    while(digitalRead(BT_UP) == 0){}
    delay(20);
    digitalWrite(13,LOW);}
  
  if (digitalRead(BT_DOWN) == 0){
    delay(20);
    if (VALOR >= 1){
      VALOR = VALOR - 1;}
    digitalWrite(13,HIGH);
    while(digitalRead(BT_DOWN) == 0){}
    delay(20);
    digitalWrite(13,LOW);}
  
  
}