projet_compil
=============

Projet compilation - StenC


/**************
NOTE IMPORTANTE
***************/

Pour les tests, faire :

make

cat stenc_minimalist.txt | ./a.out > test.s

La sortie sera redirigée vers un fichier .s qui pourra être utiliser avec spim

à terme, passer le nom du fichier en argument et redirigier le tout vers le même fichier avec l'extension voulue (.s) 

Les fichiers de test intérmédiaires sont disponibles dans le répertoire Tests/ , un fichier readme.txt explique les différentes étapes 





-> Grammaire

-> Reconnaissance : instructions d'affectations normales

-> A faire : 
	reconnaitre les commentaires (cf tp2)
	reconnaitre les expressions arithmétiques/booléennes et générer les quads correspondants
