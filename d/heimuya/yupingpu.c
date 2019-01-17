inherit ROOM;

void create()
{
        set("short", "玉屏瀑");
        set("long", @LONG
来到玉屏瀑，这里的景观真是无以比拟，一面宽宽大大晶莹如玉
的瀑布自天上泻下来，传说这是天上仙娥们在清洗天宫的玉屏风所流
下地界的天池中的圣水。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
		"east" : __DIR__"lianhua",
		"westdown" : __DIR__"baizhang",
		"north" : __DIR__"guanpu",
]));
set("objects", ([
                __DIR__"npc/wolf": 1,]) );

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
