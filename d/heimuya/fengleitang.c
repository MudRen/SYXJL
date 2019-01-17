inherit ROOM;

void create()
{
        set("short", "风雷堂");
        set("long", @LONG
此处是日月教风雷堂主处理日常事务之地，室内并没有特别的摆设，只
在大堂摆放着一张太师椅。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"changlang5",
  "north" : __DIR__"changlang",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong" : 1,
]));

        setup();
        replace_program(ROOM);
}
