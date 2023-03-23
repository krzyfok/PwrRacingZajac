# Zajac
Na początku programu generowana jest mapa zgodnie z wczytanymi danymi, oraz znajdowana jest pozycja zająca i nory.
Następnie zaczynając od pozycji zająca poszukiwane są wszytskie pola które spełniają warunki skoku, nie są kopcami kreta i mieszczą się w mapie. Zapisywane są one do tabeli "pola", do tabeli "wykonaneskoki" zapisywane są przesunięcia jakie zosatały wykonane w danym skoku. Pole które zostało już wpisane do tabeli zostaje zablokowane poprzez zmianę litery na "b". Następnie dla kolejnych pól w tabeli "pola" wykonywana jest ta sama procedura (szukanie pól spelniających wymagania, dodawanie do tabli). Program konczy się gdy do tabeli zostaną dodane współrzędne nory. Wynik jest uzyskowany poprzez oddtwarzenie skoków jakie zostały wykonane za pomocą tabel "pola" oraz "wykonaneskoki" (np. nora ma współrzędne 3,3 i w tabeli pola została dodana z indeksem 8, w tabeli z danymi skoków szukany jest skok 8 i odejmowany od wspólrzednych pola[8]. Wynik jest szukany w tabeli pola i indeks 8 jest zastępowany znalezionym indeksem. Całość jest powtarzana aż do cofnięcia się do pozoycji początkowej zająca). Zachowanie kolejności przy wpisywaniu do tabeli "pola" i wykonywaniu algorytmu gwarantuje ze do pola zając dostał się najkrótszą możliwą drogą. Decyzja o przerwaniu programu z powodu braku mozliwosci dojscia do nory podejmowana jest gdy ilosc pól w tabeli "pola" będzie mniejsza niż wartości iteratora "j" który wykorzystywany jest do przypisywania kolejnych wartosci pól na ktorych ma byc wykonany algorytm. (Tabele "pola" i "wykonaneskoki" powinne być dynamiczne, niestety zabrakło mi czasu)