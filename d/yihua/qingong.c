// ROOM : qinong.c
inherit ROOM;
void create()
{
  set("short","宫主寝宫");
  set("long",@LONG
这是宫主休息的地方，只见一个身材奇好, 貌美如花的女子站立在
花丛中,她就是武功奇高,身份神秘的移花宫宫主。以前因为被男人抛弃
所以她非常狠男人，如果你是男人最好不要接近她。
LONG
    );
  set("exits",([
      "north" : __DIR__"changlang",
      "south" : __DIR__"woshi",
     ]));
  set("objects",([
		__DIR__"npc/gongzhu" : 1,
     ]));
 setup();
 replace_program(ROOM);
}
