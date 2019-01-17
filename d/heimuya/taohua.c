inherit ROOM;

void create()
{
        set("short", "桃花川");
        set("long", @LONG
走到桃花川，前面一派秀色奇石，一琢琢淡红的圆石自峰顶铺将下去，
宛若片片桃花，连成桃林一绝。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
	"northup" : __DIR__"meimao",
	"westup" : __DIR__"zisi",
	"west" : __DIR__"ziyun",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
