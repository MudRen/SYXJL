inherit ROOM;

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
殿中摆着数十个巨大的书架，架上放着许多的武功秘籍，这许多秘籍都
是教中长老在这多年来从各门派之中明抢暗夺过来的，日月教与各门派
的纷争都由此而起，以至多年来各门派高手都数度明夺暗盗，但黑木崖
壁垒森严，所以均无功而返，反而每次都送了几条性命在黑木崖上。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	        "down" : __DIR__"chengdedian",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/lu" : 1,
		__DIR__"npc/shizhe" : 3,
]));

        setup();
        replace_program(ROOM);
}
