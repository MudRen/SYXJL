//room: /u/chen/shashou/yilou.c
inherit ROOM;

void init();

void create()
{
	set("short","第二楼");
	set("long", @LONG
	这里是杀手楼的第二楼，这里居住的是杀手楼的二流
人物。这里的充满着一种阴寒肃杀之气。一个汉子正背对屋外
夕阳昏黄的阳光映照之下，双目流露出一种令人不敢侵犯的威
严，神情似冷非冷，似暖非暖，像已饱经无限沧桑。
LONG
	   );
	set("exits",([
           "east" : __DIR__"qiandian",
	   ]));
	set("objects",([
                    __DIR__"npc/wuqiong":1,
//                     __DIR__"npc/shashou":6,
			]));
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
