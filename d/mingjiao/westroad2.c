//westroad2.c

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long",
	     "�Ѿ����˺ܾã�ɽ��Խ��Խ�ܣ�ҹ�������ˣ�ҹ�ɺ��ţ�\n"	
	 "����ë���Ȼ�����ǡ�����ѣ����������족������������Ҫ\n"
	 "��ɽ�ˡ�ͻȻ�����ַ������������ǻ�⡣\n" 
	);
	set("exits",([
		      "east" : __DIR__"westroad1",
	              "west" : __DIR__"gebitan1",
                      "south" : __DIR__"miaorenbuluo",
	]));
	set("coor/x",-60);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}