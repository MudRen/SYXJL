// Room: /d/tianlongsi/fzlou2.c

inherit ROOM;




void create()
{
	set("short", "������");
	set("long", @LONG
�����ҳ����࣬����һ����һ���ţ�һ����������ǽ��д
�Ŵ���һ���������֡�һλ��ü��Ŀ�Ļ�����ɮ������������
�ϴ�����
LONG
	);

	set("exits", ([
		"down" : __DIR__"fzlou1",
	]));

	set("objects",([
//		CLASS_D("shaolin") + "/xuan-ci" : 1,	
                 __DIR__"npc/yideng" : 1,
         ]));
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",-90);
	set("coor/y",-110);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}



