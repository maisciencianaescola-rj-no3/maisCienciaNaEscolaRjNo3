#define BUZZER 8
#define NUM_TECLAS 12

// Pinos dos botões, na ordem das notas (pino 8 é pulado pq é o buzzer)
const byte pinosBotoes[NUM_TECLAS] = {13, 12, 11, 10, 9, 7, 6, 5, 4, 3, 2, 1};

// Frequências (Hz) correspondentes a cada pino, na mesma ordem - 4ª oitava
const int frequencias[NUM_TECLAS] = {262, 294, 330, 349, 392, 440, 494, 277, 311, 370, 415, 466};

// Nomes das notas, só para referência/debug (opcional)
const char* nomesNotas[NUM_TECLAS] = {"Do", "Re", "Mi", "Fa", "Sol", "La", "Si", "Do#", "Re#", "Fa#", "Sol#", "La#"};

void tom(byte pino, int frequencia, int duracao)
{
  // Calcula o tempo que o pino fica em HIGH e LOW em microssegundos
  long semiPeriodo = 1000000L / (frequencia * 2L);

  // Calcula quantas vezes o ciclo completo deve se repetir dentro da duração (ms)
  long ciclos = (duracao * 1000L) / (semiPeriodo * 2L);

  for (long i = 0; i < ciclos; i++)
  {
    digitalWrite(pino, HIGH);
    delayMicroseconds(semiPeriodo);
    digitalWrite(pino, LOW);
    delayMicroseconds(semiPeriodo);
  }
}

void setup()
{
  pinMode(BUZZER, OUTPUT);

  // Configura todos os botões de uma vez, sem repetir pinMode 12 vezes
  for (int i = 0; i < NUM_TECLAS; i++)
  {
    pinMode(pinosBotoes[i], INPUT_PULLUP);
  }

  // Serial.begin(9600); // descomente se quiser ver no monitor qual nota foi tocada
}

void loop()
{
  // Percorre todos os botões e toca a nota correspondente se algum estiver pressionado
  for (int i = 0; i < NUM_TECLAS; i++)
  {
    if (digitalRead(pinosBotoes[i]) == LOW)
    {
      tom(BUZZER, frequencias[i], 150);
      // Serial.println(nomesNotas[i]); // descomente junto com o Serial.begin acima
    }
  }
}
