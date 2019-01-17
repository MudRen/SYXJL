// Room: /d/songshan/luyanpubu.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "芦岩瀑布");
	set("long", @LONG
忽听水声如雷，峭壁上两条玉龙直挂下来，双瀑并泄，屈曲
回旋，飞跃奔逸，水花映日，淡淡冕生。
    瀑布一侧有一小小芦岩寺，瀑布斜过就是胜观峰。瀑布之侧
有路可上。
LONG );
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"        : __DIR__"tieliang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
}
 
int valid_leave(object me, string dir)
{
    if ((int)me->query_skill("dodge") <= 200 && dir=="up")    
    {
    	if (me->query("qi")>=30){
      me->improve_skill("dodge",(int)me->query_skill("dodge",1)/2);
      me->add("qi",-15);
      me->add("jing",-10);     
 
}
}

    return ::valid_leave(me, dir);
}

