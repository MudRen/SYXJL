// zijincheng.c�Ͻ��
// by arnzh 97.1.24 

inherit ROOM;

void create()
{
	set("short", "�Ͻ��");
	set("long", @LONG
	�������ǰ��һ�����ۣ�����д�š��Ͻ�ǡ��������ɫ�Ĵ��֣���ש
���ߣ�Ժǽ����һ�˰��С�ġ������ٷ��ĸ����֡�Ժ�з����������䣬��
����ͬ��ɫ�ĵ�ʿȷ���Ͻ����������о�������������������������һ������С����
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"liantai",
 		"north" : __DIR__"xiaolu1",  
	]));
//	set("objects", ([
//		CLASS_D("wudang") + "/zhike" : 1]));
	set("coor/x",-70);
	set("coor/y",180);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",180);
	set("coor/z",230);
	set("coor/x",-70);
	set("coor/y",180);
	set("coor/z",230);
	setup();
	replace_program(ROOM);
}

