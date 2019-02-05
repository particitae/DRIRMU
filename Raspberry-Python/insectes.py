# -*- coding: utf-8 -*-
import serial # ligne 1
import time
import requests
import datetime

camera=picamera.PiCamera() # ligne 5
camera.resolution=(2592,1944) # Paramètrage de la qualité de l'image
ser=serial.Serial('/dev/ttyACMO',9600) # ce sont les données que l'on reçoit de l'Arduino
true='insecte detecte'
now=datetime.datetime.now() 
y=ser.readline() # ligne 10
while true: # condition qui démarre la capture de données
    if ser.readline() : 
	tmp=str(datetime.datetime.now()) # variable qui contient l'heure de la capture
        camera.capture(tmp +'.jpg') #déclenchement de la photo
        x=y.decode("utf-8") # ligne 15 
        z=x.split(" ") # séparation des données relevées par les capteurs
        humin,tempin,humout,tempout=z[0],z[1],z[2],z[3]
        print(humin,tempin,humout,tempout) # optionnel, permet de voir le résultat des mesures sur le compiler
        r=requests.post("http://data.particitae.fr/communication.php", # envoi de donnée sur serveur par requête Post
        data={'identification': 1, 'temperature_interieur': tempin, 'temperature_exterieur': tempout, 'humidite_interieur': humin, 'humidite_exterieur': humout, 'date' : now }) # ligne 20
	file = {'file': open(tmp + '.jpg',"rb")} # envoi de la photo sur le serveur
        s= requests.post("http://data.particitae.fr/communication.php", files = file) 
