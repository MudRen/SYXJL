inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
����һ�乩���½�ͽ���˵�ҩ��
LONG
        );
        set("no_fight", "1");
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"chengdedian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/yao" : 1,
]));

        setup();
        replace_program(ROOM);
}
