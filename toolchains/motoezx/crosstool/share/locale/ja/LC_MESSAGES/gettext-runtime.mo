��    (      \  5   �      p  B   q  !  �  �  �  9   �  M        O     i  ,   �     �  %   �  ,   �  -   !	      O	  &   p	     �	     �	  �   �	  e   �
  :       @  �  Z  �  9     �     �  *   �  1     &   O     v  "   �  9   �  I   �  �   2     �     �     �     
          +     >  �  J  ;   �  �  *  �  $  7   �  ;   *     f     �  +   �     �  '   �  +     ,   >  "   k  !   �  '   �  '   �  b     F   c  $   �  �   �  �  �  *  �     �     �  /   �         =   5      s   %   �   >   �   S   �   m   A!  	   �!     �!     �!     �!     �!     "     "               !                             (                                 &   
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
 error while reading "%s" memory exhausted missing arguments standard input too many arguments write error Project-Id-Version: GNU gettext-runtime 0.13.1
Report-Msgid-Bugs-To: bug-gnu-gettext@gnu.org
POT-Creation-Date: 2005-01-14 13:07+0100
PO-Revision-Date: 2003-12-20 00:24+0900
Last-Translator: Masahito Yamaga <ma@yama-ga.com>
Language-Team: Japanese <translation-team-ja@lists.sourceforge.net>
MIME-Version: 1.0
Content-Type: text/plain; charset=EUC-JP
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=1; plural=0;
   -V, --version               �С������������Ϥ��ƽ�λ
   -d, --domain=TEXTDOMAIN   TEXTDOMAIN �����������줿��å���������Ф�
  -e                        ���������ץ������󥹤�Ÿ������
  -E                        (�ߴ����Τ����̵�뤵���)
  -h, --help                ���Υإ�פ�ɽ�����ƽ�λ
  -V, --version             �С����������ɽ�����ƽ�λ
  [TEXTDOMAIN]              ������å������� TEXTDOMAIN ������Ф�
  MSGID MSGID-PLURAL        MSGID (ñ����) / MSGID-PLURAL (ʣ����) ������
  COUNT                     �����ͤ���ܤˤ���ñ��/ʣ����������
   -d, --domain=TEXTDOMAIN   TEXTDOMAIN �����������줿��å���������Ф�
  -e                        ���������ץ������󥹤�Ÿ������
  -E                        (�ߴ����Τ����̵�뤵���)
  -h, --help                ���Υإ�פ�ɽ�����ƽ�λ
  -n                        �����β��Ԥ���Ϥ��ʤ�
  -V, --version             �С����������ɽ�����ƽ�λ
  [TEXTDOMAIN] MSGID        MSGID �˱�����������å������� TEXTDOMAIN ����
                            ���Ф�
   -h, --help                  ���Υإ�פ�ɽ�����ƽ�λ
   -v, --variables             ����������˸�����ѿ������
 %s: �����ʥ��ץ���� -- %c
 %s: ̵���ʥ��ץ���� -- %c
 %s: ���ץ���� `%c%s' �ˤϰ����Ϥ���ޤ���
 %s: ���ץ���� `%s' ��ۣ��Ǥ�
 %s: ���ץ���� `%s' �ˤϰ�����ɬ�פǤ�
 %s: ���ץ���� `--%s' �ˤϰ����Ϥ���ޤ���
 %s: ���ץ���� `-W %s' �ˤϰ����Ϥ���ޤ���
 %s: ���ץ���� `-W %s' ��ۣ��Ǥ�
 %s: ������ɬ�פʥ��ץ���� -- %c
 %s: ���ץ���� `%c%s' ��ǧ������ޤ���
 %s: ���ץ���� `--%s' ��ǧ������ޤ���
 Copyright (C) %s Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

[������]
����ϥե꡼�����եȥ������Ǥ�. ���ԡ��ξ��ˤĤ��Ƥϥ��������ɤߤ�������.
�Ծ����ڤ�������ŪŬ������ǡ���ˤ�餺, �����ʤ��ݾڤ⤢��ޤ���.

 ʸˡ��, ���������ˤ�äưۤʤäƤ��븶ʸ��å������μ����������ɽ��.
 ��ʸ�Υ�å������μ����������ɽ��.
 �⤷ TEXTDOMAIN �ѥ�᡼�������ꤵ��ʤ����, �Ķ��ѿ� TEXTDOMAIN ����
�ɥᥤ�󤬷�ޤ�ޤ�. �⤷ɸ��Υǥ��쥯�ȥ�˥�å���������������
���Ĥ���ʤ����, �Ķ��ѿ� TEXTDOMAINDIR �ǻ��ꤵ�줿��꤫��õ���ޤ�.
ɸ��θ����ǥ��쥯�ȥ�: %s
 �⤷ TEXTDOMAIN �ѥ�᡼�������ꤵ��ʤ����, �Ķ��ѿ� TEXTDOMAIN ����
�ɥᥤ�󤬷�ޤ�ޤ�. �⤷ɸ��Υǥ��쥯�ȥ�˥�å���������������
���Ĥ���ʤ����, �Ķ��ѿ� TEXTDOMAINDIR �ǻ��ꤵ�줿��꤫��õ���ޤ�.
-s ���ץ�����Ĥ��ƻȤ��ȥץ������� `echo' ���ޥ�ɤΤ褦��ư��ޤ�.
���������ΰ�����ñ�ˤ��Τޤ�ɸ����Ϥ˥��ԡ�����櫓�ǤϤ���ޤ���.
���򤵤줿����������˻��ꤵ�줿��å������������, ���Υ�å������������
�������줿��Τ�ɽ�����ޤ�.
ɸ��θ����ǥ��쥯�ȥ�: %s
 �̾�Υ��ڥ졼�����⡼�ɤǤ�, ɸ�����Ϥ�ɸ����Ϥ˥��ԡ�����, $VARIABLE
�ޤ��� ${VARIABLE} �����δĶ��ѿ��򻲾Ȥ�, ���줾����ͤ��ִ�����ޤ�.
��������������ꤵ����, ����������ǻ��Ȥ����, ���Τ褦�ʴĶ��ѿ�������
��������ޤ���, �����Ǥʤ�����ɸ�����Ϥ˸�������ƤδĶ��ѿ�����������ޤ�.
 ͭ�פʽ���:
 ���ڥ졼�����⡼��:
 �Х���ݡ��Ȥ� <bug-gnu-gettext@gnu.org> �ޤ�.
 �Ķ��ѿ����ͤ�����.
 ���¿���ξ�������뤿��ˤ� `%s --help' �����Ϥ��Ƥ�������.
 ̤�ΤΥ����ƥ२�顼 ����ˡ: %s [���ץ����] [���������]
 ����ˡ: %s [���ץ����] [TEXTDOMAIN] MSGID MSGID-PLURAL COUNT
 ����ˡ: %s [���ץ����] [[TEXTDOMAIN] MSGID]
�ޤ���: %s [���ץ����] -s [MSGID]...
 --variables ���Ȥ����, ɸ�����Ϥ�̵�뤵��, ���Ϥ� 1�Ԥ��ĥ����������
���Ȥ����Ķ��ѿ����鹽������ޤ�.
 ��� %s.
 "%s" �ɤ߹�����Υ��顼 �����Ȥ��̤����ޤ��� ����������ޤ��� ɸ������ ������¿�����ޤ� �񤭹��ߥ��顼 