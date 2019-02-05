#include "DHT.h"
#define DHTPIN 2 //capteur humidité température intérieur
#define DHTPIN 4 //capteur humidité température extérieur    
#define DHTTYPE DHT22 //défini le type de capteur (ici le capteur Grove est un DHT22)
DHT dht1(DHTPIN, DHTTYPE); //défini le capteur intérieur
DHT dht2(DHTPIN, DHTTYPE); //défini le capteur extérieur
const int L1 = 7; //led sur l'analogique 7
void setup()  { //initialisation du code
    Serial.begin(9600);
    pinMode(3,INPUT); //défini le capteur de présence sur l'entrée analogique 3
    dht1.begin(); //démarre l'un des capteurs humidité température
    dht2.begin(); //démarre le second capteur humidité température
    pinMode(L1, OUTPUT);
}
void loop()  {
    while(1)  {
        delay(500); //délai nécesaire car la prise d'humidité et de température prend 250ms
        if(digitalRead(3)==LOW)  { //la suite du code se déclenche si le capteur lui renvoit une présence sur le trajet du rayon infrarouge
            float h1 = dht1.readHumidity(); //le programme lit les valeurs renvoyées par le capteur 
            float t1 = dht1.readTemperature(); //le programme lit les valeurs renvoyées par le capteur
            float h2 = dht2.readHumidity(); //le programme lit les valeurs renvoyées par le capteur
            float t2 = dht2.readTemperature(); //le programme lit les valeurs renvoyées par le capteur 
                Serial.print(h1); //affiche la valeur d'humidité intérieur sur la console
                Serial.print(" ");
                Serial.print(t1); //affiche la valeur de température intérieur sur la console
                Serial.print(" ");
                Serial.print(h2); //affiche la valeur d'humidité extèrieur sur la console
                Serial.print(" ");
                Serial.print(t2); //affiche la valeur d'humidité extèrieur sur la console
                Serial.println(" "); //retour à la ligne après prise de données
            digitalWrite(L1, HIGH); //pour faire simple : HIGH=pas d'insecte détecté ; LOW=insecte détecté
            delay(2000); //délai de 2000ms entre 2 lectures du signal renvoyé par le capteur
            digitalWrite(L1, LOW); 
            if (isnan(t1) || isnan(h1)) 
            {
                Serial.println("Echec de lecture"); //vérifie si le retour est bien valide, s'il affihe Nan il y a surement un problème 
            } 
            else 
            {
                
            }
        }
        else  {
        }
    }
}
