Реализация классического клеточного автомата "Жизнь" Конвея с дополнительными возможностями. Проект выполнен в рамках учебной практики.

## Особенности проекта

- Игровое поле с торической топологией (края соединены)
- Визуализация в реальном времени с возможностью масштабирования
- Библиотека готовых шаблонов (глайдеры, космические корабли и др.)
- Гибкая система правил (B3/S23 по умолчанию)
- Интерактивное управление: добавление клеток, пауза, очистка поля

## Установка (Linux)

Необходимые зависимости:
```bash
sudo apt update
sudo apt install \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    libdrm-dev \
    libgbm-dev
```

## Сборка и запуск

```bash
git clone git@github.com:justnurik/game_of_life.git
mkdir build && cd build
cmake ..
cmake --build .
./run
```

## Управление

- **ЛКМ** - добавить/удалить клетку (в режиме паузы)
- **ПКМ** - разместить выбранный шаблон
- **Пробел** - пауза/продолжить
- **Стрелки вверх/вниз** - регулировка скорости
- **Num1/Num2** - увеличение/уменьшение масштаба
- **Shift (левый)** - очистить поле
- **Backspace** - отменить выбор шаблона

## [Видео-демонстрации](<video/демонстрация_игры.webm>)
   - Добавление случайных клеток
   - Запуск симуляции
   - Использование шаблонов
   - Управление скоростью
   - Выбор различных конфигураций
   - Многократное размещение шаблонов
   - Взаимодействие между структурами
   - Особенности торического поля

## Последние обновления (30.03.24)

- Добавлено перемещение по полю в режиме увеличения
- Регулировка скорости симуляции
- Многократное размещение шаблонов
- Управление паузой
- Быстрая очистка поля

## Разработчики

- Молданазаров Нурдаулет: [GitLab](https://gitlab.akhcheck.ru/jNurik)
- Шалбай Алишер: [GitLab](https://gitlab.akhcheck.ru/jNurik)

---

*Проект создан в образовательных целях. Вдохновлено работами Джона Конвея.*