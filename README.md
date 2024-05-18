# Компьютерный клуб

## Описание
Решение задачи "Компьютерный клуб" на языке C++ (стандарт C++20 включительно). Программа предназначена для работы с текстовыми файлами, которые содержат входные данные для задачи.

## Общие требования
- CMake 3.15 или выше
- Компилятор gcc или clang для Linux, MinGW/Cygwin для Windows
- Google Test для запуска юнит-тестов

## Сборка и запуск

### Сборка проекта на Linux (gcc/clang)

1. Клонируйте репозиторий:
   ```sh
   git clone https://github.com/yourusername/computer-club-ts.git
   cd computer-club-ts
   ```
2. Создайте директорию для сборки и перейдите в нее
    ```sh
    mkdir build
    cd build
    ```
3. Сгенерируйте файлы сборки с помощью CMake:
    ```sh
    cmake ..
    ```
4. Соберите проект:
    ```sh
    cmake --build .

### Сборка проекта на Windows (MinGW/Cygwin)
1. Клонируйте репозиторий:
   ```sh
   git clone https://github.com/yourusername/computer-club-ts.git
   cd computer-club-ts
   ```
2. Создайте директорию для сборки и перейдите в нее
    ```sh
    mkdir build
    cd build
    ```
3. Сгенерируйте файлы сборки с помощью CMake:
    ```sh
    cmake -G "MinGW Makefiles" ..
    ```
4. Соберите проект:
    ```sh
    cmake --build .
    ```

### Запуск программы
Для запуска программы необходимо указать путь к входному файлу в качестве аргумента командной строки. Пример:
```sh
./main test_file.txt
```
или на Windows:
```sh
main.exe test_file.txt
```
## Тестирование
Для запуска тестов скопируйте файлы test(1,2,3).txt в директорию build/test выполните запуск:
```sh
test
```
или на Windows:
```sh
test.exe
```