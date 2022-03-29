# Задача №111 Сложное метро

## Описание решения
Очевидно, что в данной задаче удобно работать с метро как с графом. 
(вершины=станции, ребра=пути между станциями) 

Также заранее переведем информацию о времени прибытия поездов на станции в более удобный формат.
А именно в каждом ребре будем хранить массив линейных функций (kx+b). 
Каждая такая функция означает, что по этому ребру проходит ветка метро. 
И свободный член (b) функции равен времени прибытия первого поезда, 
а k равен интервалу на этой ветке.

Далее поймем, что если мы знаем, что прибудем на станцию в момент t 
и хотим на соседнюю станцию y, то за O(*количество веток к y*) можем 
получить минимальное время прибытия на любую из соседних станций.
(по линейным функциям написанным на ребре)

Все это позволяет нам свести задачу к обычному поиску кратчайшего пути 
в взвешенном графе.

Одно из решение такой задачи - алгоритм Дейкстры. 
Именно он и реализован в решении.

## Немного документации

Чтобы создать объект Subway в конструктор передаются:

1) количество вершин
2) ребра (вектор объектов EdgeInputType)
3) линии метро (вектор объектов LineInputType)

Далее нужно просто вызывать функцию shortest_way, в которую передаются
начало пути, конец и время начала пути.