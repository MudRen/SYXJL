// /clone/board/towiz_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("明教弟子留言板", ({ "board" }) );

        set("location", "/d/mj/guangming-ding");

        set("board_id", "mingjiao_b");

        set("long", "这是一个供明教弟子使用的留言板。\n" );

        setup();

        set("capacity", 60);

        replace_program(BULLETIN_BOARD);

}





