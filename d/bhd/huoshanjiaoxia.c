// Room: /u/setup/huoshanjiaoxia.c



inherit ROOM;



void create()

{

        set("short", "��ɽ����");

        set("long", @LONG

��Խ��Խ�ȣ�����������ɽ���¡���ʱ�ѿ��Կ������ӻ�ɽ��ŭ���

��������������Ȼ��ֻ������Ҳ�Ƕ��ܲ�ס���������ǿڸ���������

��������������һ����ľ���ݣ�ֻ���ͺͺ���ƽ�������ʯ��

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"haoshanyanshilu",

  "west" : __DIR__"huoshan",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

