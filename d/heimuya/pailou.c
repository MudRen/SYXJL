inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
������һ����¥�����������½̽�ͽ����Ϣ�ң�������һ�������̣�
������һ��������ʯ��·��Ҳ��֪ͨ��ʲô�ط���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"xiangfang",
  "south" : __DIR__"datiepu",
  "west" : __DIR__"shiwu",
  "north":__DIR__"shibanlu",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/shizhe" : 2,
]));

        setup();
        replace_program(ROOM);
	"/clone/board/riyue_b"->foo();

}
