inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long",@LONG
���Ǹ���ͨ��ʯ̨���ഫ������������ٴ�̨������������ȥ���Ǳ�
���صء���Ĳ���á������д��������µ�����֮�������������׾Ͳ���
���У�����ǧ��Ҫ��ʲô���⡣
LONG
        );
        set("exits", ([
                "west" : __DIR__"munitang",
		"northdown" : __DIR__"doushuai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
        ]));
        set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	set("coor/x",-80);
	set("coor/y",-130);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
