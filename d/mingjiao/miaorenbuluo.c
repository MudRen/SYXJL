//miaorenbuluo.c

inherit ROOM;

void create()
{
        set("short", "���˲���");
        set("long",
	     "����ǰͻȻһ����ԭ�����߽���һ�����˲��䡣������Χ���ڻ�\n"
	 "�ѱߣ���ɫ�ϣ���������ĳ�ּ�����ʽ��������ʿ������ľ�ۣ���\n"
	 "�������дʡ�ͻȻ�����Ǻ��������㡣\n"
	);
 	set("exits",([
		      "north" : __DIR__"westroad2",
	]));
	set("objects",([
			"/d/mingjiao/npc/miaozuwushi":4,	
	]));
	set("coor/x",-60);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}