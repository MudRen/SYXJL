inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
ƬƬ��ʯ�к����һ������ʯ�£�ͨ��ȴ����ɫ������ӳ���£�ʯ��
�����������ǳ����͡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"taohua",
]));
        set("objects", ([
                __DIR__"npc/bee": 2,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
