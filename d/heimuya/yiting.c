inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������������̵ľ��������ǽ������µĵط���ʱʱ���Լ�������
ͬ���и�λ����.�����ڴ˹��̴�ƣ����и����������Ծ�̾����
LONG
        );
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"changlang6",
]));

        setup();
        replace_program(ROOM);
}
