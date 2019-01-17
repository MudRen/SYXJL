// Room: shanya.c

inherit ROOM;

void create()
{
        set("short", "山崖");
        set("long", @LONG
自洪水旗向东走，来到一个陡峭的山崖。它高耸入云，深不见底，山
谷中烟雾腾腾，紫气环绕，诡秘异常。你向山谷中扔了一块石头，久不闻
其声，可见其深！！！
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hongshuiqi",
]));
        set("no_clean_up", 0);

        set("coor/x",-100);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",80);
	set("coor/z",0);
	set("coor/x",-100);
	set("coor/y",80);
	set("coor/z",0);
	setup();
}
void init()
{
          add_action("do_jumpdown", "jumpdown");
}

int do_jumpdown(string arg)
{
        object me;
        me = this_player();

        message_vision("$N毫不考虑，一个纵身，跳了下去。\n", me);
                environment(me), ({me});
me->move("/d/mj/banshanyao.c");
message_vision("$N空中变换身形，一个空翻，轻飘飘地落在地上！\n", me);
                environment(me), me;
                return 1;
}



