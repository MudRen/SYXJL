
// Room: /jingzhou/jiyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "妓院");
        set("long", @LONG
你一走进来，几名打扮得俗不可耐的女人分站两旁对你发出媚笑，不时
地还用手里的各色丝巾挑逗着你。厅内灯火通明，香气扑鼻。鸠母小春子满
脸都堆着粉抹得五颜六色，正上上下下、前前后后招呼着客人，忙个不停。
不时从楼上传来阵阵打情骂俏的声音。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"sanyijie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}