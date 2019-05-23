# test_for_intershipVK
**Задание:** в двух массивах интов найти количество одинаковых элементов. В самих массивах числа не повторяются. Написать тесты к решению.
## Сборка и запуск
Можно запустить в Clion

Можно из консоли с помощью `make`:
* `make`        - сборка и запуск
* `make build`  - сборка
* `make run`    - запуск тестов
* `make clean`  - удалить build

При тестировании используются gTest.
Чтобы запустить программу на конкретном наборе тестов:
1. `make build`
2. `build/intershipVK --gtest_filter=testDiffRange*` - запуск всех тестов на разных числовых диапазонах

## Реализованные алгоритмы
### Метод двух указателей
Сортируем оба массива за _O(NlogN+MlogM)_ и дальше сравнивает их за _min(N, M)_. Самый первый алгоритм, приходящий в голову (после простого обхода за N*M). Очень сильно проигрывает остальным по скорости, но не требует дополнительной памяти.
### Бинарный поиск по минимальному массиву
Сортируем массив, меньшей длины за _O(NlogN)_, для каждого элемента из второго массива за _O(logN)_ ищет его вхождение в первом. Итоговая асимптотика: _O(NlogN_ _+_ _MlogN)_, где _N<M_. Так же как и метод двух указателей не требует дополнительно памяти, эффективен, когда _N_ на несколько порядков меньше _M_ (тогда асимптотика стремится к _O(M)_), но на больших массивах работает долго.
### Алгоритм, использующий HashTable (unordered_set)
По минимальному массиву строится _HashTable_, что позволяет за _O(1)_ находить в ней элементы из второго массива. _HashTable_ конструируется за O(N). Итого алгоритм работает за _O(N+M)_, но требует дополнительной памяти _O(N*k)_, _k_ - небольшая константа, чтобы не получить добавление элемента за _O(size())_.
### Алгоритм подсчета чисел в массиве
Находит разницу между минимальным и максимальным числом для каждого из массивов, далее по минимальной из этих разниц строит массив, отвечающий за то, есть ли данное число в массиве. Таким образом за _O(1)_ можно проверить, присуствует ли элемент второго массива в первом.

Алгоритм - некоторые рассуждения на тему, а что делать, если нам не хватает памяти (например, если бы числам в массиве разрешено было повторяться или нам на вход были бы даны не массивы, а файлы с числами). За _O(N_+_M)_ находится минимальная разность между максимальным и минимальным элементами обоих массивов, за _O(N)_ строится массив вхожения чисел и за _O(M)_ проверяются числа из другого массива. Итого: _O(2*(N+M))_ и с дополнительной затратой памяти _O(min(diff1,_ _diff2))_ - разности максимальных и миниальных значений в массивах.

Если в тестах даны массивы с не очень большой разницей значений, то этот алгоритм работает в разы быстрее алгоритма, использующего _HashTable_, т.к. не тратит время преподсчет _хеш-функции_ и исправление коллизий. Если диапазон значений одного из массивов примерно равен его длине, то этот алгоритм самый оптимальный. 
