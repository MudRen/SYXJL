inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
        �����������Ů������Ϣ�ң��Ǽ�������᷿�����ߺ��㡣�Ƕ����
�õط��������м�����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"changlang4",
]));

        setup();
}
