# Сортировки

### Сортировка выбором:
![](https://bytebucket.org/Alex_Arno/sorts/raw/c14323539daf644e41348502d3227ccb80f59e50/Readme/Selection-Sort-Animation.gif?token=3147094517028825032a4957e9a35a25e25b2d60)

Шаги алгоритма:

1.находим номер минимального значения в текущем списке
2.производим обмен этого значения со значением первой неотсортированной позиции (обмен не нужен, если минимальный элемент уже находится на данной позиции)
3.теперь сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы

### Сортировка пузырьком:
![](https://bytebucket.org/Alex_Arno/sorts/raw/c14323539daf644e41348502d3227ccb80f59e50/Readme/Bubble-sort-example-300px.gif?token=703edf5888904533c21f8dddf43c0211bff11619)

Алгоритм состоит из повторяющихся проходов по сортируемому массиву.
За каждый проход элементы последовательно сравниваются попарно и, если порядок в паре неверный, выполняется обмен элементов.
Проходы по массиву повторяются N-1 раз или до тех пор, пока на очередном проходе не окажется,
что обмены больше не нужны, что означает — массив отсортирован.
При каждом проходе алгоритма по внутреннему циклу, очередной наибольший элемент массива ставится на своё место в конце массива рядом с предыдущим «наибольшим элементом»,
а наименьший элемент перемещается на одну позицию к началу массива («всплывает» до нужной позиции, как пузырёк в воде. Отсюда и название алгоритма).


### Сортировка вставками:

![](https://bytebucket.org/Alex_Arno/sorts/raw/c14323539daf644e41348502d3227ccb80f59e50/Readme/280px-Insertion-sort-example-300px.gif?token=253019f39e385516f7a39eb37c1f4b26a91b84cc)

На вход алгоритма подаётся последовательность n чисел: a_1,a_2,...,a_n .
Сортируемые числа также называют ключами. Входная последовательность на практике представляется в виде массива с n элементами.
В начальный момент отсортированная последовательность пуста.
На каждом шаге алгоритма выбирается один из элементов входных данных и помещается на нужную позицию в уже отсортированной последовательности до тех пор, пока набор входных данных не будет исчерпан.
В любой момент времени в отсортированной последовательности элементы удовлетворяют требованиям к выходным данным алгоритма.

### Сортировка Шелла:

![](https://bytebucket.org/Alex_Arno/sorts/raw/c14323539daf644e41348502d3227ccb80f59e50/Readme/Sorting_shellsort_anim.gif?token=8a50ab43bdf53286e6b8f925f3a39f399acd2aa8)

При сортировке Шелла сначала сравниваются и сортируются между собой значения, стоящие один от другого на некотором расстоянии  d.
После этого процедура повторяется для некоторых меньших значений d, а завершается сортировка Шелла упорядочиванием элементов при  d=1 (то есть обычной сортировкой вставками).
Эффективность сортировки Шелла в определённых случаях обеспечивается тем, что элементы «быстрее» встают на свои места
(в простых методах сортировки, например, пузырьковой, каждая перестановка двух элементов уменьшает количество
инверсий в списке максимум на 1, а при сортировке Шелла это число может быть больше).

### Пирамидальная сортировка:

![](https://bytebucket.org/Alex_Arno/sorts/raw/c14323539daf644e41348502d3227ccb80f59e50/Readme/HeapSort.gif?token=173dc978ba39994ad2b98ffdfc07e72b373d66e2)
Массив можно отсортировать, если на его основе строить и перестраивать сортирующее дерево, известное как двоичная куча или просто пирамида. 
Что есть сортирующее дерево? Это дерево, у которого любой родитель больше (или меньше, смотря в какую сторону оно сортирующее) чем его потомки. 
Как из обычного дерева сделать сортирующее дерево? Очень просто – нужно двигаться от потомков вверх к родителям и если потомок больше родителя, то менять местами.
Если такой обмен произошёл, опустившегося на один уровень родителя нужно сравнить с потомками ниже – может и там тоже будет повод для обмена.
Преобразовывая неотсортированную часть массива в сортирующее дерево, в итоге в корень «всплывёт» наибольший элемент.
Обмениваем максимум с последним ключом неотсортированного подмассива.
Структура перестанет быть сортирующим деревом, но в качестве моральной компенсации его неотсортированная часть станет меньше на один узел.
К этой неотсортированной части заново применим всю процедуру, то есть преобразуем её в сортирующее дерево с последующей перестановкой найденного максимума в конец.
И так действуем до тех пор, пока неотсортированная часть не скукожится до одного-единственного элемента.

### Быстрая сортировка:

1.Выбираем опорный элемент
2.Разбиваем массив на 3 части
	Создаём переменные l и r — индексы соответственно начала и конца рассматриваемого подмассива
	Увеличиваем l, пока l-й элемент меньше опорного
	Уменьшаем r, пока r-й элемент больше опорного
	Если l всё ещё меньше r, то меняем l-й и r-й элементы местами, инкрементируем l и декрементируем r
	Если l вдруг становится больше r, то прерываем цикл
Повторяем рекурсивно, пока не дойдём до массива из 1 элемента


### Поразрядная сортировка:

![](https://bytebucket.org/Alex_Arno/sorts/raw/c14323539daf644e41348502d3227ccb80f59e50/Readme/sort_counting.gif?token=1078ac9cba1693720b23ad9e03579da0e2023026)
Применение поразрядной сортировки имеет одно ограничение: перед началом сортировки необходимо знать

length – максимальное количество разрядов в сортируемых величинах (например, при сортировке слов необходимо знать максимальное количество букв в слове),
rang – количество возможных значений одного разряда (при сортировке слов – количество букв в алфавите).
Для сортировки чисел второе число заранее известно: количество цифр равно основанию системы счисления.
Поскольку в большинстве случаев сортируемые числа состоят из небольшого количества разрядов, поразрядная сортировка мало того, что применима, но и работает сравнительно быстро.

Допустим, у нас есть числа: 39, 47, 54, 59, 34, 41, 32 (length = 2, rang = 10)

1. Создаем пустые списки, количество которых равно числу rang.

2. Распределяем исходные числа по этим спискам в зависимости от величины младшего разряда (по возрастанию).
Для нашего примера получим:
41
32
54, 34
47
59, 39

(Вообще надо создать 10 (rang) списков, но некоторые из них оказались пустыми)

3. Собираем числа в той последовательности, в которой они находятся после распределения по спискам.
Получим: 41, 32, 54, 34, 47, 59, 39

4. Повторяем пункты 2 и 3 для всех более старших разрядов поочередно.
Для двузначных чисел мы должны сделать еще один проход. Распределение по спискам будет выглядеть так:
32, 34, 39
41, 47
54, 59
Объединив числа в список, получим отсортированный массив.
