inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这里是一间普普通通的厢房，是峨嵋派四代俗家弟子苏梦清的休息
室。这里房间宽敞明亮，东西不多，很朴素，但一切都是有条有理，一
尘不染。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dlang5",
]));
	set("objects",([
           __DIR__"npc/smqing" : 1,
             ]));

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",110);
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
