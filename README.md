Projet Dispositif de Recensement d'Insectes Rampants en Milieu Urbain 2018-2019
Auteurs : Marc Gourayeb, Jean-François Lendresse, Adrien Vache, Pierre Heran, Pierre Brochard, Laure Turcati, Jérôme Gaudin, Baptiste Fabre

[Université de Bordeaux](https://www.u-bordeaux.fr/) - [Particitae](http://particitae.fr/) - [Celia](http://www.celia.u-bordeaux1.fr)

# Résumé

Le dispositif automatique pour le recensement d’insectes rampants est un projet réalisé par les étudiants du Master Professionnel Instrumentation Physique de l’Université de Bordeaux en collaboration avec PARTICITAE.
PARTICITAE est un observatoire scientifique à la disposition de tous qui accompagne la transition environnementale et qui construit une connaissance systémique de l’environnement urbain.
Le dispositif développé et conçu par les étudiants spécialistes de l’instrumentation physique a pour but de caractériser la distribution et l’abondance des différents groupes d’insectes sur le sol en milieu urbain.
Le projet s’articule ainsi en trois axes :
-   La conception mécanique du dispositif

-   Sa conception électronique

-   la programmation servant le fonctionnement et l’automatisation du système.

----------
# Liste du Matériel

| Quantité | Matériel                                                        | Références     | 
|----------|-----------------------------------------------------------------|----------------|
| 1        | Kit Raspberry Pi 3 B+                                           | 35930          |
| 1        | Carte Arduino UNO                                               | 25950          |
| 2        | Capteur humidité / Température (Grove 101020019)                | 31292          |
| 1        | Détecteur de distance IR (Grove 101020175)                      | 35303          |
| 2        | LED 8 mm LD08B                                                  | 3044           |
| 1        | Caméra 8 Mpx pour Raspberry (RB-CAMERA-V2)                      | 35368          |
| 1        | Black Eye Lens Objectif Universel pour Smartphone – Grand Angle | KBBEYEPKI-0194 |
| 1        | Cordon 1 m USB2MM-1                                             | 49108          |
| 1        | Pack de 10 câbles de connexion M/F BBJ21                        | 12335          |
| 1        | Pack de 10 câbles de connexion M/M BBJ8                         | 12313          |
| 1        | Carte mémoire Micro SD                                          |                |
|          | Panneaux de fibre composite*                                    |                |
|          | Vis :                                                           |                |
| 22       | Ø 5 x L 40 mm                                                   |                |
| 40       | Ø 4 x L 25 mm                                                   |                |
| 60       | Ø 3,5 x L 12 mm                                                 |                |

* La fibre composite est un matériau composé à 30% de mélange de fibres végétales, 45% de polymères et 25% de résine/colle. Les panneaux de fibre composite sont notamment utilisés dans le milieu nautique pour
leurs propriétés de résistance à une humidité élevé et aux changements de température : tableau de bords de barques, bateaux, barges et pontons. Ce matériau est extrêmement facile à dimensionner car il se travail comme le bois : matériau léger, facile à découper et à visser.

----------
# Dispositif et processus

L’insecte dès qu'il entre dans la boîte est détecté par un capteur de mouvement qui déclenche le processus suivant : 
- les LEDs flashs s’allument
- la caméra prends une photo de l’insecte,
- les capteurs relèvent les conditions d’humidité et de température (intérieur & extérieur), ces données sont centralisées sur la carte mémoire et sont envoyées, accompagnées de la photo, sur un serveur de Particitae via une connexion Wifi.

![Processus](https://raw.githubusercontent.com/particitae/DRIRMU/master/Images/Processus.png)

Pour réaliser à bien la fabrication, vous aurez besoin de certains outils : un fer à soudé, un tournevis, un écran et son câble HDMI, un clavier et une souris.
Les étapes d’électronique et de programmation dépendent l’une de l’autre. L’étape mécanique peut être réalisée à part.

#Électronique
La partie qui va suivre consiste à réaliser tous les branchements nécessaires. Vous aurez besoin de vous munir d’un fer à souder.


Il est nécessaire dans un premier temps de réaliser des ponts de soudure sur les deux capteurs d’humidité/température, afin d’avoir une même alimentation pour les deux ![Figure 2](https://upload.wikimedia.org/wikipedia/commons/5/55/Montage-Electronique.png), 

puis sur les deux LEDs, afin qu’elles soient branchées en série ![Figure 3](https://upload.wikimedia.org/wikipedia/commons/c/c7/Montage_Electronique_2.png).

Pensez à recouvrir les ponts par une gaine isolante.

Voici le plan électronique de l’ensemble de l’installation :
![Plan Electronique](https://raw.githubusercontent.com/particitae/DRIRMU/master/Images/Sch%C3%A9ma-Electronique.png)

Il est nécessaire de commencer par effectuer les branchements relatifs à la **carte Arduino** en suivant le plan électronique ci-dessus.
L’alimentation secteur alimente la **carte Raspberry**, sur laquelle on connecte la **caméra Raspberry** (qui fera office d’appareil photo). 
La micro carte SD, contiendra les scripts python et toutes les données.
La **carte Arduino** est alimentée par la **carte Raspberry** via USB.

*Les câbles rouges connectent les alimentations, les câbles noirs connectent les masses et les câbles jaunes sont les voies d’entrées-sorties digitales
Il peut être judicieux d’ajouter une résistance d’une cinquantaine d’Ohm afin de réduire la puissance des LEDs.*

**Attention le bon fonctionnement de l'ensemble dépend de la réussite de cette étape. Veillez à réaliser les bons branchements.**

# Programmation

## Arduino

La carte Arduino est le centre de commande des différents capteurs et du flash de l’appareil photo (par LED). Cette carte connectée à l’ordinateur propose d’enregistrer un script, des ordres pour son utilisation.
![lien vers le fichier source de l'Arduino](https://raw.githubusercontent.com/particitae/DRIRMU/master/Arduino/Insectes_Arduino.ino)

## Raspberry

La **carte Raspberry** va servir de centre de commande et d’alimentation au dispositif. C’est elle qui assure l’alimentation de la carte Arduino et de tous les capteurs.
Un script Python va relier, centraliser, enregistrer et envoyer par wifi sur le serveur toutes les données reçues.

*Pour les prochaines étapes, afin de manipuler la carte Raspberry, il faudra vous munir d’un clavier, d’une souris ainsi que d’un écran (ou projecteur). Veillez à connecter la carte Raspberry à un réseau wifi domestique ayant une portée suffisante lors de l’utilisation.*

L’achat d’une carte Raspberry PI ne suffit pas à son utilisation immédiate. Il faut dans un premier temps installer Raspian sur une carte micro SD et faire les premières configurations :
