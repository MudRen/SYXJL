//chufang.c
inherit ROOM;
void create()
{
  set("short","厨房");
  set("long",
  "这是间宽敞的厨房，厨师们在展示各自的烹饪绝活。\n"
  "整个房间弥漫着令人垂涎欲滴的菜香。墙上贴着一张醒目\n"
  "的启事(note)。\n"
  );
  set("exits",([
  "west" : __DIR__"huayuan",
  "east" : __DIR__"chaifang",
  ]));
  set("item_desc",([
  "note" : "本厨房招收小工：每砍一担柴，付１０两银子。\n",
  ]));

  set("objects",([
  __DIR__"npc/feifei" : 1,
  __DIR__"obj/doujiang" : random(5),
  __DIR__"obj/cake"  : random(3),
  ]));
  set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",10);
	set("coor/z",0);
	setup();
  }
int valid_leave(object me, string dir)
{
	if (( present("jiang", me)||present("cake", me))
	&&objectp(present("fei fei", environment(me))) )
	return notify_fail
	("肥肥一把拽住你的衣领，着急地叫到：饭菜不能带出去，这里蟑螂已经够
	多了。\n");
	return ::valid_leave(me, dir);
}





