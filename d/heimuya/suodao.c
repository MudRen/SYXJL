inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������������������׵��¹ȣ��ұ�����������������������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"baichi",
]));
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/rygirl" : 1,
]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
