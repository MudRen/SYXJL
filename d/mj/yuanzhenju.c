// Room: yuanzhenju.c

inherit ROOM;

void create()
{
        set("short", "圆真居");
        set("long", @LONG
小屋一个，古道夕阳。一个光头和尚面目狰狞，满脸横肉，
双手紧握，青筋暴出，全身充满了杀气，好象随时随地准备要杀
个人来过把瘾，看起来，他！他！他！要杀你！快逃！！！
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"luzhou",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuan" : 1,
]));
        set("no_clean_up", 0);

        set("coor/x",-70);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",20);
	set("coor/z",0);
	set("coor/x",-70);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

