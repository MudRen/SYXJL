inherit ROOM;

void create()
{
        set("short", "����ָ·");
        set("long", @LONG
������ָ·��ʵ�Ƕ������˶������µ�һ��ʯ����ԶԶ��������
�������¡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"xian",
		"westup" : __DIR__"lianhua",
]));
	set("objects", ([
                __DIR__"npc/hudie": 2,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
