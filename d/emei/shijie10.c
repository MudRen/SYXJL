inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是通往峨嵋山的石阶，一条长长的石阶向西延伸，就向没有尽头似
的，虔诚的进香客来来往往。沿途很是热闹，不是有小贩沿路叫买，还有峨
眉的女尼和俗家弟子来来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "northeast" : "/d/wudang/wdroad8",
  "west" : __DIR__"shijie11",
]));
	set("no_clean_up", 0);

	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",0);
	set("coor/x",-40);
	set("coor/y",-100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
