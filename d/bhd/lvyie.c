// Room: /u/setup/lvyie.c



inherit ROOM;



void create()

{

        set("short", "��Ұ");

        set("long", @LONG

�����ǵ���Ķ�������Ŀ����һƬ��������ͷ�Ĵ���Ұ���ǻ��ɽ����

ǧ����Ļ�ɽ�Ҷѻ����ɣ���;���������������֮�⣬��������滨����

��֮�У�ż������һЩ�в�����Ŀ�Ĵ���С�ޣ�����Ҳ���޺����ˣ����ߵ�

�˴�����Ϊ��ɽ��ת��һƬ�����֣�����������һ��ʯɽ��

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "south" : __DIR__"lvyie1",

  "northwest" : __DIR__"shishan",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

