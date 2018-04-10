# 2 užduotis

## v0.1
Programa leidžia įrašyti mokinio/studento vardą ir atsitiktinai sugeneruoja n pažymiu.
Tada įrašomas egzamino rezultatas ir išvedamas mokinio/studento galutinis balas.

## v0.2
Kas pakito nuo v0.1:

* Galima duomenis įvesti arba iš klaviatūros arba iš tekstinio failo:
  - tekstiniame faile iš pradžių parašomi 2 skaičiai - mokinių skaičius ir namų darbų kiekis. Tada iš eilės rašomi studento pavardė, vardas, visi namų darbų balai, egzamino balas ir kartojama kol išrašomi visi studentai.
* Pažymiai nėra random.
* Galutiniai balai surašyti abecelės tvarka pagal pavardę.
* Galutinis balas rašomas ir vidurkio ir medianos forma.

Šioje versijoje faile dar reikia įrašyti kiek bus mokinių ir kiek nd pažymiu jie turės.

## v0.3
* Nuskaitaint duomenis iš failo nebereikia įrašyti kiek bus mokiniu ir kiek namu darbu pazymiu
* Patikrinama ar failas "kursiokai.txt" egzistuoja
* Nebeleidžia įvesti pažymiu mažesnių už 0 ar didesnių už 10

## v0.4
* Tikrina programos greitį kai ji sugeneruoja input failus, kurie turi 10, 100, 1000, 10000 ir 100000 mokinių įvestis.
(kai yra 100000 mokiniu programa uztrunka virš 2 minučių)
* Galimybė įvesti iš klaviatūros yra užkomentuota ir neveikia, nes nėra reikalinga tikrinant laika kai skaitoma iš failo.

|Mokinių skaičius |Laikas      |
|-----------------|------------|
|10               |0.00920861s |
|100              |0.0460522s  |
|1000             |0.706384s   |
|10000            |7.67177s    |
|100000           |125.201s    |


## v0.5
Lyginamas programos greitis naudojant skirtingus konteinerių tipus (vektorius, listus ir dekus). Tikrinama naudojant praeitos programos
sukūrtą 10000 mokinių faila.

|Konteineris |1 Strategija|
|------------|------------|
|Vektorius   |6.90567s    |
|Listas      |2.59651s    |
|Dekas       |6.8473s     |

Vektorių ir dekų laikai beveik tokie patys, o listai su tokio dydzio failu daugiau nei dvigubai greitesni.

## v1.0
Daro tą ka darė v0.5 bet atskiria i dvi strategijas. Pagal 1 sstrategiją "galvočiai" ir "vargšiukai" atskiriami i 2 konteinerius.
Pagal 2 strategija "vargšiukai" atskiriami į atskirą konteinerį ir ištrinami iš studentų konteinerio.

Taip pat sutvarkytas error handling.

Laikai naudojant 100000 mokinių failą:

|Konteineris |1 Strategija|2 Strategija|
|------------|------------|------------|
|Vektorius   |4.60497s    |7.03768s    |
|Listas      |2.49851s    |4.91976s    |
|Dekas       |2.5689s     |4.72897s    |

Naudojimosi instrukcija: paleidus programa duodami pasirinkimai 1. įvesti duomenis ranka 2. nuskaityti duomenis iš failo 3.
sukurti nauja faila su pasirinktu skaičiu mokinių. Pasirinkus 1 ar 2 išrašomi kiek laiko užtrunka kiekvienas konteineris su abiem strategijomis . Pasirinkus 3 paklausiama kokio dydžio failą norima sukurti ir įrašius grįžtama prie pradinio pasirinkimo.

