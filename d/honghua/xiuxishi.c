// room: xiuxishi.c
// By Marz

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
        这是间整洁的厢房，房里别无他物，只有中间放着一张收拾
得舒舒服服的大床，看着就让人想睡觉。
LONG
        );

        set("exits", ([
      "north" : __DIR__"zoulang2",
                ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",90);
	set("coor/z",20);
	setup();
}


