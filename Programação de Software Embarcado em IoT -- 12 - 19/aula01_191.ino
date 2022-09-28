// C++ code
//

#define ledVermelho 6
#define ledAmarelo 5
#define ledVerde 3

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
}

void loop()

{
  	// Sinal vermelho
	digitalWrite(ledVermelho, 1);	//acende o LED vermelho
  	digitalWrite(ledAmarelo, 0);	//apaga o LED amarelo
  	digitalWrite(ledVerde, 0);	//apaga o LED verde
  	delay(3000);
  
  	// Sinal Verde
	digitalWrite(ledVermelho, 0);	//apaga o LED vermelho
  	digitalWrite(ledAmarelo, 0);	//apaga o LED amarelo
  	digitalWrite(ledVerde, 1);	//acende o LED verde
  	delay(4000);
  	
  	// Sinal Amarelo
	digitalWrite(ledVermelho, 0);	//apaga o LED vermelho
  	digitalWrite(ledAmarelo, 1);	//acende o LED amarelo
  	digitalWrite(ledVerde, 0);	//apaga o LED verde
  	delay(1300);

}