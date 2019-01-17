inherit ROOM;


void create()
{
        set("short", "玉女池");
        set("long", @LONG
玉女池是一个并不很大的池子，据说终年不会干涸，池水清澈，掩映
着池畔的玉女峰，苍山碧水，景色极是宜人。再往上就是大名鼎鼎的峨眉
派的所在了，听说峨眉派封山极严，一般游客不许上山，所以还是小心点
好。
LONG
        );

        set("exits", ([
		"southdown" : __DIR__"shifang",
		"eastup" : __DIR__"shanmen",
               ]));
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",50);
	set("coor/x",-40);
	set("coor/y",-30);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}