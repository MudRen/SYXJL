inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
���ڲ��õ�ʮ�����ʣ��ֱ�ڷ��ż��Ŵ󴲣������½�ͽ����Ϣ֮�á�
LONG
        );
        set("no_fight", "1");
        set("sleep_room", "1");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"pailou",
]));

        setup();
        replace_program(ROOM);
}
