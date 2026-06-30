// C++ code
//
int t_vermelho = 0;

int t_amarelo = 0;

int t_verde = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  t_vermelho = 2;
  t_amarelo = 1;
  t_verde = 2;
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  delay(1000 * t_vermelho); // Wait for 1000 * t_vermelho millisecond(s)
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  delay(1000 * t_amarelo); // Wait for 1000 * t_amarelo millisecond(s)
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  delay(1000 * t_verde); // Wait for 1000 * t_verde millisecond(s)
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
}