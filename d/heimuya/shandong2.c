inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ͷ���Ͽ����Ǹ����ڣ�̫�������������������������յ�ʮ����������
������Щ����ȥ�ĵط����Ը��˽�������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shandong",
  "up" : __DIR__"houhuayen",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
