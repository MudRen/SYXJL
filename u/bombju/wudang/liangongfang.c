// liangongfang.c ������
// by Xiang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	���������������������ҵط��ż������ţ���λ�䵱��������ϥ������
�������
LONG
	);
	set("exits", ([
		"west" : __DIR__"donglang2",
	]));
	set("objects", ([
       "/d/huashan/npc/muren2" : 3,
               "/d/village/obj/zhujian" : 1]));

	
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",180);
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",180);
	setup();
	replace_program(ROOM);
}
