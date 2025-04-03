# modern (не talking) calculator
При наличии ошибок в коде просьба написать в тг - @kto_prochital_tot_sexy

Инструкция по запуску программы (без тестов):

1) Необходимо расположить все файлы по папкам, как в указано в репозитории, иначе исполнение может быть некорректным
2) создаем файл mkdir build
3) переходим - cd build
4) прописать cmake ..
5) и ввести make (cmake соберет воедино все файлы и даст название исполняемому файлу - ./NumberSystemAdder)
6) для запуска нужно ввести ./NumberSystemAdder ../test/input.txt output.txt (файл input.txt может меняться в зависимости от выбора исходных данных)

Для тестов (просьба при скачивании папки test поправить опечатку в название unit_tests)

cd project/build
rm -rf *  # Очистка предыдущей сборки
cmake -DBUILD_TESTS=ON ..
make
ctest --output-on-failure

Пример вывода при успешном тестировании:

Test project /path/to/project/build
    Start 1: NumberSystemAdderTests
1/1 Test #1: NumberSystemAdderTests ...........   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Подробный вывод

./test/unit_tests/runTests




