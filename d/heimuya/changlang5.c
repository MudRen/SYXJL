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
  "east" : __DIR__"houdian",
  "south" : __DIR__"houhuayen",
  "north" : __DIR__"dadian",
  "west" : __DIR__"fengleitang",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));

        setup();
        replace_program(ROOM);
}
