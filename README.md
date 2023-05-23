
***Beadandó feladat:***

Blackjack játék szimulálása, a következőképpen külön-külön projektekbe (header fileokkal):

 1. szekvenciálisan megvalósítva
    
  2. POSIX szálakkal megvalósítva
    
3.  OpenMP-vel megvalósítva
    
4.    C#-ban Task Parallel Library segítségével megvalósítva

**A programok futási idejének összehasonlítása**
1. A szálak számának
2. A generálandó 21-es leosztásoknak
**függvénnyében**
**A program leírása:**  

Kétszer generálok 2től 11ig számokat, szimulálva a laphúzást és lemérem hogy hány leosztásból generál ki pontosan 21-et. 

Ugyan ezt párhuzamosítás esetén külön-külön szálakba szervezve generálom ki , amit a szükséges pontosan 21-es generálások számával együtt parancssori argumentumként kell megadni.  

Mivel a pontosan 21 összegű generálások száma különböző időt vehet igénybe, így ezeket az időket átlagolnám és hasonlítanám össze a különböző implementációk esetén.
