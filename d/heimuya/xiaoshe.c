inherit ROOM;

void create()
{
        set("short", "小舍");
        set("long", @LONG
一进门，便闻到一阵浓烈花香，只见房中挂着一幅仕女图，图中绘着三
个美女，东首一张梳妆台，台旁一张椅子上铺了绣花锦垫。整个房内花
团锦簇，脂粉浓香扑鼻，应该是间女子的闺房。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xiaohuayuan",
]));
        set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/dongfang" : 1,
]));

        setup();
        replace_program(ROOM);
}
