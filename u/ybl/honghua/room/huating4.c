// by mayue


inherit ROOM;

void create()
{
        set("short", "聚义堂");
	set("long", @LONG
这里是红花会的聚义堂，是红花会接待客人的地方，屋子两旁整齐的摆放着
两排红木大椅，一些江湖义士正在高声谈论着什么。
LONG
	);
//      set("outdoors", "honghua");

	set("exits", ([
                "south" : __DIR__"huating5",
                "east" : __DIR__"huayuan4",
                "north" : __DIR__"huating6",
	]));
        set("objects", ([
                "/u/ybl/honghua/npc/xutianhong" : 1,
	]));
    

	setup();
	replace_program(ROOM);
}

