inherit ROOM;

void create()
{
        set("short", "��ȸ��");
        set("long", @LONG
����ֻ������յ�͵ƣ���������������������Զ������ְ�����ϡ
�м������ڴ�������������ò��α��Ʋ�����ˡ�
LONG
        );
        set("sleep_room", "1");
        set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"chengdedian",
		"west" : __DIR__"baihutang",
]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bao" : 1,
]));

        setup();
        replace_program(ROOM);
}
