//room: /u/chen/shashou/yilou.c
inherit ROOM;

void init();

void create()
{
	set("short","第一楼");
	set("long", @LONG
	这里是杀手楼的第一楼，走进这里，突感一阵肃穆之意，
大殿中十分空旷，殿顶高悬八盏金灯，两旁是精壮佩剑武士剑气
森严逼人。正中设一宝座，宝座后立有一扇玉屏，屏上写着三个
大字“杀  手  楼”。宝座上端坐一人，身着一袭锦衣，正是杀
手楼的楼主“刀剑笑”刀锋冷。
LONG
	   );
	set("exits",([
	    "south" : __DIR__"qiandian",
	   ]));
	set("objects",([
                      "/d/shashou/npc/daofengl" :1,
                      "/d/shashou/npc/shangfushi" :1,
                   "/d/shashou/npc/weishi":2,
			]));
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
