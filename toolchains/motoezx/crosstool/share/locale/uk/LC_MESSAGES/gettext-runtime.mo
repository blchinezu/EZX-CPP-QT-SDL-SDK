��    (      \  5   �      p  B   q  !  �  �  �  9   �  M        O     i  ,   �     �  %   �  ,   �  -   !	      O	  &   p	     �	     �	  �   �	  e   �
  :       @  �  Z  �  9     �     �  *   �  1     &   O     v  "   �  9   �  I   �  �   2     �     �     �     
          +     >  �  J  f   �  �  6  R    a   `  m   �  4   0  4   e  b   �  5   �  \   3  b   �  c   �  8   W  Z   �  7   �  7   #  �  [  �   �   U   �!  �  �!  R  �#  y  :'  '   �)     �)  O   �)  A   F*  ^   �*  0   �*  ?   +  h   X+  �   �+  �   I,  "   B-  )   e-      �-  #   �-     �-  ,   �-     !.               !                             (                                 &   
                            $                             %         '             "   	          #      -V, --version               output version information and exit
   -d, --domain=TEXTDOMAIN   retrieve translated message from TEXTDOMAIN
  -e                        enable expansion of some escape sequences
  -E                        (ignored for compatibility)
  -h, --help                display this help and exit
  -V, --version             display version information and exit
  [TEXTDOMAIN]              retrieve translated message from TEXTDOMAIN
  MSGID MSGID-PLURAL        translate MSGID (singular) / MSGID-PLURAL (plural)
  COUNT                     choose singular/plural form based on this value
   -d, --domain=TEXTDOMAIN   retrieve translated messages from TEXTDOMAIN
  -e                        enable expansion of some escape sequences
  -E                        (ignored for compatibility)
  -h, --help                display this help and exit
  -n                        suppress trailing newline
  -V, --version             display version information and exit
  [TEXTDOMAIN] MSGID        retrieve translated message corresponding
                            to MSGID from TEXTDOMAIN
   -h, --help                  display this help and exit
   -v, --variables             output the variables occurring in SHELL-FORMAT
 %s: illegal option -- %c
 %s: invalid option -- %c
 %s: option `%c%s' doesn't allow an argument
 %s: option `%s' is ambiguous
 %s: option `%s' requires an argument
 %s: option `--%s' doesn't allow an argument
 %s: option `-W %s' doesn't allow an argument
 %s: option `-W %s' is ambiguous
 %s: option requires an argument -- %c
 %s: unrecognized option `%c%s'
 %s: unrecognized option `--%s'
 Copyright (C) %s Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 Display native language translation of a textual message whose grammatical
form depends on a number.
 Display native language translation of a textual message.
 If the TEXTDOMAIN parameter is not given, the domain is determined from the
environment variable TEXTDOMAIN.  If the message catalog is not found in the
regular directory, another location can be specified with the environment
variable TEXTDOMAINDIR.
Standard search directory: %s
 If the TEXTDOMAIN parameter is not given, the domain is determined from the
environment variable TEXTDOMAIN.  If the message catalog is not found in the
regular directory, another location can be specified with the environment
variable TEXTDOMAINDIR.
When used with the -s option the program behaves like the `echo' command.
But it does not simply copy its arguments to stdout.  Instead those messages
found in the selected catalog are translated.
Standard search directory: %s
 In normal operation mode, standard input is copied to standard output,
with references to environment variables of the form $VARIABLE or ${VARIABLE}
being replaced with the corresponding values.  If a SHELL-FORMAT is given,
only those environment variables that are referenced in SHELL-FORMAT are
substituted; otherwise all environment variables references occurring in
standard input are substituted.
 Informative output:
 Operation mode:
 Report bugs to <bug-gnu-gettext@gnu.org>.
 Substitutes the values of environment variables.
 Try `%s --help' for more information.
 Unknown system error Usage: %s [OPTION] [SHELL-FORMAT]
 Usage: %s [OPTION] [TEXTDOMAIN] MSGID MSGID-PLURAL COUNT
 Usage: %s [OPTION] [[TEXTDOMAIN] MSGID]
or:    %s [OPTION] -s [MSGID]...
 When --variables is used, standard input is ignored, and the output consists
of the environment variables that are referenced in SHELL-FORMAT, one per line.
 Written by %s.
 error while reading "%s" memory exhausted missing arguments standard input too many arguments write error Project-Id-Version: gettext-runtime 0.14.1
Report-Msgid-Bugs-To: bug-gnu-gettext@gnu.org
POT-Creation-Date: 2005-01-14 13:07+0100
PO-Revision-Date: 2004-08-01 13:59+0200
Last-Translator: Maxim V. Dziumanenko <mvd@mylinux.com.ua>
Language-Team: Ukrainian <translation-team-uk@lists.sourceforge.net>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
   -V, --version               вивести інформацію про версію та вийти
   -d, --domain=ДОМЕН_ТЕКСТУ використовувати перекладені повідомлення з
                            вказаного домену ДОМЕН_ТЕКСТУ
  -e                        дозволити використання деяких escape-послідовностей
  -E                        (ігнорується, використовується для сумісності)
  -h, --help                показати цю довідку та вийти
  -V, --version             відобразити інформацію про версію та вийти
  [ДОМЕН_ТЕКСТУ]            знайти переклад у вказаному домені ДОМЕН_ТЕКСТУ
  MSGID MSGID-PLURAL        перекласти MSGID (однина) / MSGID-PLURAL (множина)
  ЧИСЛО                     вибрати однину/множину на основі цього значення
   -d, --domain=ДОМЕН_ТЕКСТУ використовувати перекладені повідомлення з
                            домену ДОМЕН_ТЕКСТУ
  -e                        дозволити використання деяких escape-послідовностей
  -E                        (ігнорується, використовується для сумісності)
  -h, --help                показати цю довідку та вийти
  -n                        не виводити наприкінці символ переводу рядка
  -V, --version             відобразити інформацію про версію та вийти
  [ДОМЕН_ТЕКСТУ] MSGID      знайти переклад повідомлення MSGID у ДОМЕН_ТЕКСТУ
   -h, --help                  вивести довідку та завершити роботу
   -v, --variables             виводити змінні, що зустрічаються у SHELL-FORMAT
 %s: неправильний параметр -- %c
 %s: неправильний параметр -- %c
 %s: параметр `%c%s' має використовуватись без аргументів
 %s: неоднозначний параметр `%s'
 %s: параметр `%s' має використовуватись з аргументом
 %s: параметр `--%s' має використовуватись без аргументів
 %s: параметр `-W %s' має використовуватись без аргументів
 %s: неоднозначний параметр `-W %s'
 %s: параметр %c має використовуватись з аргументом
 %s: нерозпізнаний параметр `%c%s'
 %s: нерозпізнаний параметр `--%s'
 Авторські права (C) %s Free Software Foundation, Inc.
Це - вільне програмне забезпечення; умови копіювання викладені у вихідному
коді. Не надається НІЯКОЇ гарантії; навіть гарантії КОМЕРЦІЙНОЇ ПРИДАТНОСТІ
або ПРИДАТНОСТІ ДО ПЕВНОЇ МЕТИ.
 Відображає переклад текстового повідомлення, граматична форма якого залежить
від числа.
 Відображає переклад текстового повідомлення.
 Якщо параметр ДОМЕН_ТЕКСТУ не вказаний, використовується домен, визначений у
змінній оточення TEXTDOMAIN. Якщо файл з перекладеними повідомленнями
відсутній у стандартному каталозі, можна вказати інший каталог за допомогою
змінної оточення TEXTDOMAINDIR.
Стандартний каталог пошуку: %s
 Якщо не вказаний параметр ДОМЕН_ТЕКСТУ, використовується домен, встановлений
у змінній оточення TEXTDOMAIN. Якщо файл з перекладеними повідомленнями
відсутній у типовому каталозі, можна вказати інший каталог за допомогою
змінної оточення TEXTDOMAINDIR.
При використанні з ключем -s, поведінка програми схожа на поведінку програми
`echo'. Але замість простого копіювання аргументів у стандартний вивід,
виводяться їх переклади з вказаного домену.
Стандартний каталог пошуку: %s
 У звичайному режимі роботи, стандартний ввід копіюється на стандартний вивід,
де посилання на змінні оточення у формі $VARIABLE або ${VARIABLE}, 
замінюються відповідними значеннями. Якщо вказано SHELL-FORMAT,
будуть замінюватись лише змінні, що вказані у SHELL-FORMAT; у іншому
випадку будуть замінюватись усі змінні оточення, що зустрічаються у
стандартному вводі.
 Інформативний вивід:
 Режим роботи:
 Про помилки повідомляйте на <bug-gnu-gettext@gnu.org>.
 Замінює значення змінних оточення.
 Спробуйте `%s --help' для отримання докладнішого опису.
 Невідома системна помилка Використання: %s [ПАРАМЕТР] [SHELL-FORMAT]
 Використання: %s [ПАРАМЕТР] [ДОМЕН_ТЕКСТУ] MSGID MSGID-PLURAL ЧИСЛО
 Використання: %s [ПАРАМЕТР] [[ДОМЕН_ТЕКСТУ] MSGID]
або:          %s [ПАРАМЕТР] -s [MSGID]...
 При використанні --variables, стандартний ввід ігнорується, а вивід
складається зі змінних оточення, які вказані у SHELL-FORMAT, по одній на рядок.
 Автор програми - %s.
 помилка при читанні "%s" пам'ять вичерпана відсутні аргументи стандартний ввід надто багато аргументів помилка запису 