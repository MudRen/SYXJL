inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是通往峨嵋山的石阶，一条长长的石阶向西延伸，就向没有尽头
似的，虔诚的进香客来来往往。沿途很是热闹，不是有小贩沿路叫买，还
有峨眉的女尼和俗家弟子来来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shijie10",
  "northwest" : __DIR__"shijie12",
]));
	set("no_clean_up", 0);

	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
