//westroad1.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long",
             "����һ��ֱͨ������ɽ·������Զ����ȺɽΡ�룬����Ʈ�죬\n"
         "����ǰ��Զ����Ҫ������ɽ֮���ˡ�������������֮���������䵱ɽ��\n"
	);
	set("exits",([
		      "west" : __DIR__"westroad2",
		      "east" : "/d/wudang/shanmen",
	   ]));
	set("coor/x",-50);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
        