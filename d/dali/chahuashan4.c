//Room: /d/dali/chahuashan4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ");
	set("long",@LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ����
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���
�ǵı��ţ��ϱ߲�Զ�ǳ�ǽ��
LONG);
	set("objects", ([
	   __DIR__"obj/shanchahua": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"     : __DIR__"chahuashan2",
	]));
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",20);
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",20);
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",20);
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
