inherit ROOM;

void create()
{
        set("short", "��ʳ��");
        set("long", @LONG
ֻ���Ծ���ʮ������ͽ�ֱ�Χ�ż��Ű������ڽ�ʳ��ǽ����һ��������
���ŵģ���Χ���ż������ӣ�Ҫ���Ƥ�����������¡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"changlang4",
]));
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chuzi" : 1,
]));

        setup();
        replace_program(ROOM);
}
