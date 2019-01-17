//Room: /d/dali/shanlu2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
一条山路，四面皆是茂密的树林和延绵不绝的大山，道路两旁间
或可见一些夷族的村镇，西面一片高山高耸入云，山颠白雪皑皑终年
不化。正路向西上山，一条岔路向南北蜿蜒着。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"shanlu3",
	    "south"     : __DIR__"shanlu4",
	    "northup"   : __DIR__"nianhuasi",
	    "westup"    : __DIR__"biluoxueshan",
	]));
	set("no_clean_up", 0);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",-90);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}

