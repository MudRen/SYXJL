// Room: /u/setup/lvyie1.c



inherit ROOM;



void create()

{

        set("short", "��Ұ");

        set("long", @LONG

�����ǵ���Ķ�������Ŀ����һƬ��������ͷ�Ĵ���Ұ���ǻ��ɽ����

ǧ����Ļ�ɽ�Ҷѻ����ɣ�ƽҰ��һȺ÷��¹���ڵ�ͷ�Բݣ���ΧһƬƽ��

�����޿ɲ�֮����Զ����ɽ��������ѩ��Щ��ȴ�Ǽ�Ŀ���̣����ɴ�أ���

����滨��������Ϊ��������

LONG

        );

        set("exits", ([ /* sizeof() == 2 */

  "south" : __DIR__"yanshi",

  "north" : __DIR__"lvyie",

]));

        set("no_clean_up", 0);

          set("objects", ([

		__DIR__"npc/lu":3,
          ]));

        setup();

        replace_program(ROOM);

}

