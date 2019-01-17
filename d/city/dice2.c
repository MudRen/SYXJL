inherit ROOM;

void create()
{
          set("short", "南厅");
        set("long", @LONG
	这里一张大桌旁挤满了人，都凝神盯着庄家手中的一对骰子，
有的面露喜色，有的低声咒骂。你使劲挤到桌旁，看到庄家身后墙上贴
着一张纸(paper)。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "out" : __DIR__"duchang",
]));
        set("item_desc", ([
                "paper": @TEXT


骰子的赌法：

bet　<种类>　<金量>

种类：　0，1，2，3到18
0：　		赌小	(3-10)	一赔一
1：  		赌大	(11-18)	一赔一
2：　		赌围骰	(三粒骰子同点)一赔三十六
3－18	赌单点  		一赔八

例子：
bet　0　50
赌五十两在小上

TEXT
        ]) );

        set("objects", ([
       __DIR__"npc/fair_thrower" : 1,
                        ]) );
	set("no_fight",1);
	set("no_yun",1);
	set("no_steal", 1);
        set("no_sleep_room", 1);
	set("no_beg", 1);

	setup();
}

void init()
{
	object me;
	me = this_player();
	if( me->query("gamble/amount")) {
		me->delete("gamble/amount");
//		me->decrease_skill("betting",1);
	}
}
