inherit ROOM;

void create()
{
        set("short", "千秋殿");
        set("long", @LONG
殿内摆放着许多大大小小的铁箱,每个箱子都用铁锁紧紧地锁
着，箱子之间又用铁链相互连着，看来箱子里面装着的物件非常重要。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"changlang3",
  "south" : __DIR__"dadian",
  "west" : __DIR__"changlang2",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qu" : 1,
  __DIR__"npc/lao" : 1,
]));

        setup();
        replace_program(ROOM);
}
