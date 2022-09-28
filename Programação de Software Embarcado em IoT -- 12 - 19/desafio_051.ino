#define botao 2
#define ledVermelho 3
#define ledAmarelo 5
#define ledVerde 6
#define buzzer 7
#define potenciometro 14
#define ldr 15
unsigned long relogio = millis();
int tempoVermelho = 1000;
int tempoVerde = 2000;
int tempoAmarelo = 1000;
byte brilho = 255;
byte status;	//0 vermelho; 1 verde; 2 amarelo
void setup()
{
  //definir a porta 2 (push button) como entrada
  pinMode(botao, INPUT_PULLUP);
  //definir as portas dos LEDs como saida
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(potenciometro, INPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
  relogio = millis();
  amarelo();
}
void loop()
{
  brilho = map(analogRead(ldr),1023,0,51,255);
  tempoVermelho = map(analogRead(potenciometro),0,1023,2000,5000);
  if (status == 1 && digitalRead(botao)==0)
  {
    Serial.println("Botao de travessia acionado!");
    relogio = millis();
    amarelo();
  }
  if (status == 2 && millis()-relogio>=tempoAmarelo)
  {
    relogio = millis();
    vermelho();
  }
  if (status == 0 && millis()-relogio>=tempoVermelho)
  {
    relogio = millis();
    verde();
  }
  if (status == 1 && millis()-relogio>=tempoVerde)
  {
    relogio = millis();
    amarelo();
  }
}
void vermelho()
{
  status=0;
  noTone(buzzer);
  Serial.println("Semaforo vermelho");
  analogWrite(ledVermelho, brilho);	//acende o LED vermelho
  analogWrite(ledAmarelo, 0);		//apaga o LED amarelo
  analogWrite(ledVerde, 0);			//apaga o LED verde
}
void verde()
{
  status=1;
  tone(buzzer,1500);
  Serial.println("Semaforo verde");
  analogWrite(ledVermelho, 0);		//apaga o LED vermelho
  analogWrite(ledAmarelo, 0);		//apaga o LED amarelo
  analogWrite(ledVerde, brilho);	//acende o LED verde
}
void amarelo()
{
  status=2;
  tone(buzzer,300);
  Serial.println("Semaforo amarelo");
  analogWrite(ledVermelho, 0);		//apaga o LED vermelho
  analogWrite(ledAmarelo, brilho);	//acende o LED amarelo
  analogWrite(ledVerde, 0);			//apaga o LED verde
}