
// Room: /jingzhou/dukou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "渡口");
        set("long", @LONG
面前是波涛翻滚的长江。浊浪滔滔，气势磅礴，确实令人感叹不已。两
岸渡船来来往往，江边一长溜摆满了鱼摊，板上摆满了活蹦乱跳的江鱼。过
去不远，是当地有名的万寿宝塔。不少过江客都在这里等待渡船摆渡。
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"wanshoubaota",
         ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}