//gebitan1.c

inherit ROOM;

void create()
{
        set("short", "���̲");
	set("long", @LONG
���ڴ��������֣���ǰ��һ���޼ʵĸ��̲��û��·�꣬Ҳû
��һ�����ˣ����Եúܸߣ�Զɽ��ѩ����ӥ���裬��һ�ɲ�ͬ����
���������⡣��Զ������ֻ�׹�ɢ����ϣ��ƺ�����ţ��ʬ�ǡ
������ãã���֮�ϣ����ƺ���·�ˡ�
LONG
	);
 	set("exits",([
		      "east" : __DIR__"westroad2",
		      "west" : __DIR__"gebitan2",	
		      "north" : __DIR__"gebitan1",
                      "south" : __DIR__"gebitan1",  				
	]));
	set("objects",([
			"/d/mingjiao/obj/shigu":3,	
	]));
	set("coor/x",-70);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}