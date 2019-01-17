// Room: /d/quanzhou/yucun.c
inherit ROOM;
void create()
{
    set("short", "小渔村");
    set("long", @LONG
一艘破木船搁浅在离你几十步远的海滩上，海水无情地拍打着海岸，
几只海鸥盘旋在你周围，你极目远眺，海面上却看不到一艘渔船。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
	  "/d/npc/salt_seller" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"haigang",
]));
    set("outdoors", "quanzhou");
    setup();
    replace_program(ROOM);
}
