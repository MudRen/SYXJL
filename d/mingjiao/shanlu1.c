// Room: /d/mingjiao/shanlu1.c
// Date: XXL 97/04/9

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�������ǰ�ɽ���ˡ���Զ��ǰ����һ����ͤ����λ������
����ЪϢ��ɽ·��������Ӷ��ͣ�������ȥ�����͵��֣���Ŀ
�δ�Զɽ����װ���ƺ�����ۡ�
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"shanmen",
		"westup" : __DIR__"shanlu2",
	]));

        set("objects",([
        	 __DIR__"npc/tuoba":1,
			]));

	set("outdoors", "mingjiao");
	set("coor/x",-140);
	set("coor/y",-70);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}



