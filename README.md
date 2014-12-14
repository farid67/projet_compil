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

Pour les tableaux on peut se simplifier la vie -> instructions pour gestion de tableaux -> http://people.cs.pitt.edu/~xujie/cs447/AccessingArray.htm




-> Grammaire

-> Reconnaissance : instructions d'affectations normales

-> A faire : 
	reconnaitre les commentaires (cf tp2)

	
	
Résumé :

Le code source est lu, la table des symboles ainsi que la liste des quads ;
Les symboles sont crées en fonction de leurs situation dans le code , variables (constantes ou non), nom de tableau (notion de tampon),
 label (pour les branchements)...
les quads sont chainés, et ils sont complétés au fur et à mesure de l'avancement dans la lecture du code
La liste des quads et la table des symboles sont ensuite traités pour générer le code mips correspondant, les tests sont effectués sur le nom des opérations 
pour générer le mips, et les registres sont alloués en fonction du types des arguments;
Par exemple pour les tableaux, lorsqu'on souhaite accéder à un élement via une variable, (tab[i]) on trouvera toujours l'index dans le registre
de manière générale, on aura les opérandes dans $t5 et $t3 , les résultats d'expressions temporaires dans $t6, les résultats dans $t0 


