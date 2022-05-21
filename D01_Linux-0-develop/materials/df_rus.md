## Использование утилиты **df**
df - это команда для получения подробного отчета об использовании дискового пространства системы.

Вот несколько примеров работы с командой df:
- Простой вызов команды df: \
  ![df1](misc/images/df1.png)
- Теперь давайте попросим утилиту выводить данные в более читаемом формате с помощью ключа -h: \
  ![df2](misc/images/df2.png)
- Если задать опцию -a, вы можете получить информацию обо всех файловых системах известных ядру, которые были смонтированы: \
  ![df3](misc/images/df3.png)
- -H -- ключ вывода всех размеров в гигабайтах
- -P -- ключ использования формата вывода POSIX
- -x -- ключ вывода информации обо всех размерах, кроме указанных файловых систем