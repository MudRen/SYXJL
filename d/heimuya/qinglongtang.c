inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ʽ���̾ߣ���΢�������֮�£�ɢ���ű���ĺ��⣬����
Խ��Խ�����з�ë����������֮�����ֲ�״������ҵĽ��������и���
��һ�󾪲���
LONG
        );
        set("no_fight", "1");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aaa" : 1,
]));
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changlang2",
]));

        setup();
        replace_program(ROOM);
}
