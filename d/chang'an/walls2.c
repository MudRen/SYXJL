// Room: /d/chang'an/walls2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是城墙内侧的石阶，你可以从这里登上城墙，听说上面的城墙厚
到可以并齐走数辆马车；因为城墙看起来很高，所以显得也很陡，旁边还
有可供车马上下的斜坡。
LONG );
        set("outdoors", "chang'an");
	set("no_clean_up", 0);

	set("exits", ([
		"eastup"   : __DIR__"walls4",
		"westdown" : __DIR__"southgate1",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if (dir == "eastup" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->receive_damage("qi",10);
                  if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<21))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	}
	return 1;
}


