inherit ROOM;

void create()
{
        set("short", "һƷ��");
        set("long", @LONG
�߹����Ϸ壬ǰ����һ��Ҫ�����ͱڡ�һƷ�¡���������ɽ������
����������Ьһ����������ȥ���ǾͲ�����;��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"wulao",
]));
        set("objects", ([
                __DIR__"npc/wolf": 2,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
