# so_project

Proponuję tworzyć plik z logiem wszędzie gdzie potrzeba w taki sposób:

FILE *f;
f = fopen("demon.log", "a+"); 
if (f == NULL) printf("Wystapil blad przy tworzeniu loga");
.
.
.
fclose(f);

w celu uniknięcia bałaganu. a+ gwarantuje otwarcie z możliwością >dopisywania<, więc powinno być git.
