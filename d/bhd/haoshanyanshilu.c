// Room: /u/setup/haoshanyanshilu.c



inherit ROOM;



void create()

{

        set("short", "��ɽ��ʯ·");

        set("long", @LONG

��ʯ·���ɻ�ɽ�Ҷѳɣ���ʱ�ã�����ʮ�ּ�Ӳ���������ѿ��Կ�����

�ƺ���֮�о��к��ⲻ�ϵ������ԭ������֮����һ�����ɽ���ߵ�����

�Ѹе�һ˿�������������������ʮ����·�͵����ɽ�����ˡ�

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"yashilu",

  "west" : __DIR__"huoshanjiaoxia",

]));

        set("no_clean_up", 0);



        setup();

        replace_program(ROOM);

}

