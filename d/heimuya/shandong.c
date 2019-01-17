inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这是令狐冲和盈盈居住的地方，洞里点着盏油灯，借着微弱灯光。
看到洞里摆设着几张石椅石床，角落竖着一块(石碑)，
布置得极之简朴，都是就地取材由洞内石块加工而成，但在
这绝壁中开凿出这样一个山洞确实不易。
LONG
        );
        set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/yingying" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong2",
  "north" : __DIR__"dashikuai",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
