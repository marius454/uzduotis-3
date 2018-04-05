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

## v0.5
Lyginamas programos greitis naudojant skirtingus konteinerių tipus (vektorius, listus ir dekus). Tikrinama naudojant praeitos programos
sukūrtą 10000 mokinių faila.

Vektorių ir dekų laikai beveik tokie patys, o listai su tokio dydzio failu daugiau nei dvigubai greitesni.

## v1.0
