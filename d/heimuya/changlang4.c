inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�������Ĺ������������Զ���ǽ��ÿ�������ɣ�ǽ�϶�����һ֧����
�εľ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"shifang",
  "south" : __DIR__"changlang6",
  "west" : __DIR__"changlang3",
  "north" : __DIR__"xiuxishi",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));

        setup();
        
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("gender") == "����" )
                return notify_fail("�����������Ů������Ϣ�ң�����Ҫ˯���᷿ȥ��\n");
        return ::valid_leave(me, dir);
}
