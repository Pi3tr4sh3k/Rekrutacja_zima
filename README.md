# Rekrutacja-zadanie2
<p>Celem zadania jest wyznaczenie drogi robota przy minimalnym zużyciu energii na danych odcinkach. Każdy typ drogi (czerwony, zielony, niebieski) ma swój koszt przejechania na każdym odcinku. Do celów diagnostycznych koszt czerwonej ścieżki = 5, zielonej = 1.5, niebieskiej = 0.1. Program wykorzystuje algorytm Dijksty do odnajdywania najkrótszej trasy zaczerpnięty ze strony <a href="https://algotree.org/algorithms/single_source_shortest_path/dijkstras_shortest_path_c++/">link</a>.</p>
<ol>
   <h2><li>Rozrysowanie grafu</h2>
  <p>Pierwszym krokiem było rozpisanie grafu dla wszystkich tras. Graf prezentuje się następująco:</p>
   <p><img src=graph.png/></p></li>
   <h2><li>Zasada działania algorytmu</h2>
      <p>Program posługuje się algorytmem Dijkstry do odnajdowania najkrótszej ścieżki.
         Jako pierwsze zakładam, że wszystkie odległości od wszystkich punktów poza startowym wynoszą nieskończoność.
         Tworzymy wektor, który przechowuje odległości od pkt wyjściowego wraz z aktualnym punktem.
         Zwalniamy utworzoną parę i porównuję długości ścieżek tworząc kolejne pary tak jak wyżej. Badane są wszystkie kombinacje wyjściowe od początkowego punktu.
         Kolejno są brane pod badanie następne pary w wektorze i badane wszystkie ścieżki.
         Proces trwa do całkowitego zwolnienia wektoraz utworzonych par.
         W trakcie wykonywania funkcji w przypadku znalezienia krótszej ścieżki zostaje ona zastąpiona w tablicy dist[].
         Na samym końcu jest zwracana odległość do konkretnego wierzchołka który jest badany.</p></li>
    <h2><li>Sprawdzenie poprawności wykonania algorytmu na grafie</h2>
      <p>Dla danych r=5, g=1.5, b=0.1, dla danego ciągu BABDC program powinien zwracać wartość 21,5. Następnie sumując długości ścieżek sprawdzam zgodność z rozwiązaniem.</p>
   <p><img src="spr1.JPG/"></p>
   <p><img src="spr2.JPG/"></p>
   <p><img src="spr3.JPG/"></p>
   <p><img src="spr4.JPG/"></p></li>
   <p>W programie dla podanych wartości diagnostycznych wyniki się pokrywają</p>
   <p><img src="fin.PNG"/></p>
</ol>
   
   
