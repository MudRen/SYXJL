//cedong.c

inherit ROOM;

void create()
{
	set("short", "�ප");
	set("long",
	     "������һ��СС�Ĳප������������ױ̨���ϱ߰ڷ���һЩŮ�˵���Ʒ��\n"
	);
	set("exits", ([
		"east" : __DIR__"dongnei",
	]));
	set("objects",([
		__DIR__"npc/jinhua" : 1,
	]));

	set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",-10);
	set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",-10);
	set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",-10);
	set("coor/x",-90);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}
