inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ����ķ��䣬�յ�����û���κΰ��裬�������ż�ʵ����ʯ�塣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"changlang3",
  "north" : __DIR__"liangongfang2",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-ren" : 2,
]));

        setup();
        replace_program(ROOM);
}
