inherit ROOM;

void create()
{
        set("short", "��Ѫ��");
        set("long", @LONG
���Ǳ�Ѫ�£������ɹۺ�ľ������ˮ�����٣�����������ľ���ܶ档
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xianren",
  "west" : __DIR__"yupingpu",
  "east" : __DIR__"wulao",
]));
        set("objects", ([
                __DIR__"npc/bee": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
