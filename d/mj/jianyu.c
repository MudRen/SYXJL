// Room: jianyu.c

inherit ROOM;

void create()
{
        set("short", "监狱");
        set("long", @LONG
这是一间密不透风的石室，四周没有任何门窗，只有透过牢门的小
孔的一丝微弱的光线，东边角落的地上铺着一些稻草，几个遍体伤痕的
弟子蜷缩在那里，不时发出一阵阵痛苦的低吟。

LONG
        );
set("objects",([
__DIR__"npc/yu-zu":1,
]));
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jyentrance",
]));
        set("no_clean_up", 0);

        set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",130);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

