Beadandó feladat:  
Blackjack játék szimulálása, a következőképpen külön-külön projektekbe (header fileokkal):  
1-szekvenciálisan megvalósítva  
2-POSIX szálakkal megvalósítva  
3-OpenMP-vel megvalósítva  
4-C#-ban Task Parallel Library segítségével megvalósítva  
Ezt követően a kapott eredményeket excel táblában összehasonlítom.  

A program megvalósítása:  
kétszer generálok 2től 11ig 2számot szimulálva a laphúzást és lemérem hogy hány leosztásból generál ki pontosan 21-et, ugyan ezt párhuzamosítás esetén  
külön-külön szálakba szervezve generálom ki,amit a szükséges pontosan 21-es generálások számával együtt parancssori argumentumként kell megadni, mivel a pontosan 21 összegű  
generálások száma  különböző időt vehet igénybe, így ezeket az időket átlagolnám és hasonlítanám össze a különböző implementációk esetén.  



