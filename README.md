# Semestrální práce PJC 2023 - Matouš Najman
## Zadání - Minimální kostra (minimum spanning tree)

Minimální kostry mají široké využití - od návrhů tras elektrického vedení, přes vytváření routovacích tabulek v počítačových sítích až po shlukování (clustering) bodů v analýze dat či detekce útvarů v počítačovém vidění. Doporučujeme použít Borůvkův algoritmus. Na výstupu programu bude seznam vrcholů minimální kostry a její cena nebo přímo popis celého grafu pro Graphviz, s barevně odlišenými vrcholy v kostře.

## Realizace

Implementována je jen jednovláknová verze programu. Je také možnost přidání argumentu ```--help```, který vypíše informace o formátu inputu grafu.

Pro správné fungování programu je potřeba vložit spojitý graf a dodržet formát vstupních dat. Program umožní uživateli zadat graf a pomocí Borůvkova algoritmu nalezne minimální kostru grafu. Na výstupu vrátí váhu minimální kostry a jednotlivé hrany kostry.

### Formát vstupních dat
```
H V
a b val1
c d val2
...
```
- **H**:  Počet hran v grafu
- **V**:  Počet vrcholů v grafu
- **a, b, c, d**:   vrcholy
- **val1, val2**:   hodnota příslušné hrany

Například:
```
7 8
0 1 1
1 2 2
2 3 3
3 4 4
4 5 5
5 6 6
6 7 7
```
Další testovací data lze najít ve složce ```inputs``` a k ním příslušné výstupy ve složce ```outputs```.  
