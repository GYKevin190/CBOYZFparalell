Beadandó feladat:  
Blackjack játék szimulálása, a következő képpen külön-külön fileba:  
1-szekvenciálisan megvalósítva  
2-POSIX szálakkal megvalósítva  
3-OpenMPI-al megvalósítva  
4-C#-ban Task Parallel Library segítségével megvalósítva  
Ezt követően a kapott eredményeket excel táblában összehasonlítom.

A program megvalósítása:
kétszer generálok 2től 11ig 2számot szimulálva a laphúzást és lemérem hogy hány leosztásból generál ki pontosan 21-et, ugyan ezt ezt párhuzamosítás esetén  
külön-külön szálakba szervezve generálom ki, a szükséges pontosan 21-es generálások számát a felhasználótol kérném be, mivel a pontosan 21 összegű generálások száma  
külöbnöző időt vehet igénybe, így ezeket az időket átlagolnám és hasonlítanám össze a különböző implementálások esetén.



