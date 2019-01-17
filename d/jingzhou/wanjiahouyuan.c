
// Room: /jingzhou/wanjiahouyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "万家后院");
        set("long", @LONG
你走进了一间非常简单的房间，这家宅院的少奶奶戚芳正坐在那里逗
着一个四，五岁的小女孩，却显得不是那么专著，偶尔将目光向窗外的远
方，似有所思。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"wanjiadayuan",
                "north"  : __DIR__"wanjiacaiyuan",                
        ]));
        set("objects", ([
                __DIR__"npc/qifang" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}